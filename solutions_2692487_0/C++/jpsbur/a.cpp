#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

const int maxN = 101;
const int maxM = 1000001;
const int inf = (int)1e9;

int nt;
int n, a, s[maxN], m;
int f[maxN][maxM];

void relax (int &a, int b) {
  a = min (a, b);
}

int main () {
  assert (scanf ("%d", &nt) == 1);
  for (int tt = 1; tt <= nt; ++tt) {
    assert (scanf ("%d%d", &a, &n) == 2);
    for (int i = 0; i < n; ++i) {
      assert (scanf ("%d", &s[i]) == 1);
    }
    sort (s, s + n);
    m = max (a, s[n - 1] + 1);
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        f[i][j] = inf;
      }
    }
    f[0][a] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= m; ++j) {
        if (f[i][j] == inf) {
          continue;
        }
        relax (f[i + 1][j], f[i][j] + 1);
        if (s[i] < j) {
          relax (f[i + 1][min (j + s[i], m)], f[i][j]);
        } else {
          relax (f[i][min (j + j - 1, m)], f[i][j] + 1);
        }
      }
    }
    int ans = inf;
    for (int j = 0; j <= m; ++j) {
      ans = min (ans, f[n][j]);
    }
    printf ("Case #%d: %d\n", tt, ans);
  }
  return 0;
}
