#include <cstdio>

char tab[5][5];

bool is(int x, int y, char v) {
  return tab[x][y] == v || tab[x][y] == 'T';
}

bool isV(int x, int y, int dx, int dy, char v) {
  for(int i = 0; i < 4; ++i)
    if(! is(x + i * dx, y + i * dy, v))
      return false;

  return true;
}

bool hasWon(char v) {
  for(int i = 0; i < 4; ++i) {
    if(isV(i, 0, 0, 1, v))
      return true;
    if(isV(0, i, 1, 0, v))
      return true;
  }

  return isV(0, 0, 1, 1, v) || isV(0, 3, 1, -1, v);
}

int main() {
  int T;
  scanf("%d", &T);
  for(int tc = 1; tc <= T; ++tc) {
    scanf("%s%s%s%s", tab[0], tab[1], tab[2], tab[3]);
    if(hasWon('X'))
      printf("Case #%d: X won\n", tc);
    else if(hasWon('O'))
      printf("Case #%d: O won\n", tc);
    else {
      bool hasdot = false;
      for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
          hasdot |= tab[i][j] == '.';

      if(hasdot)
        printf("Case #%d: Game has not completed\n", tc);
      else
        printf("Case #%d: Draw\n", tc);
    }
  }
}
