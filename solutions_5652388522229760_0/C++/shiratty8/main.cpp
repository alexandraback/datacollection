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

void solve(int N) {
  if (N == 0) {
    puts("INSOMNIA");
    return;
  }
  ll x = N;
  set<int> seen;
  int ret = 0;
  while (SZ(seen) < 10) {
    ll y = x;
    while (y) {
      seen.insert(y%10);
      y/=10;
    }
    //FORR(z, seen) _P("%d ", z);
    //puts("");
    x += N;
    ret++;
  }
  _P("%lld\n", x - N);
}

int main() {
  int T;
  scanf("%d", &T);
  REP(i, T) {
    int N;
    scanf("%d", &N);
    _P("Case #%d: ", i+1);
    solve(N);
  }

  return 0;
}
