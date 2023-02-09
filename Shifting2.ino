const int GREEN_BUTTON_PIN = 14;   // button input pin
const int GREEN_LED_PIN = 4;
const int RED_BUTTON_PIN = 13;   // button input pin
const int RED_LED_PIN = 2;

byte GREEN_STATE_LED = LOW;
byte lastGreenState = LOW;
byte RED_STATE_LED = LOW;
byte lastRedState = LOW;

long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(GREEN_BUTTON_PIN, INPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_BUTTON_PIN, INPUT);
  pinMode(RED_LED_PIN, OUTPUT);
}

void loop() {
  byte GREEN_STATE_BUTTON = digitalRead(GREEN_BUTTON_PIN);
  byte RED_STATE_BUTTON = digitalRead(RED_BUTTON_PIN);

  
    if (GREEN_STATE_BUTTON != lastGreenState) {
      lastGreenState = GREEN_STATE_BUTTON;
      if ( (millis() - lastDebounceTime) > debounceDelay) {
        if (GREEN_STATE_BUTTON == HIGH){
          digitalWrite(GREEN_LED_PIN, HIGH);
          delay(250);
          digitalWrite(GREEN_LED_PIN, LOW);
        }
        else {
          digitalWrite(GREEN_LED_PIN, LOW);
        }
        lastDebounceTime = millis();
      }else{
        digitalWrite(GREEN_LED_PIN, LOW);
      }
    }



  if (RED_STATE_BUTTON != lastRedState) {
    lastRedState = RED_STATE_BUTTON;
    if ( (millis() - lastDebounceTime) > debounceDelay) {
      if (RED_STATE_BUTTON == HIGH){
        digitalWrite(RED_LED_PIN, HIGH);
        delay(250);
        digitalWrite(RED_LED_PIN, LOW);
      }
      else {
        digitalWrite(RED_LED_PIN, LOW);
      }
      lastDebounceTime = millis();
    }else{
      digitalWrite(RED_LED_PIN, LOW);
    }
  }
}