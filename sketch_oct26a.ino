#define RAIN_SENSOR 27
#define LED_PIN     26
#define BUZZER_PIN  25

// Most rain sensor modules output LOW when wet.
// Change to HIGH if your module works in reverse.
#define WET_STATE LOW

void setup() {
  Serial.begin(115200);

  pinMode(RAIN_SENSOR, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.println("Water Leak Detection System Ready");
}

void loop() {
  int sensorState = digitalRead(RAIN_SENSOR);

  if (sensorState == WET_STATE) {
    // Water detected
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);

    Serial.println("ALERT: WATER LEAK DETECTED!");
  } else {
    // No water detected
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    Serial.println("Status: No Water Detected");
  }

  delay(500);
}