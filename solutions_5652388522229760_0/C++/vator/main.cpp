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

void process(int x, bool* u, int& cnt) {
  while (x) {
    int d = x%10;
    x /= 10;
    if (!u[d]) {
      u[d] = 1;
      cnt++;
    }
  }
}

int main(void) {
  int T;
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    int n;
    cin >> n;
    int x = 0;
    if (n) {
      bool u[10] = {};
      int cnt = 0;
      while (cnt < 10) {
        x += n;
        process(x, u, cnt);
      }
    }
    cout << "Case #" << tt+1 << ": ";
    if (x) {
      cout << x << endl;
    } else {
      cout << "INSOMNIA" << endl;
    }
  }
  return 0;
}
