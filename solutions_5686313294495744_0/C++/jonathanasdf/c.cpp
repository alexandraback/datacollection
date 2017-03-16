#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1000, N = 1000;
bool adjmat[M][N], seen[N]; int matchL[M], matchR[N], m, n;
bool bpm(int u) { // Can we find augmenting path starting from u
  for(int v = 0; v < n; v++) if(adjmat[u][v] && !seen[v]) { seen[v] = true;
    if(matchR[v] == -1 || bpm(matchR[v]) ) { matchL[u] = v, matchR[v] = u;
      return true; } }
  return false; }
int main() {
  int T; cin >> T;
  for (int zz=1; zz <= T; zz++) {
    cout << "Case #" << zz << ": ";
    int N; cin >> N;
    map<string, int> s, t;
    memset(matchL,-1,sizeof matchL); memset(matchR,-1,sizeof matchR);
    memset(adjmat, 0, sizeof adjmat);
    for (int i=0; i < N; i++) {
      string a, b; cin >> a >> b;
      if (!s.count(a)) s[a] = s.size()-1;
      if (!t.count(b)) t[b] = t.size()-1;
      adjmat[s[a]][t[b]] = true;
    }
    m = s.size(); n = t.size();
    int cnt = 0;
    for(int i = 0; i < m; i++) {
      memset(seen, 0, sizeof seen);
      if(bpm(i)) cnt++;
    }
    cout << N - (m + n - cnt) << endl;
  }
  return 0;
}
