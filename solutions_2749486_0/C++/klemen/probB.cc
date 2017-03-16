#include <stdio.h>

int X, Y;

void repeat(char a, char b, int steps) {
  for (int i = 0; i < steps; i++) {
    printf("%c%c", a, b);
  }
}

int main() {
  int T = 0;
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%d %d", &X, &Y);
    printf("Case #%d: ", t + 1);
    bool first = true;
    if (X > 0) {
      if (first) {
        printf("E");
        first = false;
        X--;
      }
      repeat('W', 'E', X);
    }
    else {
      if (first) {
        printf("W");
        first = false;
        X++;
      }
      repeat('E', 'W', -X);
    }
    if (Y > 0) {
      if (first) {
        printf("N");
        first = false;
        Y--;
      }
      repeat('S', 'N', Y);
    }
    else {
      if (first) {
        printf("S");
        first = false;
        Y++;
      }
      repeat('N', 'S', -Y);
    }
    printf("\n");
  }
}
