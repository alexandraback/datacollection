#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

struct solution { bool can; vector<vector<bool>> b; int i; int j; };

solution solve(int r, int c, int m) {
  auto res = vector<vector<bool>>(r, vector<bool>(c));
  if (r == 1) {
    for (int i = 0; i < m; i++)
      res[0][i] = true;
    return {true, res, r - 1, c - 1};
  } else if (c == 1) {
    for (int i = 0; i < m; i++)
      res[i][0] = true;
    return {true, res, r - 1, c - 1};
  }
  if (m == r * c - 1) {
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++)
        res[i][j] = true;
    res[r - 1][c - 1] = false;
    return {true, res, r - 1, c - 1};
  }
  for (int i = 0; i < r - 1; i++)
    for (int j = 0; j < c - 1; j++) {
      int const fill = i * c + j * r - i * j;
      int const left = (r - i - 2) * (c - j - 2);
      if (m >= fill && m - fill <= left) {
        for (int ii = 0; ii < i; ii++)
          for (int k = 0; k < c; k++)
            res[ii][k] = true;
        for (int jj = 0; jj < j; jj++)
          for (int k = 0; k < r; k++)
            res[k][jj] = true;
        m -= fill;
        for (int ii = i; m > 0 && ii < r - 2; ii++)
          for (int jj = j; m > 0 && jj < c - 2; jj++) {
            res[ii][jj] = true;
            m--;
          }
        assert(m == 0);
        return {true, res, r - 1, c - 1}; 
      }
    }
  return {false};
}

int main() {
  int tests = 0;
  cin >> tests;
  for (int t = 0; t < tests; t++) {
    cout << "Case #" << (t + 1) << ":\n";
    int r, c, m;
    cin >> r >> c >> m;
    auto sol = solve(r, c, m);
    if (!sol.can) {
      cout << "Impossible\n";
    } else {
      assert(sol.b.size() == r);
      assert(sol.b[0].size() == c);
      int cnt = 0;
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
          if (i == sol.i && j == sol.j)
            cout << 'c';
          else if (sol.b[i][j]) {
            cout << '*';
            cnt++;
          } else
            cout << '.';
        cout << '\n';
      }
      assert(cnt == m);
    }
  }
}
