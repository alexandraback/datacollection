#include <algo/macros.hpp>

char B[4][5];

bool has_won(char p) {
  for (int i = 0; i < 4; i++) {
    int hcnt = 0;
    int vcnt = 0;
    for (int j = 0; j < 4; j++) {
      if (B[i][j] == p || B[i][j] == 'T')
        hcnt++;
      if (B[j][i] == p || B[j][i] == 'T')
        vcnt++;
    }
    if (hcnt == 4 || vcnt == 4)
      return true;
  }

  int icnt = 0;
  int dcnt = 0;
  for (int i = 0; i < 4; i++) {
    if (B[i][i] == p || B[i][i] == 'T')
      icnt++;
    if (B[i][3 - i] == p || B[i][3 - i] == 'T')
      dcnt++;
  }
  if (icnt == 4 || dcnt == 4)
    return true;
}

bool is_completed() {
  int dots = 0;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      if (B[i][j] == '.')
        dots++;
  return dots == 0;
}

int main() {
  FREOPEN("large.in");
  FREOPEN_OUT("large.out");
  int T;
  scanf("%d", &T);


  for (int t = 1; t <= T; t++) {
    for (int i = 0; i < 4; i++)
      scanf("%s\n", B[i]);

    printf("Case #%d: ", t);
    if (has_won('X'))
      printf("X won\n");
    else if (has_won('O'))
      printf("O won\n");
    else if (is_completed())
      printf("Draw\n");
    else
      printf("Game has not completed\n");

  }
}
