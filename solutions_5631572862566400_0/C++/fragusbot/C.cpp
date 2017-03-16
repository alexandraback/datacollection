#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

int st;
int was[N];
vector <int> g[N];

int dfs(int x) {
  was[x] = st;
  int res = 1;
  for (int y : g[x]) {
    if (was[y] != st) {
      res = max(res, 1 + dfs(y));
    }
  }
  return res;
}

int ne[N];
bool a[N][N];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  freopen("log", "w", stderr);
  st = 0;
  memset(was, 0, sizeof was);
  int tt;
  scanf("%d", &tt);
  for (int cc = 1; cc <= tt; ++cc) {
    printf("Case #%d: ", cc);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      g[i].clear();
    }
    memset(a, false, sizeof a);
    for (int i = 0; i < n; ++i) {
      scanf("%d", ne + i);
      --ne[i];
      g[ne[i]].push_back(i);
      a[ne[i]][i] = true;
    }
    ++st;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (a[i][j] && a[j][i]) {
          was[i] = was[j] = st;
          ans += dfs(i);
          ans += dfs(j);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      ++st;
      was[i] = st;
      int x = ne[i], len = 1;
      while (true) {
        if (x == i) {
          ans = max(ans, len);
        }
        if (was[x] == st) {
          break;
        }
        was[x] = st;
        ++len;
        x = ne[x];
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}