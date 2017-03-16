#include <iostream>
using namespace std;

#define FAIL { cout << "Impossible\n"; goto end; }

int main() {
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    cout << "Case #" << tt << ":\n";

    int r, c, m;
    cin >> r >> c >> m;

    // cout << r << " " << c << " " << m << endl;

    if (m == r*c-1) {
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          if (!i && !j) cout << 'c';
          else cout << '*';
        }
        cout << endl;
      }
      continue;
    }

    bool transp = false;
    if (r > c) {
      transp = true;
      int tmp = r; r = c; c = tmp;
    }

    // now r <= c

    char res[r][c];

    if (r == 1) {
      for (int i = c-1; i > 0; --i) {
        if (m-- > 0) res[0][i] = '*';
        else res[0][i] = '.';
      }
    }

    if (r == 2) {
      if (m % 2) FAIL;
      if (m == r*c - 2) FAIL;

      res[1][0] = '.';

      for (int i = c-1; i > 0; --i) {
        if (m > 0) { res[0][i] = res[1][i] = '*'; m -= 2; }
        else res[0][i] = res[1][i] = '.';
      }
    }

    if (r >= 3) {  // 3 <= r <= c
      int empty = r*c - m;

      if (empty < 9 && empty % 2) FAIL;
      if (empty <= 3) FAIL;

      if (empty <= 2 * c) {
        for (int i = 2; i < r; ++i) {
          for (int j = 0; j < c; ++j) res[i][j] = '*';
        }
        m -= (r-2)*c;

        if (empty % 2) {
          res[2][0] = res[2][1] = res[2][2] = '.';
          empty -= 3;
        }

        for (int j = 0; j < c; ++j) {
          if (empty) { res[0][j] = res[1][j] = '.'; empty -= 2; }
          else res[0][j] = res[1][j] = '*';
        }

      } else {  // more than 2 empty rows
        for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) res[i][j] = '.';

        int i = r-1;

        while (m >= c) {
          for (int j = 0; j < c; ++j) res[i][j] = '*';
          m -= c;
          --i;
        }

        for (int j = c-1; j >= c-m; --j) res[i][j] = '*';

        if (m == c-1) {
          res[i][1] = '.';
          res[i-1][c-1] = '*';

          if (res[0][c-1] == '.' && res[1][c-1] == '*') {
            res[2][2] = '.';
            res[0][c-1] = '*';
          }
        }
      }
    }

    res[0][0] = 'c';

    for (int i = 0; i < (transp ? c : r); ++i) {
      for (int j = 0; j < (transp ? r : c); ++j) {
        cout << res[transp ? j : i][transp ? i : j];
      }
      cout << endl;
    }

    end: ;
  }
}
