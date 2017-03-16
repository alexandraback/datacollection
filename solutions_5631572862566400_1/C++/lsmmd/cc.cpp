#include <iostream>
#include <vector>
using namespace std;

int n;
int dfs(int root, vector<int> &vis, vector<int> &a) {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i] && a[i] == root) {
      vis[i] = 1;
      ans = max(ans, dfs(i, vis, a));
      vis[i] = 0;
    }
  }
  return ans;
}

int main() {
  int tk, tk1 = 0;
  cin >> tk;
  while (tk--) {
    tk1++;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
      vector<int> vis(n, 0);
      int u = i;
      vis[u] = 1;
      while (!vis[a[u]]) {
        vis[a[u]] = vis[u] + 1;
        u = a[u];
      }
      ans = max(ans, vis[u] - vis[a[u]] + 1);
    }
    int len = 0;

    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++) {
      // a->b , b->a
      if (a[a[i]] == i && !vis[i]) {
        vis[i] = vis[a[i]] = 1;
        len += dfs(i, vis, a) + 1;
        len += dfs(a[i], vis, a) + 1;
      }
    }
    cout << "Case #" << tk1 << ": " << max(ans, len) << endl;
  }
  return 0;
}
