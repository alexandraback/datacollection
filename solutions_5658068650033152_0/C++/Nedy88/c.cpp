#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
using namespace std;

const int MAXN = 20;

int a[MAXN][MAXN];
int n, m;
int mx[] = {0, 0, 1, -1};
int my[] = {1, -1, 0, 0};

void dfs(int i, int j) {
  a[i][j] = 1;
  for (int k = 0; k < 4; ++k) {
    int x = i + mx[k];
    int y = j + my[k];
    if (x < 0 || x >= n || y < 0 || y >= m) {
      continue;
    }
    if (!a[x][y]) {
      dfs(x, y);
    }
  }
}

void solve(int test) {
  int k;
  cin >> n >> m >> k;
  int res = k;
  int maxMask = 1 << (n * m);
  for (int mask = 0; mask < maxMask; ++mask) {
    int next = 0;
    int cnt = 0;
    memset(a, 0, sizeof a);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mask & (1 << next)) {
          a[i][j] = 2;
          ++cnt;
        }
        ++next;
      }
    }
    if (cnt >= res) {
      continue;
    }
    for (int i = 0; i < n; ++i) {
      if (!a[i][0]) {
        dfs(i, 0);
      }
      if (!a[i][m - 1]) {
        dfs(i, m - 1);
      }
    }
    for (int j = 0; j < m; ++j) {
      if (!a[0][j]) {
        dfs(0, j);
      }
      if (!a[n - 1][j]) {
        dfs(n - 1, j);
      }
    }
    int nClosed = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i][j] == 0) {
          ++nClosed;
        }
      }
    }
    if (nClosed + cnt >= k) {
      if (cnt < res) {
        res = cnt;
      }
    }
  }
  cout << "Case #" << test << ": " << res << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  int nTest;
  cin >> nTest;
  for (int test = 1; test <= nTest; ++test) {
    solve(test);
  }
  return 0;
}
