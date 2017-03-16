#include <cassert>
#include <cstdio>

int main() {
  int tt;
  assert(scanf("%d", &tt) == 1);
  for (int t = 1; t <= tt; t++) {
    char a[4][4];
    bool is_dot = false, is_x = false, is_o = false;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++) {
        assert(scanf(" %c", &a[i][j]) == 1);
        if (a[i][j] == '.')
          is_dot = true;
      }
    for (int i = 0; i < 4 && !is_x && !is_o; i++) {
      is_x = true;
      for (int j = 0; j < 4 && is_x; j++)
        if (a[i][j] != 'T' && a[i][j] != 'X')
          is_x = false;
      if (is_x)
        break;

      is_x = true;
      for (int j = 0; j < 4 && is_x; j++)
        if (a[j][i] != 'T' && a[j][i] != 'X')
          is_x = false;
      if (is_x)
        break;

      is_x = true;
      for (int j = 0; j < 4 && is_x; j++)
        if (a[j][j] != 'T' && a[j][j] != 'X')
          is_x = false;
      if (is_x)
        break;

      is_x = true;
      for (int j = 0; j < 4 && is_x; j++)
        if (a[j][3 - j] != 'T' && a[j][3 - j] != 'X')
          is_x = false;
      if (is_x)
        break;

      is_o = true;
      for (int j = 0; j < 4 && is_o; j++)
        if (a[i][j] != 'T' && a[i][j] != 'O')
          is_o = false;
      if (is_o)
        break;

      is_o = true;
      for (int j = 0; j < 4 && is_o; j++)
        if (a[j][i] != 'T' && a[j][i] != 'O')
          is_o = false;
      if (is_o)
        break;
        
      is_o = true;
      for (int j = 0; j < 4 && is_o; j++)
        if (a[j][3-j] != 'T' && a[j][3-j] != 'O')
          is_o = false;
      if (is_o)
        break;
        
      is_o = true;
      for (int j = 0; j < 4 && is_o; j++)
        if (a[j][j] != 'T' && a[j][j] != 'O')
          is_o = false;
      if (is_o)
        break;
    }
    if (is_x)
      printf("Case #%d: X won\n", t);
    else if (is_o)
      printf("Case #%d: O won\n", t);
    else if (is_dot)
      printf("Case #%d: Game has not completed\n", t);
    else
      printf("Case #%d: Draw\n", t);
  }
  return 0;
}

