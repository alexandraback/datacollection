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

bool ok(const string & a, const string & b) {
  for (int i = 0; i < (int)a.size(); i++) {
    if (a[i] != b[i] && b[i] != '?') return false;
  }
  return true;
}

int main(void) {
  int T;
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  cin >> T;
  int TW[4] = {1, 10, 100, 1000};
  for (int tt = 0; tt < T; tt++) {
    string sc,sj;
    string asc, asj;
    int ac = -1, aj = -1;
    int adiff = 0;
    cin >> sc >> sj;
    for (int c = 0; c < TW[sc.size()]; c++) {
      string sc2;
      int d = c;
      for (int i = 0; i < (int)sc.size(); i++) { sc2 += (char)(d%10 + '0'); d /= 10; }
      reverse(sc2.begin(), sc2.end());
      if (!ok(sc2, sc)) continue;
      for (int j = 0; j < TW[sc.size()]; j++) {
        string sj2;
        d = j;
        for (int i = 0; i < (int)sc.size(); i++) { sj2 += (char)(d%10 + '0'); d /= 10; }
        reverse(sj2.begin(), sj2.end());
        if (ok(sj2, sj)) {
          int diff = abs(c-j);
          if (ac == -1 || (diff < adiff || (diff == adiff && make_pair(c,j) < make_pair(ac, aj)))) {
            ac = c;
            aj = j;
            adiff = diff;
            asc = sc2;
            asj = sj2;
          }
        }
      }
    }
    cout << "Case #" << tt+1 << ": ";
    cout << asc << " " << asj << endl;
  }
  return 0;
}
