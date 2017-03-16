#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

int n, m, b;
int a[55];
bool f;

void solve(int r, int k, int s) {
  if (f) return;
  if (r > n) {
    if (s == b) f = true;
  } else {
    int x = s + (n - r + 1) * k;
    if (x < b) return;
    if (r == 1 || r < n) {
      if (!f) {
        a[r] = 0;
        solve(r + 1, 0, s);
      }
      for (int i = 1; i <= k && i + 2 <= m && !f; ++i) {
        a[r] = i;
        solve(r + 1, i, s + i);
      }
      if (k == m && !f) {
        a[r] = k;
        solve(r + 1, k, s + k);
      }
    } else {
      a[r] = k;
      solve(r + 1, k, s + k);
    }
  }
}

const int dx[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
const int dy[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

char g[55][55];

int main() {
  assert(freopen("input.txt", "r", stdin));
  assert(freopen("output.txt", "w", stdout));
  //std::ios::sync_with_stdio(0);
  //std::cin.tie(0);
  int tt, nc = 0;
  scanf("%d", &tt);
  while (tt--) {
    printf("Case #%d:\n", ++nc);
    scanf("%d %d %d", &n, &m, &b);
    memset(g, '*', sizeof(g));
    if (b + 1 == n * m) {
      g[1][1] = 'c';
      for (int i = 1; i <= n; ++i) {
        g[i][m + 1] = 0;
        puts(g[i] + 1);
      }
    } else {
      f = false;      
      solve(1, m, 0);
      if (f) {
        for (int i = 1; i <= n; ++i)
          for (int j = a[i] + 1; j <= m; ++j)
            g[i][j] = '.';
        bool ok = false;
        for (int i = 1; i <= n && !ok; ++i)
          for (int j = 1; j <= m && !ok; ++j)
            if (g[i][j] == '.') {
              int cnt = 0;
              for (int k = 0; k < 8; ++k) {
                int x = i + dx[k];
                int y = j + dy[k];
                cnt += (1 <= x && x <= n) && (1 <= y && y <= m) && (g[x][y] == '*');
              }
              if (cnt == 0) {
                ok = true;
                g[i][j] = 'c';
              }
            }
        for (int i = 1; i <= n; ++i) {
          g[i][m + 1] = 0;
          puts(g[i] + 1);
        }
      } else {
        puts("Impossible");
      }
    }
  }
}
