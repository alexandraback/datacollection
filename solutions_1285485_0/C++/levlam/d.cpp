#include <cassert>
#include <cstdio>
#include <map>
#include <set>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

char a[55][55];

int main(void) {
  int tn, nt;
  scanf("%d", &nt);
  for (tn=1; tn<=nt; tn++) {
    printf ("Case #%d: ", tn);

    int h, w, d;
    scanf("%d %d %d\n", &h, &w, &d);
    for (int i = 0; i < h; i++) {
      gets(a[i]);
    }

    int x = -1, y = -1;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (a[i][j] == 'X') {
          x = i;
          y = j;
        }
      }
    }
    w -= 2;
    h -= 2;
    x -= 1;
    y -= 1;

    w *= 2;
    h *= 2;
    x = 2 * x + 1;
    y = 2 * y + 1;

    assert (0 < x && x < h);
    assert (0 < y && y < w);

    set <pair <int, int> > ans;

    for (int i = -55; i <= 55; i++) {
      for (int j = -55; j <= 55; j++) {
        int nx = (i % 2 == 0) ? x + i * h : h - x + i * h;
        int ny = (j % 2 == 0) ? y + j * w : w - y + j * w;
        nx -= x;
        ny -= y;
        if (nx == 0 && ny == 0) {
          continue;
        }
        if (nx * nx + ny * ny > 4 * d * d) {
          continue;
        }
        int D = __gcd(abs(nx), abs(ny));
        assert (D);

        int tx = x, ty = y, good = 1;
        while (tx != nx + x || ty != ny + y) {
          tx += nx / D;
          ty += ny / D;
          if (tx % h == 0 && ty % w == 0)
            good = 0;
        }
        if (!good) {
          continue;
        }


        nx /= D;
        ny /= D;

        ans.insert (make_pair(nx, ny));
      }
    }

    for (int i = -55; i <= 55; i++) {
      for (int j = -55; j <= 55; j++) {
        int nx = i * h;
        int ny = j * w;
        nx -= x;
        ny -= y;
        if (nx * nx + ny * ny > d * d) {
          continue;
        }
        int D = __gcd(abs(nx), abs(ny));
        assert (D);

        nx /= D;
        ny /= D;

        ans.insert (make_pair(nx, ny));
      }
    }

    printf ("%d\n", ans.size());

  }

  return 0;
}
