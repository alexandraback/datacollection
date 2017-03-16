#include<bitset>
#include<stdio.h>

int sleepTime(int N) {
  std::bitset<10> hasDigit = {0};
  for (int i = 1;;i++) {
    int x = i * N;
    while (x > 0) {
      hasDigit[x % 10] = true;
      x = x / 10;
    }
    if (hasDigit.all()) {
      return i * N;
    }
  }
  return -1;
}

int main(void) {
  int T = 0;
  int N = 0;
  scanf("%d\n", &T);
  for (int i = 1; i <= T; i++) {
    scanf("%d\n", &N);
    if (N == 0) {
      printf("Case #%d: INSOMNIA\n", i);
    } else {
      printf("Case #%d: %d\n", i, sleepTime(N));
    }
  }
  return 0;
}
