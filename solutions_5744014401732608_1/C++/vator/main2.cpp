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

vector<int> G[77];

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
    int n;
    long long m;
    cin >> n >> m;
    cout << "Case #" << tt+1 << ": ";
    if (n == 2) {
      if (m == 1) {
        cout << "POSSIBLE" << endl;
        cout << "01\n00" << endl;
      } else {
        cout << "IMPOSSIBLE" << endl;
      }
      continue;
    }
    vector<string> A;
    string s;
    for (int i = 0; i < n; i++) { s += '0'; }
    for (int i = 0; i < n; i++) { A.push_back(s); }
    if ((1LL<<(n-2)) < m) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }
    long long cnt = 0;
    long long CC[77] = {};
    for (int i = 0; i < n-1; i++) {
      long long nxcnt;
      if (i < 2) nxcnt = 1;
      else nxcnt = cnt*2;
      if (m < nxcnt) break;
      for (int j = 0; j < i; j++) {
        A[j][i] = '1';
      }
      cnt = nxcnt;
      CC[i] = cnt;
    }
    for (int i = n-2; i >= 0 && m > 0; i--) {
      if (CC[i] == 0) continue;
      if (CC[i] <= m) {
        A[i][n-1] = '1';
        m -= CC[i];
      }
    }
    assert(m == 0);
    cout << "POSSIBLE" << endl;
    for (int i = 0; i < n; i++) {
      cout << A[i] << endl;
    }
  }
  return 0;
}
