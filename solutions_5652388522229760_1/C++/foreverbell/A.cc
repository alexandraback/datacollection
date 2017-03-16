#include <bits/stdc++.h>

using namespace std;

int tests, n;

int solve(int n) {
  if (n == 0) return -1;
  bool v[10];
  memset(v, 0, sizeof(v));
  for (int k = 1; ; ++k) {
    int t = n * k;
    while (t) {
      v[t % 10] = true;
      t /= 10;
    }
    bool flag = true;
    for (int i = 0; i < 10; ++i) if (!v[i]) flag = false;
    if (flag) return k * n;
  }
  return -1;
}

int main() {
  freopen("A-large.in", "r", stdin);
  scanf("%d", &tests);
  for (int tt = 1; tt <= tests; ++tt) {
    scanf("%d", &n);
    printf("Case #%d: ", tt);
    int r = solve(n);
    if (r == -1) puts("INSOMNIA");
    else printf("%d\n", solve(n));
  }
  return 0;
}
