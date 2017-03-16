#include <iostream>
#include <algorithm>
using namespace std;

bool w[21][21][21];

int main() {
  for (int i = 1; i <= 20; i++) {
    for (int j = i; j <= 20; j++) {
      w[1][i][j] = 1;
      if ((i*j) % 2 == 0)
        w[2][i][j] = 1;
      if (i > 1 && (i*j) % 3 == 0)
        w[3][i][j] = 1;
      if (i > 2 && (i*j) % 4 == 0)
        w[4][i][j] = 1;
      if ((i*j) % 5 == 0) {
        if (i == 3 && j >= 10)
          w[5][i][j] = 1;
        else if (i > 3)
          w[5][i][j] = 1;
      }
      if ((i*j) % 6 == 0) {
        if (i > 3)
          w[6][i][j] = 1;
      }
    }
  }
  int t; cin >> t;
  for (int T = 1; T <= t; T++) {
    int x, r, c;
    cin >> x >> r >> c;
    if (r > c)
      swap(r,c);
    cout << "Case #" << T << ": " << (w[x][r][c] ? "GABRIEL" : "RICHARD") << "\n";
  }
  return 0;
}
