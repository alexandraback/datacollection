#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

char grid[4][4];

bool won(char c) {
  bool wda = true;
  bool wdb = true;
  for (int i = 0; i < 4; i++) {
    wda &= (grid[i][i] == c || grid[i][i] == 'T');
    wdb &= (grid[i][3 - i] == c || grid[i][3 - i] == 'T');

    bool wr = true;
    bool wc = true;
    for (int j = 0; j < 4; j++) {
      wr &= (grid[i][j] == c || grid[i][j] == 'T');
      wc &= (grid[j][i] == c || grid[j][i] == 'T');
    }

    if (wr || wc)
      return true;
  }

  return (wda || wdb);
}

bool draw() {
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      if (grid[i][j] == '.')
        return false;
  return true;
}

int main() {
  int ncases;

  scanf("%i", &ncases);
  for (int caseno = 1; caseno <= ncases; caseno++) {
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        scanf(" %c", grid[i] + j);

    printf("Case #%i: ", caseno);
    if (won('X'))
      printf("X won\n");
    else if (won('O'))
      printf("O won\n");
    else if (draw())
      printf("Draw\n");
    else
      printf("Game has not completed\n");
  }
}
