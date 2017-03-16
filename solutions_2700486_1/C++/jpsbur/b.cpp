#include <cstdio>
#include <cassert>

const int maxN = 4000001;
const int maxH = 4005;
const int sh = maxN * 2;

int nt;
int n, x, y;
int cnt[maxH];
double p[maxH * 2][maxH];

int main () {
  cnt[1] = 1;
  for (int i = 2; i <= maxH; ++i) {
    cnt[i] = cnt[i - 1] + 4 * (i - 1) + 1;
    if (i < 10) {
//      fprintf (stderr, "i=%d cnt=%d\n", i, cnt[i]);
    }
  }
  assert (scanf ("%d", &nt) == 1);
  for (int tt = 1; tt <= nt; ++tt) {
    fprintf (stderr, "tt=%d\n", tt);
    assert (scanf ("%d%d%d", &n, &x, &y) == 3);
    if (x < 0) {
      x = -x;
    }
    int h = 0;
    while (cnt[h] <= n) {
      ++h;
    }
//    fprintf (stderr, "n=%d h=%d cnt=%d\n", n, h, cnt[h]);
    double ans = 0.0;
    if (x + y < 2 * (h - 1)) {
      ans = 1.0;
    } else if (x + y > 2 * (h - 1)) {
      ans = 0.0;
    } else {
      int z = n - cnt[h - 1];
//      fprintf (stderr, "   z=%d\n", z);
      for (int i = 0; i <= z; ++i) {
        for (int j = 0; j <= h * 2; ++j) {
          p[i][j] = 0.0;
        }
      }
      p[0][0] = 1.0;
      for (int i = 0; i < z; ++i) {
        for (int j = 0; j <= h + 1; ++j) {
//          fprintf (stderr, "f[%d][%d]=%.5lf\n", i, j, p[i][j]);
          if (j == 2 * (h - 1)) {
//            fprintf (stderr, "case 0 -> %d %d\n", i + 1, j);
            p[i + 1][j] += p[i][j] * 1.0;
          } else if (i - j == 2 * (h - 1)) {
//            fprintf (stderr, "case 1 -> %d %d\n", i + 1, j + 1);
            p[i + 1][j + 1] += p[i][j] * 1.0;
          } else {
//            fprintf (stderr, "case 2 -> %d %d..%d\n", i + 1, j, j + 1);
            p[i + 1][j] += p[i][j] * 0.5;
            p[i + 1][j + 1] += p[i][j] * 0.5;
          }
        }
      }
      for (int i = y + 1; i <= h + 1; ++i) {
        ans += p[z][i];
      }
    }
    printf ("Case #%d: %.9lf\n", tt, ans);
  }
  return 0;
}
