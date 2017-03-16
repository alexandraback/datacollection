#include <cstdio>
#include <vector>

using namespace std;

bool u[1024];
vector<int> edges[1024];

bool dfs(int v) {
  u[v] = true;
  for (unsigned i = 0; i < edges[v].size(); i++) {
    int w = edges[v][i];
    if (!u[w]) {
      if (dfs(w)) {
        return true;
      }
    }
    else {
      return true;
    }
  }

  return false;
}

bool solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int m;
    scanf("%d", &m);
    edges[i].resize(m);
    for (int j = 0; j < m; j++) {
      scanf("%d", &edges[i][j]);
      edges[i][j]--;
    }
  }
  
  for (int i = 0; i < n; i++) {
    memset(u, 0, sizeof(u));
    if (dfs(i)) {
      return true;
    }
  }
  
  return false;
}

int main() {
  int t = 0;
  scanf("%d", &t);
  for (int ti = 0; ti < t; ti++) {
    bool result = solve();
    printf("Case #%d: ", ti + 1);
    if (result) {
      printf("Yes\n");
    }
    else {
      printf("No\n");
    }
  }
  return 0;
}
