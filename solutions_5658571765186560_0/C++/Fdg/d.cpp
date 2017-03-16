/* 
  2014.03.26 15:10
  http://codeforces.ru/gym/100289/
*/


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>
#include <cmath>
#include <string> 
#include <ctime>

using namespace std;

#undef Fdg_Home

bool used[22][22];

vector<pair<int, int>> v;

int dx[] = {-1, 0, 0, 1},
    dy[] = {0, -1, 1, 0};

int x, r, c, win = 0;

bool was[22][22], used2[22][22];

int dfs(int x, int y) {
  if (x >= 0 && x < r && y >= 0 && y < c && !used2[x][y] && !was[x][y]) {
    was[x][y] = true;
    int cnt = 1;
    for (int t = 0; t < 4; ++t) {
      int nx = x + dx[t], ny = y + dy[t];
      cnt += dfs(nx, ny);
    }
    return cnt;
  }
  return 0;
}

void go(int left) {
  if (left == 0) {
    bool good = true;
    for (int it = 0; it < 2; ++it) {
      for (int i = -10; i <= 10; ++i) {
        for (int j = -10; j <= 10; ++j) {
          memset(used2, 0, sizeof(used2));
          bool ok = true;
          for (int ii = 0; ii < 10; ++ii)
            for (int jj = 0; jj < 10; ++jj) {
              if (used[ii][jj]) {
                int x = ii + i, y = jj + j;
                // cout << x << "  " << y << endl;
                if (x >= 0 && x < r && y >= 0 && y < c) {
                  used2[x][y] = true;
                } else {
                  ok = false;
                }
              }
            }
          if (ok) {
            // cout << i << "  " << j << endl;
            memset(was, 0, sizeof(was));
            bool can = true;
            for (int ii = 0; ii < r; ++ii) {
              for (int jj = 0; jj < c; ++jj) {
                if (!was[ii][jj] && !used2[ii][jj] && dfs(ii, jj) % x != 0) {
                  can = false;
                }
              }
            }
            if (can) good = false;
          }
        }
      }

      for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < i; ++j)
          swap(used[i][j], used[j][i]);
      }
    }
    if (good) {
      win = true;
      // for (int i = 0; i < 10; ++i) {
      //   for (int j = 0; j < 10; ++j) {
      //     cout << used[i][j];
      //   }
      //   cout << endl;
      // }
      // cout << endl;
    }
    return;
  }
  for (int i = 0; i < v.size(); ++i) {
    for (int t = 0; t < 4; ++t) {
      int x = v[i].first + dx[t], y = v[i].second + dy[t];
      if (x >= 0 && x < 10 && y >= 0 && y < 10 && !used[x][y]) {
        used[x][y] = true;
        v.push_back({x, y});
        go(left - 1);
        v.pop_back();
        used[x][y] = false;
      }
    }
  }
}

void solveTest(int CS) {
  printf("Case #%d: ", CS);
  cin >> x >> r >> c;
  // if (r < c) swap(r, c);
  if (x > 6 || 2 * min(r, c) + 1 <= x) {
    puts("RICHARD");
    return;
  }
  win = 0;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      used[i][j] = true;
      v.push_back({i, j});
      go(x - 1);
      v.pop_back();
      used[i][j] = false;
    }
  }
  puts(win ? "RICHARD" : "GABRIEL");
}

int main() {
#ifndef Fdg_Home
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  scanf("%d\n", &T);
  for (int test = 1; test <= T; ++test) {
    solveTest(test);
  }
  return 0;
}