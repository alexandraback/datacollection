#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>

using namespace std;

int n;
int m;
int u[55];
string a[55];
int was[55];
int p[55];
vector<int> g[55];

int main() {
  freopen("in", "r", stdin); freopen("out", "w", stdout); freopen("log", "w", stderr);
  int tt; scanf("%d", &tt);
  for (int cc = 1; cc <= tt; ++cc) {
    for (int i = 0; i < 55; ++i) g[i].clear();
    for (int i = 0; i < 55; ++i) was[i] = 0;
    for (int i = 0; i < 55; ++i) p[i] = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) {
      int x, y; scanf("%d %d", &x, &y); --x; --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    for (int i = 0; i < n; ++i) u[i] = i;
    string ans = "@";
    do {
      for (int i = 0; i < n; ++i) p[i] = -1;
      bool can = true;
      for (int it = 0; it < n - 1; ++it) {
        int x = u[it];
        bool found = false;
        while (x != -1) {
          for (int i = 0; i < g[x].size(); ++i) {
            int y = g[x][i];
            if (y == u[it + 1]) {
              p[y] = x; found = true; break;
            }
          }
          if (found) break;
          x = p[x];
        }
        if (!found) can = false;
      }
      if (can) {
        string cur = "";
        for (int i = 0; i < n; ++i) cur += a[u[i]];
        if (cur < ans) ans = cur;
      }
    } while (next_permutation(u, u + n));
    printf("Case #%d: %s\n", cc, ans.c_str());
  }
  return 0;
}