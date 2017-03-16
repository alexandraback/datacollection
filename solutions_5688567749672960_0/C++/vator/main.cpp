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

int dp[1111111];

int rev(int x) {
  int res = 0;
  while (x) {
    res = res*10 + x%10;
    x /= 10;
  }
  return res;
}

int main(void) {
  dp[1] = 1;
  for (int i = 2; i <= 1000000; i++) {
    int r = rev(i);
    dp[i] = dp[i-1] + 1;
    if (r < i && rev(r) == i) dp[i] = min(dp[i], dp[r]+1);
  }
  int T;
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    int n;
    cin >> n;
    cout << "Case #" << tt+1 << ": " << dp[n] << endl;
  }
  return 0;
}
