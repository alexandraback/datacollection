#include <bits/stdc++.h>
using namespace std;
int f[1001]; vector<int> g[1001];
bool seen[1001];
int dd;
void dfs(int n, int c) {
  dd = max(dd, c);
  seen[n] = true;
  for (int k=0; k < g[n].size(); k++) if (!seen[g[n][k]]) {
    dfs(g[n][k], c+1);
  }
  seen[n] = false;
}
int main() {
  int T; cin >> T;
  for (int zz=1; zz <= T; zz++) {
    cout << "Case #" << zz << ": ";
    int N; cin >> N;
    for (int i=1; i <= N; i++) cin >> f[i], g[i].clear();
    for (int i=1; i <= N; i++) g[f[i]].push_back(i);
    int t = 0;
    memset(seen, 0, sizeof seen);
    for (int i=1; i <= N; i++) if (f[i] > i && f[f[i]] == i) {
      t += 2;
      dd = 0;
      seen[i] = true;
      dfs(f[i], 0);
      t += dd;
      dd = 0;
      seen[i] = false;
      seen[f[i]] = true;
      dfs(i, 0);
      t += dd;
    }

    for (int i=1; i <= N; i++) {
      memset(seen, 0, sizeof seen);
      seen[i] = true;
      int c = 1, j = f[i];
      while(!seen[j]) {
        seen[j] = true;
        j = f[j];
        c++;
      }
      if (j == i) t = max(c, t);
    }
    cout << t << endl;
  }
  return 0;
}
