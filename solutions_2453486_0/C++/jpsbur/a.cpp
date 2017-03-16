#include <cstdio>
#include <cassert>

bool check (char a[4][5], char x, int i, int j, int di, int dj) {
  for (int k = 0; k < 4; ++k, i += di, j += dj) {
    if (a[i][j] != x && a[i][j] != 'T') {
      return false;
    }
  }
  return true;
}

int main() {
  int nt;
  assert (scanf ("%d", &nt) == 1);
  for (int tt = 1; tt <= nt; ++tt) {
    char a[4][5];
    for (int i = 0; i < 4; ++i) {
      assert (scanf ("%s", a[i]) == 1);
    }
    char na[] = "XO";
    int res = 2;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 4; ++j) {
        if (check (a, na[i], j, 0, 0, 1)) {
          res = i;
        }
        if (check (a, na[i], 0, j, 1, 0)) {
          res = i;
        }
      }
      if (check (a, na[i], 0, 0, 1, 1)) {
        res = i;
      }
      if (check (a, na[i], 3, 0, -1, 1)) {
        res = i;
      }
    }
    if (res == 2) {
      for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
          if (a[i][j] == '.') {
            res = 3;
          }
        }
      }
    }
    char resN[4][99] = {
      "X won",
      "O won",
      "Draw",
      "Game has not completed"
    };
    printf ("Case #%d: %s\n", tt, resN[res]);
  }
  return 0;
}
