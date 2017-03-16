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


void solve() {
  string in;
  cin >> in;

  map<char, int> S;
  FORR(c, in) {
    S[c]++;
  }

  map<int, int> ans;

  if (S['X']) {
    int x = S['X'];
    ans[6] = x;
    S['S'] -= x;
    S['I'] -= x;
    S.erase('X');
  }

  if (S['Z']) {
    int z = S['Z'];
    ans[0] = z;
    S.erase('Z');
    S['E'] -= z;
    S['R'] -= z;
    S['O'] -= z;
  }

  if (S['W']) {
    int n = S['W'];
    ans[2] = n;
    S['T'] -= n;
    S.erase('W');
    S['O'] -= n;
  }

  if (S['U']) {
    int n = S['U'];
    ans[4] = n;
    S['F'] -= n;
    S['O'] -= n;
    S.erase('U');
    S['R'] -= n;
  }

  if (S['S']) {
    int n = S['S'];
    ans[7] = n;
    S.erase('S');
    S['E'] -= n;
    S['V'] -= n;
    S['E'] -= n;
    S['N'] -= n;
  }

  if (S['G']) {
    int n = S['G'];
    ans[8] = n;
    S['E'] -= n;
    S['I'] -= n;
    S.erase('G');
    S['H'] -= n;
    S['T'] -= n;
  }

  if (S['R']) {
    int n = S['R'];
    ans[3] = n;
    S['T'] -= n;
    S['H'] -= n;
    S.erase('R');
    S['E'] -= n;
    S['E'] -= n;
  }

  if (S['O']) {
    int n = S['O'];
    ans[1] = n;
    S.erase('O');
    S['N'] -= n;
    S['E'] -= n;
  }

  ans[5] = S['V'];
  ans[9] = S['E'] - S['V'];

  string s;
  FORR(nm, ans) {
    int n = nm.first;
    int m = nm.second;
    //_P("%d,%d\n", n,m);
    REP(i, m) s += ('0' + n);
  }
  cout << s << endl;
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
