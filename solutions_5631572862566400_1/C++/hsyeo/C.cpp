#include <iostream>
#include <vector>

using namespace std;

int G[1001];
int d[1001];
int c[1001];
int N;

int dfs(int v, int depth) {
  d[v] = depth;
  int w = G[v];
  if (d[w] == 0)
    return dfs(w, depth + 1);
  return d[v] - d[w] + 1;
}

int dfs2(int v, int depth, int root) {
  int ret = depth;
  for (int i = 1; i <= N; i++) {
    if (G[i] == v && i != root) {
      ret = max(ret, dfs2(i, depth + 1, root));
    }
  }
  return ret;
}

int main() {
  int T; cin >> T;
  for (int test_cases = 1; test_cases <= T; test_cases++) {
    cin >> N;
    for (int i = 1; i <= N; i++) {
      cin >> G[i];
      d[i] = 0;
      c[i] = 0;
    }
    int ans = 0;
    // Detect the longest cycle
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) d[j] = 0;
      if (d[i] == 0) ans = max(ans, dfs(i, 1));
    }
    int tot = 0;
    // Extend the cycle with length 2.
    for (int i = 1; i <= N; i++) {
      int j = G[i];
      if (j > i && G[j] == i) {
	tot += 2 + dfs2(i, 0, j) + dfs2(j, 0, i);
      }
    }
    ans = max(ans, tot);

    printf("Case #%d: %d\n", test_cases, ans);
  }
  return 0;
}
