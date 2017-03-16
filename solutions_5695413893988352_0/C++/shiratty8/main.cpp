#include <bits/stdc++.h>
using namespace std;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FORR(x,arr) for(auto&& x:arr)
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i,n) for (int i = (n)-1; i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define BIT(n) (1LL<<(n))
#define SZ(x) ((int)(x).size())
typedef long long ll;
// -------------------------------------

int N;
string C, J;

ll mi;
ll ansc, ansj;

void dfs(int pos, ll cs, ll js) {
  if (pos == N) {
    ll d = labs(cs - js);
    if (d < mi) {
      ansc = cs;
      ansj = js;
      mi = d;
    }
    else if (d == mi) {
      if (cs < ansc) {
        ansc = cs;
        ansj = js;
      }
    }
    return;
  }

  char c = C[pos];
  char j = J[pos];
  int w = (cs > js ? 1 : js > cs ? -1 : 0);

  cs *= 10;
  js *= 10;

  if (w == 0) {
    if (c == '?' && j == '?') {
      dfs(pos+1, cs, js);  // 0, 0
      dfs(pos+1, cs+1, js);  // 1, 0
      dfs(pos+1, cs, js+1);  // 0, 1
    }
    else if (c == '?') {
      int nj = (j - '0');
      REP(k, 3) {
        int nc = nj + k - 1;
        if (nc >= 0 && nc <= 9) {
          dfs(pos+1, cs + nc, js + nj);
        }
      }
    }
    else if (j == '?') {
      int nc = (c - '0');
      REP(k, 3) {
        int nj = nc + k - 1;
        if (nj >= 0 && nj <= 9) {
          dfs(pos+1, cs + nc, js + nj);
        }
      }
    }
    else {
      int nc = (c - '0');
      int nj = (j - '0');
      dfs(pos+1, cs + nc, js + nj);
    }
  }
  else {
    if (w == 1) {
      if (j == '?') j = '9';
      if (c == '?') c = '0';
    }
    else if (w == -1) {
      if (c == '?') c = '9';
      if (j == '?') j = '0';
    }
    int nc = (c - '0');
    int nj = (j - '0');
    dfs(pos+1, cs + nc, js + nj);
  }
}

void solve() {
  cin >> C >> J;
  N = SZ(C);

  mi = 1e18+1;

  dfs(0, 0, 0);

  cout << setfill('0') << setw(N) << ansc;
  cout << ' ';
  cout << setfill('0') << setw(N) << ansj;
  cout << endl;
}

int main() {
  int T;
  scanf("%d", &T);
  REP(i, T) {
    _P("Case #%d: ", i+1);
    solve();
  }

  return 0;
}
