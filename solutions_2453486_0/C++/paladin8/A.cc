#include <iostream>
using namespace std;

int dx[] = { 0, 1, 1, 1 }, dy[] = { 1, 1, 0, -1 };

int main() {
  int t; cin >> t;
  for (int c = 1; c <= t; c++) {
    string g[4];
    for (int i = 0; i < 4; i++) cin >> g[i];

    bool xwon = false, owon = false, done = true;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        for (int k = 0; k < 4; k++) {
          int numx = 0, numo = 0;
          for (int l = 0; l < 4; l++) {
            int x = i + l * dx[k], y = j + l * dy[k];
            if (x >= 0 && x < 4 && y >= 0 && y < 4) {
              if (g[x][y] == 'X') numx++;
              else if (g[x][y] == 'O') numo++;
              else if (g[x][y] == 'T') { numx++; numo++; }
              else done = false;
            }
          }
          if (numx == 4) xwon = true;
          if (numo == 4) owon = true;
        }

    cout << "Case #" << c << ": ";
    if (xwon) cout << "X won" << endl;
    else if (owon) cout << "O won" << endl;
    else if (done) cout << "Draw" << endl;
    else cout << "Game has not completed" << endl;
  }
  return 0;
}
