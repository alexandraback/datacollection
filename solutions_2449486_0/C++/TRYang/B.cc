#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>

using std::set;
using std::make_pair;
using std::pair;

const int kMAXN = 110;

int cover[kMAXN][kMAXN];
int g[kMAXN][kMAXN];
set<pair<int, int> > left;
int n, m;
int check_row(int x, int y) {
  for (int i = 0; i < m; i++)
    if (g[x][i] > g[x][y]) return 0;
  return 1;
}
int check_col(int x, int y) {
  for (int i = 0; i < n; i++)
    if (g[i][y] > g[x][y]) return 0;
  return 1;
}
void del_row(int x, int y) {
  for (int i = 0; i < m; i++)
    if (g[x][i] == g[x][y] && !cover[x][i]) {
      cover[x][i] = 1;
      left.erase(make_pair(g[x][i], x * m + i));
    }
}
void del_col(int x, int y) {
  for (int i = 0; i < n; i++)
    if (g[i][y] == g[x][y] && !cover[i][y]) {
      cover[i][y] = 1;
      left.erase(make_pair(g[i][y], i * m + y));
    }
}
int main() {
  int T, cp = 0;
  for (scanf("%d", &T); T; T--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) scanf("%d", &g[i][j]);
    memset(cover, 0, sizeof cover);
    left.clear();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) left.insert(make_pair(g[i][j], i * m + j));
    while (left.size() > 0) {
      int x = left.begin()->second / m;
      int y = left.begin()->second % m;
      int flag = 0;
      if (check_row(x, y)) {
        del_row(x, y);
        flag = 1;
      }
      if (check_col(x, y)) {
        del_col(x, y);
        flag = 1;
      }
      if (!flag) break;
    }
    int ans = 1;
    for (int i = 0; i < n; i++)
      for (int j = 0 ; j < m; j++)
        if (!cover[i][j]) ans = 0;
    printf("Case #%d: ", ++cp);
    puts(ans ? "YES" : "NO");
  }
  return 0;
}
