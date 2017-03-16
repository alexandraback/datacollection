#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

const int maxn = 1000 + 10;
vector<int> re_g[maxn];
int g[maxn], n;
int h[maxn];
bool mark[maxn];
int max_loop_ans;

int Max(int a, int b) {
  return a > b ? a : b;
}

void max_loop_dfs(int u, int hh) {
  if (mark[u] || mark[g[u]]) return;
  h[u] = hh;
  if (h[g[u]] == -1) {
    max_loop_dfs(g[u], hh+1);
  } else {
    max_loop_ans = Max(max_loop_ans, h[u] - h[g[u]] + 1);
  }
  mark[u] = true;
}

int max_loop() {
  memset(mark, 0, sizeof(mark));
  memset(h, -1, sizeof(h));
  max_loop_ans = 0;
  for (int i = 1; i <= n; i++) {
    if (h[i] == -1) {
      max_loop_dfs(i, 0);
    }
  }
  return max_loop_ans;
}

int re_max_depth(int u, int fa) {
  int h = 0;
  for (int i = 0; i < re_g[u].size(); i++) {
    int v = re_g[u][i];
    if (v != fa) {
      h = Max(h, re_max_depth(v, u));
    }
  }
  return h + 1;
}

int size_two_loop() {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (g[i] > i && g[g[i]] == i) {
      ans += re_max_depth(i, g[i]) +
             re_max_depth(g[i], i);
    }
  }
  return ans;
}

int main() {
  // freopen("B-small-attempt0", "r", stdin);
  // freopen("B-small.out", "w", stdout);
  
  int TextN;
  scanf("%d", &TextN);
  for (int TT = 1; TT <= TextN; TT++) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) re_g[i].clear();
    for (int i = 1; i <= n; i++) {
      scanf("%d", g + i);
      re_g[g[i]].push_back(i);
    }
    // printf("%d\n", max_loop());
    printf("Case #%d: %d\n", TT, Max(max_loop(), size_two_loop()));
  }

  return 0;
}