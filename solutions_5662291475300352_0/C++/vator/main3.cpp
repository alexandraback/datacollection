#include <bits/stdc++.h>

using namespace std;

// TEMPLATE {{{
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
    long long start[11], speed[11];
    int idx = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int st, cnt, m;
      cin >> st >> cnt >> m;
      for (int j = 0; j < cnt; j++) {
        start[idx] = st;
        speed[idx] = m+j;
        idx++;
      }
    }
    cout << "Case #" << tt+1 << ": ";
    if (idx < 2) {
      cout << "0" << endl;
      continue;
    }
    if (speed[0] == speed[1]) {
      cout << "0" << endl;
      continue;
    }
    if (speed[0] < speed[1]) {
      swap(start[0], start[1]);
      swap(speed[0], speed[1]);
    }
    if ((360-start[0])*speed[0] >= (720-start[1])*speed[1]) {
      cout << "1" << endl;
    } else {
      cout << "0" << endl;
    }
  }
  return 0;
}
