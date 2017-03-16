#include <cstdio>

typedef long long LL;

LL min(LL x, LL y) { return x < y ? x : y; }

LL t, r;

bool f(LL n) {
  if (n*r*2ll + n + n*(n-1ll)*2ll <= t) return 1;
  return 0;
}

LL solve() {
  LL lo = 1, hi = min(707106790ll, (t + r)/r) , mi;
  while (lo + 1 < hi) {
    mi = lo + (hi-lo) / 2;
    if (f(mi)) lo = mi; else hi = mi;
  }
  return lo;
}

int main() {
  int T; int cas = 0;
  scanf("%d", &T);
  while (T--) {
    scanf("%lld%lld", &r, &t);
    printf("Case #%d: ", ++cas);
    printf("%lld\n", solve());
  }
  return 0;
}
