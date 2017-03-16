// TEMPLATE {{{
#include <bits/stdc++.h>
using namespace std;
#ifndef LOCAL
#define OJ 1
#else
#define OJ 0
#endif

#define endl '\n'
#define TIMESTAMP merr << "Execution time: " << fixed << setprecision(3) << (double)clock()/CLOCKS_PER_SEC << " s.\n"
class C_ {}; template <typename T> C_& operator <<(C_& __m, const T& __s) { if (!OJ) cerr << "\E[91m" << __s << "\E[0m"; return __m; }
C_ merr;

struct __s { __s() { if (OJ) { ios_base::Init i; cin.sync_with_stdio(0); cin.tie(0); } } ~__s(){ TIMESTAMP; } } __S;
/// END OF TEMPLATE }}}

vector<int> G[7];

int u[7];
bool cycle;
void dfs1(int v) {
  u[v] = 1;
  for (int i = 0; i < (int)G[v].size(); i++) {
    int vv = G[v][i];
    if (u[vv] == 1) {
      cycle = true;
      return;
    }
    if (u[vv]) continue;
    dfs1(vv);
    if (cycle) return;
  }
  u[v] = 2;
}

int cnt2;
int en;
void dfs2(int v) {
  if (v == en) {
    cnt2++;
    return;
  }
  u[v] = 1;
  for (int i = 0; i < (int)G[v].size(); i++) {
    int vv = G[v][i];
    if (u[vv]) continue;
    dfs2(vv);
  }
  u[v] = 0;
}

int main(void) {
  int T;
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    int n,m;
    cin >> n >> m;
    cout << "Case #" << tt+1 << ": ";
    merr << "Case #" << tt+1 << ": ";
    if (n == 2) {
      if (m == 1) {
        cout << "POSSIBLE" << endl;
        cout << "01\n00" << endl;
        merr << "POSSIBLE" << endl;
        merr << "01\n00" << endl;
      } else {
        cout << "IMPOSSIBLE" << endl;
        merr << "IMPOSSIBLE" << endl;
      }
      continue;
    }
    vector<pair<int,int> > E;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        E.push_back(make_pair(i,j));
      }
    }
    int lim = 1;
    for (int i = 0; i < (int)E.size(); i++) {
      lim *= 3;
    }
    bool found = false;
    for (int bit = 0; bit < lim; bit++) {
      int nn = bit;
      bool ok = true;
      for (int i = 0; i < 7; i++) { G[i].clear(); }
      for (int i = 0; i < (int)E.size(); i++) {
        int a = E[i].first, b = E[i].second;
        if (nn%3 == 1) {
          if (a == n-1 || b == 0) { ok = false; break; }
          G[a].push_back(b);
        } else if (nn%3 == 2) {
          if (b == n-1 || a == 0) { ok = false; break; }
          G[b].push_back(a);
        }
        nn /= 3;
      }
      if (!ok) continue;
      cycle = false;
      memset(u, 0, sizeof(u));
      dfs1(0);
      if (cycle) continue;
      cnt2 = 0;
      memset(u, 0, sizeof(u));
      en = n-1;
      dfs2(0);
      if (cnt2 == m) {
        cout << "POSSIBLE" << endl;
        merr << "POSSIBLE" << endl;
        vector<string> A;
        string s;
        for (int i = 0; i < n; i++) { s += '0'; }
        for (int i = 0; i < n; i++) { A.push_back(s); }
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < (int)G[i].size(); j++) {
            int v = G[i][j];
            A[i][v] = '1';
          }
        }
        for (int i = 0; i < n; i++) {
          cout << A[i] << endl;
          merr << A[i] << endl;
        }
        found = true;
        break;
      }
    }
    if (found) continue;
    cout << "IMPOSSIBLE" << endl;
    merr << "IMPOSSIBLE" << endl;
  }
  return 0;
}
