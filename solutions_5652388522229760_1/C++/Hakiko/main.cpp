#include <bits/stdc++.h>

unsigned int combine(unsigned int a, unsigned int b) {
  for (int i = 0; i < 10; ++i) {
    a |= (b & (1 << i));
  }
  return a;
}

unsigned int digits(int n) {
  unsigned int mask = 0;
  while (n > 0) {
    mask = combine(mask, 1 << (n % 10));
    n /= 10;
  }
  return mask;
}

const unsigned int ALL = (1 << 10) - 1;

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int n;
    scanf("%d", &n);
    if (n == 0) {
      printf("Case #%d: INSOMNIA\n", i + 1);
    } else {
      unsigned int mask = 0;
      int t = 0;
      int k = n;
      while (mask != ALL) {
        mask = combine(mask, digits(k));
        k += n;
        t += 1;
      }
      printf("Case #%d: %d\n", i + 1, t * n);
    }
  }
}
