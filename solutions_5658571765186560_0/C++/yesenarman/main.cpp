#include <bits/stdc++.h>
#define sz(c) ((int)(c).size())
#define vec vector
using namespace std;
typedef long long int64;
typedef pair<int,int> pii;
typedef vec<string> mino;

ostream& operator<<(ostream &os, vec<string> a) {
  for (int i = 0; i < sz(a); ++i) {
    for (int j = 0; j < sz(a[0]); ++j)
      cerr << a[i][j];
    cerr << endl;
  }
  return os;
}

mino norm(mino x) {
  int mini = sz(x);
  int maxi = 0;
  int minj = sz(x[0]);
  int maxj = 0;
  for (int i = 0; i < sz(x); ++i)
    for (int j = 0; j < sz(x[i]); ++j)
      if (x[i][j] == '#') {
        mini = min(mini, i);
        maxi = max(maxi, i);
        minj = min(minj, j);
        maxj = max(maxj, j);
      }
  mino res;
  for (int i = mini; i <= maxi; ++i) {
    string s;
    for (int j = minj; j <= maxj; ++j)
      s += x[i][j];
    res.push_back(s);
  }
  return res;
}

vec<mino> gen(int n) {
  set<mino> cur;
  cur.insert({"#"});
  for (int i = 1; i < n; ++i) {
    set<mino> nxt;
    for (mino x : cur) {
      int w = sz(x[0]);
      mino y;
      y.push_back(string(w + 2, '.'));
      for (string s : x)
        y.push_back("." + s + ".");
      y.push_back(string(w + 2, '.'));

      static vec<int> dr = {-1, 0, +1, 0};
      static vec<int> dc = {0, -1, 0, +1};
      for (int r = 0; r < sz(y); ++r)
        for (int c = 0; c < sz(y[0]); ++c)
          if (y[r][c] == '#') {
            for (int k = 0; k < sz(dr); ++k) {
              int rr = r + dr[k];
              int cc = c + dc[k];
              if (y[rr][cc] != '.') continue;
              y[rr][cc] = '#';
              nxt.insert(norm(y));
              y[rr][cc] = '.';
            }
          }
    }
    cur = nxt;
  }
  return vec<mino>(cur.begin(), cur.end());
}

int fill(int n, int m, vec<string> &a, int i, int j) {
  if (i < 0 || j < 0 || i >= n || j >= m || a[i][j] != '.')
    return 0;
  a[i][j] = 'X';
  return fill(n, m, a, i + 1, j)
       + fill(n, m, a, i, j + 1)
       + fill(n, m, a, i - 1, j)
       + fill(n, m, a, i, j - 1) + 1;
}

bool good(int n, int m, vec<string> a, int X) {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (a[i][j] == '.' && fill(n, m, a, i, j) % X != 0)
        return false;
  return true;
}

mino rotate(mino a) {
  int n = sz(a[0]);
  int m = sz(a);
  mino res(n, string(m, '.'));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      res[i][j] = a[m - j - 1][i];
  return res;
}

bool checkRot(int X, int n, int m, mino x) {
  for (int i = 0; i < n - sz(x) + 1; ++i)
    for (int j = 0; j < m - sz(x[0]) + 1; ++j) {
      vec<string> a(n, string(m, '.'));
      for (int ii = 0; ii < sz(x); ++ii)
        for (int jj = 0; jj < sz(x[ii]); ++jj)
          a[i + ii][j + jj] = x[ii][jj];
      if (good(n, m, a, X)) return true;
    }
  return false;
}

bool checkMino(int X, int n, int m, mino x) {
  for (int rot = 0; rot < 4; ++rot) {
    if (checkRot(X, n, m, x)) return true;
    x = rotate(x);
  }
  return false;
}

bool solve(int X, int n, int m) {
  if (X >= 7) return false;

  for (mino x : gen(X)) {
    if (!checkMino(X, n, m, x)) return false;
  }

  return true;
}

void solve(int testcase) {
  cout << "Case #" << testcase << ": ";

  int X, n, m;
  cin >> X >> n >> m;
  if (solve(X, n, m)) {
    cout << "GABRIEL" << endl;
  } else {
    cout << "RICHARD" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  //vec<string> a = {"##."};
  //cerr << good(1, 3, a, 2) << endl;
  //return 0;

  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t)
    solve(t);

  return 0;
}
