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

void solve(string& s) {
  int len = SZ(s);
  int ans = 0;
  FOR(i, 1, len) {
    if (s[i] != s[i-1]) {
      ans++;
    }
  }
  if (s[len-1] == '-') ans++;
  _P("%d\n", ans);

}

int main() {
  int T;
  cin >> T;
  REP(i, T) {
    string s;
    cin >> s;
    _P("Case #%d: ", i+1);
    solve(s);
  }

  return 0;
}
