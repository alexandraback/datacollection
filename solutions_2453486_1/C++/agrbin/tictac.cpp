#include <cstdio>

char map[8][8];

// -1 - not completed
// 0 - draw
// 1 - O won
// 2 - X won

int check_line(int is_row, int r) {
  char koji = 0;
  for (int j = 0; j < 4; ++j) {
    char tst = is_row ? map[r][j] : map[j][r];
    if (tst == '.') return 0;
    if (tst == 'T') continue;
    if (!koji) koji = tst;
    if (tst != koji) return 0;
  }
  throw (koji == 'X' ? 2 : 1);
}

int check_diag(int is_main) {
  char koji = 0;
  for (int j = 0; j < 4; ++j) {
    char tst = is_main ? map[j][j] : map[3 - j][j];
    if (tst == '.') return 0;
    if (tst == 'T') continue;
    if (!koji) koji = tst;
    if (tst != koji) return 0;
  }
  throw (koji == 'X' ? 2 : 1);
}

int solve() {
  try {
    for (int is_row = 0; is_row < 2; ++is_row)
      for (int i = 0; i < 4; ++i)
        check_line(is_row, i);
    // ovdje nema pobjede u liniji.
    for (int diag = 0; diag < 2; ++diag)
      check_diag(diag);
  } catch (int &e) {
    return e;
  }
  // ovdje nema pobjede ni na dijagonali. ako nema tocke ovo je draw.
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      if (map[i][j] == '.')
        return -1;
  return 0;
}

int main() {
  int k;
  scanf("%d", &k);
  for (int j = 0; j < k; ++j) {
    for (int i = 0; i < 4; ++i)
      scanf("%s", map[i]);
    switch (solve()) {
      case -1:
        printf("Case #%d: Game has not completed\n", j + 1); break;
      case 0:
        printf("Case #%d: Draw\n", j + 1); break;
      case 1:
        printf("Case #%d: O won\n", j + 1); break;
      case 2:
        printf("Case #%d: X won\n", j + 1); break;
    }
  }

  return 0;
}
