#include <cassert>
#include <cstdio>

int main() {
  int tn;
  assert(scanf("%d", &tn) == 1);
  for (int t = 1; t <= tn; t++) {
    int n, m;
    assert(scanf("%d%d", &n, &m) == 2);
    int a[n][m], ok[n][m];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        assert(scanf("%d", &a[i][j]) == 1), ok[i][j] = 0;
    for (int i = 0; i < n; i++) {
      int mx = 0;
      for (int j = 0; j < m; j++)
        if (a[i][j] > mx)
          mx = a[i][j];
      for (int j = 0; j < m; j++)
        if (a[i][j] == mx)
          ok[i][j] = 1;
    }
    for (int i = 0; i < m; i++) {
      int mx = 0;
      for (int j = 0; j < n; j++)
        if (a[j][i] > mx)
          mx = a[j][i];
      for (int j = 0; j < n; j++)
        if (a[j][i] == mx)
          ok[j][i] = 1;
    }
    bool ans = true;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (!ok[i][j])
          ans = false;
    printf("Case #%d: %s\n", t, ans ? "YES" : "NO");
  }
  return 0;
}

