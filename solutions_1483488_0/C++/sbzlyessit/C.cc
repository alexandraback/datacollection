#include <stdio.h>
#include <string.h>

int p[10];

bool mark[10000000];

int GetCount(int n) {
  int ret = 0;
  while (n) {
    n /= 10;
    ++ret;
  }
  return ret;
}

int Transfer(int n, int len) {
  return n / 10 + n % 10 * p[len - 1];
}

int main() {
  int T;
  scanf("%d", &T);
  p[0] = 1;
  for (int i = 1; i < 10; ++i) p[i] = p[i - 1] * 10;
  for (int tt = 1; tt <= T; ++tt) {
    int A, B;
    long long ret = 0;
    scanf("%d%d", &A, &B);
    memset(mark, 0, sizeof(mark));
    for (int i = A; i <= B; ++i) {
      if (mark[i]) continue;
      int n = i, tot = 1;
      int len = GetCount(n);
      for (int j = Transfer(n, len); j != n; j = Transfer(j, len)) {
        mark[j] = true;
        if (j >= A && j <= B && j >= p[len - 1]) ++tot;
      }
      ret += tot * (tot - 1) / 2;
    }
    printf("Case #%d: %d\n", tt, ret);
  }
  return 0;
}
