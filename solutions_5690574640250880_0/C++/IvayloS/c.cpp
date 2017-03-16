/*
 * c.cpp
 *
 *  Created on: Apr 12, 2014
 *      Author: istrandjev
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <functional>
#define all(x) x.begin(),x.end()
#define mpair make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ld epsylon = 1e-9;

int move[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {
    -1, -1}};

bool solve(int n, int m, int k, int l, int x, vector<string>& a) {
  int non_mines = n * m - x;
  int lft = non_mines - k * l;
  if (lft < 0) {
    return false;
  }
  if (lft > k + l + 1 || k > n || l > m) {
    return false;
  }

  if (lft == 1) {
    return false;
  }

  a.clear();
  a.resize(n, string(m, '*'));
  for (int i = 0; i < k; ++i) {
    for (int j=  0 ; j < l; ++j) {
      a[i][j] = '.';
    }
  }
  a[0][0] = 'c';
  if(lft == 0) {
    return true;
  }
  if (k == n) {
    if (lft > k) {
      return false;
    }
    for (int j = 0; j < lft; ++j) {
      a[j][l] = '.';
    }
    return true;
  }
  if (l == m) {
    if (lft > l) {
      return false;
    }
    for (int j = 0; j < lft; ++j) {
      a[k][j] = '.';
    }
    return true;
  }
  if (lft == 2) {
    for (int j = 0; j < lft; ++j) {
      a[k][j] = '.';
    }
    return true;
  }
  if (lft == k + l + 1) {
    for (int j = 0; j <= l; ++j) {
      a[k][j] = '.';
    }
    for (int j = 0; j < k; ++j) {
      a[j][l] = '.';
    }
    return true;
  }
  if (lft == 3) {
    if (k >= 3) {
      for (int j = 0; j < lft; ++j) {
        a[j][l] = '.';
      }
      return true;
    } else if (l >= 3) {
      for (int j = 0; j < lft; ++j) {
        a[k][j] = '.';
      }
      return true;
    } else {
      return false;
    }
  }
  for (int j = 0; j < 2; ++j) {
    a[k][j] = '.';
  }
  for (int j = 0; j < 2; ++j) {
    a[j][l] = '.';
  }
  lft -= 4;
  int v = 2;
  while (lft > 0) {
    if (v < l) {
      a[k][v] = '.';
      lft--;
    }
    if (lft > 0 && v < k) {
      a[v][l] = '.';
      lft--;
    }
    v++;
  }
  return true;
}

bool verify(const vector<string>& a, int nmines) {
  int n = (int)a.size();
  int m = (int)a[0].size();
  vector<vector<int> > ne(n, vector<int>(m, 0));
  int mines = 0;
  for (int x = 0; x < n; ++x) {
      for (int y =0; y <m;++y) {
        if (a[x][y] == '*') {
          mines++;
        }
      }
  }
  if (mines != nmines) {
    return false;
  }
  for (int x = 0; x < n; ++x) {
    for (int y =0; y <m;++y) {
      if (a[x][y] == '*') {
        continue;
      }
      for (int l = 0; l < 8; ++l) {
        int tx = x + move[l][0];
        int ty = y + move[l][1];
        if (tx < 0 || tx >= n || ty < 0 || ty >= m) {
          continue;
        }
        if (a[tx][ty] == '*') {
          ne[x][y]++;
        }
      }
    }
  }
  for (int x = 0; x < n; ++x) {
    for (int y =0; y < m;++y) {
      if (a[x][y] == '*' || ne[x][y] == 0) {
        continue;
      }
      bool good = false;
      for (int l = 0; l < 8; ++l) {
        int tx = x + move[l][0];
        int ty = y + move[l][1];
        if (tx < 0 || tx >= n || ty < 0 || ty >= m) {
          continue;
        }
        if (ne[tx][ty] == 0 && a[tx][ty] != '*') {
          good = true;
          break;
        }
      }
      if (!good) {
        cerr << x << " " << y << endl;
        return false;
      }
    }
  }
  return true;
}

void solve(int n, int m, int x) {
  int non_mines = n * m - x;
  if (non_mines == 1) {
    vector<string> a(n, string(m, '*'));
    a[0][0] = 'c';
    for (int r = 0; r < n; ++r) {
      printf("%s\n", a[r].c_str());
    }
    return;
  }
  if (n == 1) {
    vector<string> a(n, string(m, '.'));
    for (int i = 0; i < x; ++i) {
      a[0][(int)a[0].size() - 1 - i] = '*';
    }
    a[0][0] = 'c';
    for (int r = 0; r < n; ++r) {
      printf("%s\n", a[r].c_str());
    }
    return;
  }
  if (m == 1) {
    vector<string> a(n, string(m, '.'));
    for (int i = 0; i < x; ++i) {
      a[(int)a.size() - 1 - i][0] = '*';
    }
    a[0][0] = 'c';
    for (int r = 0; r < n; ++r) {
      printf("%s\n", a[r].c_str());
    }
    return;
  }
  if (x == 0) {
    vector<string> a(n, string(m, '.'));
    a[0][0] = 'c';
    for (int r = 0; r < n; ++r) {
      printf("%s\n", a[r].c_str());
    }
    return;
  }
  if (n >= 2 && m >= 2) {
    vector<string> a;
    for (int k = 2; k <= n; ++k) {
      for (int l = 2; l <= m; ++l) {
        if (solve(n, m, k, l, x,  a)) {
          if (!verify(a, x)) {
            cerr << "Bad output on test: " << n << " " << m << " " << x<< endl;
            for (int r = 0; r < n; ++r) {
              cerr << a[r] << endl;
            }
            exit(0);
          }
          for (int r = 0; r < n; ++r) {
            printf("%s\n", a[r].c_str());
          }
          return;
        }
      }
    }
    printf("%s\n", "Impossible");

    return;
  }
}
int main() {
  freopen("google.in", "r", stdin);
  freopen("google.out", "w", stdout);

  int nt;
  cin >> nt;
  for (int it = 1; it <= nt; it++) {
    int n, m, x;
    cin >> n >> m >> x;
    cout << "Case #" << it << ":\n";
    solve(n, m, x);
  }
  return 0;
}




