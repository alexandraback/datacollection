#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
using namespace std;

int f(int x) {
  if (x == 0) return -1;
  int sum = 0;
  int c;
  for (c = x; ; c += x) {
    int m = c;
    while (m > 0) {
      sum |= 1 << (m % 10);
      m /= 10;
    }
    if (sum == (1 << 10) - 1) break;
  }
  return c;
}

int main() {
  freopen("A-large.in", "r", stdin);
  freopen("A-large.out", "w", stdout);

  int TextN, n;
  scanf("%d", &TextN);
  for (int TT = 1; TT <= TextN; TT++) {
    scanf("%d", &n);
    int ans = f(n);
    if (ans < 0) {
      printf("Case #%d: INSOMNIA\n", TT);
    } else {
      printf("Case #%d: %d\n", TT, ans);
    }
  }
  return 0;
}