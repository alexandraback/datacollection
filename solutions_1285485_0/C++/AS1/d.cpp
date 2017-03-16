#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

int main (void) {
  int tn;
  scanf ("%d", &tn);
  for (int tt = 1; tt <= tn; tt++) {
    int h, w, d;
    scanf ("%d%d%d", &h, &w, &d);
    vector <string> board(h);
    for (int i = 0; i < h; i++) {
      cin >> board[i];
    }
    int rx = -1, ry = -1;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (board[i][j] == 'X') {
          ry = i;
          rx = j;
        }
      }
    }
    rx--;
    ry--;
    w -= 2;
    h -= 2;
    w *= 2;
    h *= 2;
    rx = rx * 2 + 1;
    ry = ry * 2 + 1;
    d *= 2;
    
    int res = 0;
    set <pair <int, int> > s;
    for (int i = -d - 2; i <= d + 2; i++) {
      for (int j = -d - 2; j <= d + 2; j++) {
        int x = w * j + ((j & 1) ? w - rx : rx), 
            y = h * i + ((i & 1) ? h - ry : ry), 
            dx = x - rx, dy = y - ry,
            nd = dx * dx + dy * dy;
        if (nd == 0) {
          continue;
        }
        int t = __gcd (dx, dy);
        if (t < 0) {
          t = -t;
        }
        dx /= t;
        dy /= t;
        if (nd <= d * d && !s.count (make_pair (dx, dy))) {
          res++;
          s.insert (make_pair (dx, dy));
          //fprintf (stderr, "(%d %d)->(%d %d)\n", x, y, rx, ry);
        }
      }
    }
    printf ("Case #%d: %d\n", tt, res);
  }
  return 0;
}