#include <cstdio>
#include <string>

using namespace std;

char a[5][5];

bool check(char c)
{
  for (int i = 0; i < 4; ++i) {
    int numc = 0;
    for (int j = 0; j < 4; ++j) {
      if (a[i][j] == c || a[i][j] == 'T') numc++;
    }
    if (numc == 4) return true;
    numc = 0;
    for (int j = 0; j < 4; ++j) {
      if (a[j][i] == c || a[i][j] == 'T') numc++;
    }
    if (numc == 4) return true;
  }
  int ld = 0, rd = 0;
  for (int i = 0; i < 4; ++i) {
    if (a[i][i] == c || a[i][i] == 'T') ld++;
    if (a[i][3 - i] == c || a[i][3 - i] == 'T') rd++;
  }
  if (ld == 4 || rd == 4) return true;
  return false;
}

string solve() {
  if (check('X')) return "X won";
  if (check('O')) return "O won";
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (a[i][j] == '.') return "Game has not completed";
    }
  }
  return "Draw";
}

int main() {
  int T;
  scanf("%d", &T);
  int cn = 0;
  while (T--) {
    ++cn;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        scanf(" %c", &a[i][j]);
      }
    }
    printf("Case #%d: %s\n", cn, solve().c_str());
  }
}
