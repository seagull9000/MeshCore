#include "buzzer.h"

void genericBuzzer::begin() {
    Serial.print("DBG: Setting up buzzer on pin ");
    Serial.println(PIN_BUZZER);
    #ifdef PIN_BUZZER_EN
      pinMode(PIN_BUZZER_EN, OUTPUT);
      digitalWrite(PIN_BUZZER_EN, HIGH);
    #endif

    pinMode(PIN_BUZZER, OUTPUT);
    startup();
}

void genericBuzzer::play(const char *melody) {
    if (isPlaying())   // interrupt existing
    {
        rtttl::stop();
    }
    rtttl::begin(PIN_BUZZER,melody);
    Serial.println("DBG: Playing melody");
  
}

bool genericBuzzer::isPlaying() {
    return rtttl::isPlaying();
}

void genericBuzzer::loop() {
    if (!rtttl::done()) rtttl::play();
}

void genericBuzzer::startup() {
    play(startup_song);
}

void genericBuzzer::shutdown() {
    play(shutdown_song);
}
