#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long LL;

int T, ti, n, m;
int p[60][60][60];
bool bbb;

bool check() {
  // for (int i = 0; i < n; ++i) {
    // for (int j = 0; j < n; ++j)
      // cout << p[1][i][j];
    // cout << endl;
  // }
  for (int l = 2; l < n; ++l)
    for (int q = 1; q < l; ++q)
      for (int i = 0; i < n; ++i)
        for (int j = i+2; j < n; ++j) {
          p[l][i][j] = 0;
          for (int k = i+1; k < j; ++k)
            p[l][i][j] += p[q][i][k] * p[l-q][k][j];
        }
  int s = 0;
  for (int l = 1; l < n; ++l)
    s += p[l][0][n-1];
  // cout << "==== " << s << endl;
  // for (int l = 1; l < n; ++l) {
    // cout << l << ' ' << p[l][0][n-1] << endl;
  // }
  if (s == m) {
    cout << "POSSIBLE" << endl;
    bbb = true;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      cout << p[1][i][j];
    cout << endl;
  }

    return bbb;
  }
  return false;
}

bool f(int a, int b) {
  if (bbb)
    return true;
  if (a == n-1)
    return check();
  int na = a, nb = b;
  if (b == n-1)
    na = a+1, nb = na+1;
  else
    na = a, nb = b+1;
  f(na, nb);
  p[1][a][b] = 1;
  f(na, nb);
  p[1][a][b] = 0;
  return false;
}

int solve() {
  cin >> n >> m;
  bbb = false;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      p[1][i][j] = 0;
  printf("Case #%d: ", ti);
  f(0, 1);
  if (!bbb)
    cout << "IMPOSSIBLE" << endl;
  return 0;
}

int main() {
  cin >> T;
  for (ti = 1; ti <= T; ti++) {
    solve();
  }
  return 0;
}
