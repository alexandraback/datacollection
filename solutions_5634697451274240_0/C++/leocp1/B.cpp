#include<bitset>
#include<stdio.h>

constexpr size_t maxInSize = 100;

int flip(std::bitset<maxInSize> in) {
  int nFlips = 0;
  for (int i = maxInSize -1; i >= 0; i--) {
    if (in[i]) {
      nFlips++;
      for (int j = 0; j <= i; j++) {
        in.flip(j);
      }
    }
  }
  return nFlips;
}

int main(void) {
  int T = 0;
  scanf("%d\n", &T);
  int x = 0;
  for (int i = 1; i <= T; i++) {
    std::bitset<maxInSize> n = {};
    int j = 0;
    while ((x = getchar()) != EOF) {
      if (x == '\n') {
        break;
      }
      if (x == '-') {
        n[j] = true;
      }
      if (x == '+') {
        n[j] = false;
      }
      j++;
    }
    printf("Case #%d: %d\n", i, flip(n));
  }
  return 0;
}
