#include <bits/stdc++.h>

using namespace std;

int n;
string code[8];
bool matrix[8][8];

int main() {
  freopen("C-small-attempt0.in", "rt", stdin);
  freopen("C-small-attempt0.out", "wt", stdout);
  int t; cin >> t;
  for(int tst = 1; tst <= t; ++tst) {
    int m; cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> code[i];
    memset(matrix, 0, sizeof matrix);
    while(m--) {
      int u, v; cin >> u >> v; --u; --v;
      matrix[u][v] = matrix[v][u] = 1;
    }
    vector<int> order(n);
    for(int i = 0; i < n; ++i) order[i] = i;
    string answer = "Z", build;
    do
    {
      vector<int> currentPath(1, order[0]);
      for(auto u : order) if(u != order[0]) {
        while(currentPath.size()) {
          if(matrix[currentPath.back()][u]) break;
          currentPath.pop_back();
        }
        if(currentPath.empty()) goto invalid;
        currentPath.push_back(u);
      }
      build = "";
      for(auto u : order) build += code[u];
      answer = min(answer, build);
      invalid:;
    }while(next_permutation(order.begin(), order.end()));
    cout << "Case #" << tst << ": " << answer << '\n';
  }
  return 0;
}
