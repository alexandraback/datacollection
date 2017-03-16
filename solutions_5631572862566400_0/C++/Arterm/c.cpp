#include <bits/stdc++.h>

using namespace std;

const int M = 1010;

int n, f[M];
int d[M], h[M];
bool used[M];
vector<int> g[M];

void read() {
  fill(used, used + M, false);
  for (int i = 0; i < M; ++i)
    g[i].clear();


  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> f[i];
    --f[i];
    g[f[i]].push_back(i);
  }
}

int dfs(int v, int ex) {
  used[v] = true;

  int ans = 0;

  for (int to : g[v])
    if (to != ex) {
      ans = max(ans, dfs(to, ex));
  }

  return 1 + ans;
}

void kill() {
  int ans = 0;

  for (int v = 0; v < n; ++v) {
    int u = f[v], len = 1;
    while (u != v && len < n) {
      ++len;
      u = f[u];
    }

    if (u == v)
      ans = max(ans, len); //longest cycle
  }


  int sum = 0;

  for (int i = 0; i < n; ++i)
    if (!used[i] && f[f[i]] == i) {
      sum += dfs(i, f[i]) + dfs(f[i], i);
    }

  ans = max(ans, sum);

  cout << ans << endl;
}


int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    read();
    kill();
    cerr << "Case #" << i << " done.\n";
  }
  return 0;
}
