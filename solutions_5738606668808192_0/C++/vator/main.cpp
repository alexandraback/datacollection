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

int mulmod(const vector<int> & v, int base, int mod) {
  int res = 0;
  for (int i = (int)v.size()-1; i >= 0; i--) {
    res = (res * base + v[i]) % mod;
  }
  return res;
}

string to_s(const vector<int> & v) {
  string s;
  for (int i = (int)v.size()-1; i >= 0; i--) {
    s += (char)('0'+v[i]);
  }
  return s;
}

vector<pair<string,vector<int> > > solve(int n, int j) {
  vector<string> V;
  vector<int> v(n,0);
  v[0] = v[n-1] = 1;
  for (int i = 1; i < n-1; i+=2) {
    v[i] = 1;
    for (int i2 = i+2; i2 < n-1; i2+=2) {
      v[i2] = 1;
      for (int i3 = 2; i3 < n-1; i3+=2) {
        v[i3] = 1;
        for (int i4 = i3+2; i4 < n-1; i4+=2) {
          v[i4] = 1;
          for (int base = 2; base <= 10; base++) {
            int mod = (base%2 ? 2 : 3);
            if (base == 6) mod = 7;
            assert(mulmod(v, base, mod) == 0);
          }
          V.push_back(to_s(v));
          v[i4] = 0;
        }
        v[i3] = 0;
      }
      v[i2] = 0;
    }
    v[i] = 0;
  }
  assert((int)V.size() >= j);
  vector<pair<string,vector<int> > > res;
  vector<int> mods;
  for (int base = 2; base <= 10; base++) {
    int mod = (base%2 ? 2 : 3);
    if (base == 6) mod = 7;
    mods.push_back(mod);
  }
  for (int i = 0; i < j; i++) {
    res.push_back(make_pair(V[i], mods));
  }
  return res;
}

int main(void) {
  int T;
  freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    int n,j;
    cin >> n >> j;
    vector<pair<string,vector<int> > > ans = solve(n, j);
    cout << "Case #" << tt+1 << ":" << endl;
    for (int i = 0; i < (int)ans.size(); i++) {
      cout << ans[i].first << " ";
      for (int i2 = 0; i2 < (int)ans[i].second.size(); i2++) {
        cout << ans[i].second[i2] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
