#include <stdio.h>
#include <string.h>
#include <math.h>

typedef unsigned long long ULL;

const ULL MAX = 1e14;
int sum[10000000];

int p(ULL n) {
  char s[199];
  sprintf(s, "%llu", n);
  int i, l = strlen(s);
  for (i = 0; s[i]; i++)
    if (s[i] != s[l - i - 1]) return 0;
  return 1;
}

int ps(ULL n) {
  ULL sqr = sqrt(n);
  if (sqr * sqr != n) return 0;
  /*if (p(n) && p(sqr)) {
    printf("%llu\n", n);
  }*/
  return p(n) && p(sqr);
}

int solve() {
  ULL i;
  for (i = 1; i * i <= MAX; i++)
    sum[i] = sum[i - 1] + ps(i * i);
  return 0;
}

int main() {
  solve();
  int C = 1, T;
  scanf("%d", &T);
  while (T--) {
    ULL a, b;
    scanf("%llu%llu", &a, &b);
    int l = sqrt(a) + !(sqrt(a) * sqrt(a) == a), r = sqrt(b);
    //printf("%d %d %d %d\n", l, r, sum[l], sum[r]);
    int ans = (l == r && ps(l * l)) ? 1 : sum[r] - sum[l] + ps(l * l);
    printf("Case #%d: %d\n", C++, ans);
  }
  return 0;
}
