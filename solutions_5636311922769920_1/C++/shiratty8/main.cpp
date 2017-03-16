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

void solve(int K, int C, int S) {
  int t = (K+C-1)/C;
  if (t > S) {
    puts("IMPOSSIBLE");
    return;
  }
  ll powk[100];
  powk[0] = 1;
  FOR(i, 1, C) {
    powk[i] = powk[i-1] * K;
  }

  REP(i, t) {
    ll x = 0;
    REP(j, C) {
      int d = i * C + j;
      if (d >= K) break;
      // detect d
      x += powk[j] * d;
    }
    _P(" %lld", x+1);
  }
  puts("");
}

int main() {
  int T;
  cin >> T;
  REP(i, T) {
    int K, C, S;
    cin >> K >> C >> S;
    _P("Case #%d: ", i+1);
    solve(K, C, S);
  }

  return 0;
}
