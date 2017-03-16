#include <cassert>
#include <cstdio>
#include <cstring>

#include <algorithm>

int main() {
  using std::max;
  int tn;
  assert(scanf("%d", &tn) == 1);
  for (int tt = 1; tt <= tn; tt++) {
    int n, s, p;
    assert(scanf("%d%d%d", &n, &s, &p) == 3);
    int a[n];
    for (int i = 0; i < n; i++)
      assert(scanf("%d", &a[i]));
    int d[n + 1][n + 1];
    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        // fprintf(stderr, "d[i=%d][j=%d] = %d\n", i, j, d[i][j]);
        if (a[i] >= 3 * max(p, 2) - 4)
          d[i + 1][j + 1] = max(d[i + 1][j + 1], d[i][j] + 1);
        if (a[i] >= 3 * max(p, 1) - 2)
          d[i + 1][j] = max(d[i + 1][j], d[i][j] + 1);
        if (a[i] >= 3 * p)
          d[i + 1][j] = max(d[i + 1][j], d[i][j] + 1);
        if (a[i] >= 2)
          d[i + 1][j + 1] = max(d[i + 1][j + 1], d[i][j]);
        d[i + 1][j] = max(d[i + 1][j], d[i][j]);
      }
    printf("Case #%d: %d\n", tt, d[n][s]);
  }
  return 0;
}

