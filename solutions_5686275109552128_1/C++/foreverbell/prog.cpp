
#include <bits/stdc++.h>

using namespace std;

const int maxN = 1111, maxint = 0x7f7f7f7f;
int n, p[maxN];

int main() {
  freopen("B-large.in", "r", stdin);
  freopen("B-large.out", "w", stdout);
  int tests;
  scanf("%d", &tests);
  for (int tt = 1; tt <= tests; ++tt) {
    scanf("%d", &n);
    int lim = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", p + i);
      lim = max(lim, p[i]);
    }
    int result = maxint;
    for (int t = 1; t <= lim; ++t) {
      int cnt = 0;
      for (int i = 1; i <= n; ++i) {
        if (p[i] <= t) continue;
        int part = p[i] / t;
        if (p[i] % t == 0) --part;
        cnt += part;
      }
      result = min(result, cnt + t);
    }
    printf("Case #%d: %d\n", tt, result);
  }
  return 0;
}
