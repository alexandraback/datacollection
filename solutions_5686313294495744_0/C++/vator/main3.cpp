// TEMPLATE {{{
#include <bits/stdc++.h>
using namespace std;
#ifndef LOCAL
#define OJ 1
#else
#define OJ 0
#endif

#define endl '\n'
#define TIMESTAMP merr << "Execution time: " << (double)clock()/CLOCKS_PER_SEC << " s.\n"
class C_ {}; template <typename T> C_& operator <<(C_& __m, const T& __s) { if (!OJ) cerr << "\E[91m" << __s << "\E[0m"; return __m; }
C_ merr;

struct __s { __s() { if (OJ) { ios_base::Init i; cin.sync_with_stdio(0); cin.tie(0); } } ~__s(){ TIMESTAMP; } } __S;
/// END OF TEMPLATE }}}

int main(void) {
  int T;
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    int n;
    vector<pair<string,string> > V;
    cin >> n;
    for (int i = 0; i < n; i++) {
      string a,b;
      cin >> a >> b;
      V.push_back(make_pair(a,b));
    }
    int ans = 0;
    for (int bit = 1; bit < (1<<n); bit++) {
      bool u[16] = {};
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (bit & (1<<i)) {
          u[i] = 1;
          cnt++;
        }
      }
      if (cnt <= ans) continue;
      bool ok = true;
      for (int i = 0; i < n; i++) {
        if (!u[i]) continue;
        vector<int> fa, fb;
        for (int j = 0; j < n; j++) {
          if (u[j]) continue;
          if (V[i].first == V[j].first) fa.push_back(j);
          if (V[i].second == V[j].second) fb.push_back(j);
        }
        if (fa.size() == 0 || fb.size() == 0) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ans = cnt;
      }
    }
    cout << "Case #" << tt+1 << ": ";
    cout << ans << endl;
  }
  return 0;
}
