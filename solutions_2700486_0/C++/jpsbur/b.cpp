#include <cstdio>
#include <cassert>

const int maxN = 200;
const int sh = maxN * 2;

int nt;
int n, x, y;
int f[sh * 2][sh];

void fall (int &x, int &y, int z) {
  x = 0;
  y = n * 2;
  while (y > 0) {
    if (y >= 2 && !f[x + sh][y - 2]) {
      y -= 2;
    } else if (f[x + sh - 1][y - 1] && f[x + sh + 1][y - 1]) {
      break;
    } else if (f[x + sh - 1][y - 1]) {
      y -= 1;
      x += 1;
    } else if (f[x + sh + 1][y - 1]) {
      y -= 1;
      x -= 1;
    } else {
      y -= 1;
      assert (z != -1);
      if (z) {
        x -= 1;
      } else {
        x += 1;
      }
      z = -1;
    }
  }
//  fprintf (stderr, "fall to (%d %d)\n", x, y);
}

double bt (int i) {
  if (i == n) {
    if (x < -sh || x > sh || y < 0 || y > sh) {
      return 0.0;
    }
    return f[x + sh][y] ? 1.0 : 0.0;
  } else {
    double res = 0.0;
    for (int z = 0; z < 2; ++z) {
      int xc, yc;
      fall (xc, yc, z);
      f[xc + sh][yc] = 1;
      res += bt (i + 1);
      f[xc + sh][yc] = 0;
    }
    return res * 0.5;
  }
}

int main () {
  assert (scanf ("%d", &nt) == 1);
  for (int tt = 1; tt <= nt; ++tt) {
    fprintf (stderr, "tt=%d\n", tt);
    assert (scanf ("%d%d%d", &n, &x, &y) == 3);
    if (x < 0) {
      x = -x;
    }
    double ans = bt (0);
    printf ("Case #%d: %.9lf\n", tt, ans);
  }
  return 0;
}
