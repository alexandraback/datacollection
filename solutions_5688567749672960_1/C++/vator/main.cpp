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

// int dp[11111111];

long long rev(long long x) {
  long long res = 0;
  while (x) {
    res = res*10 + x%10;
    x /= 10;
  }
  return res;
}

int deg(long long x) {
  int cnt = 0;
  while (x) {
    cnt++;
    x /= 10;
  }
  return cnt;
}

long long clever(long long x) {
  int cnt = deg(x);
  long long ten = 1;
  if (x < 21) return x;
  if (x%10 == 0) return 1 + clever(x-1);
  for (int i = 0; i < cnt-cnt/2; i++) {
    ten *= 10;
  }
  if ((x-(x%ten-1)) == rev(x-(x%ten-1))) return x%ten-1 + 2 + clever(x-(x%ten-1) - 2);
  return x%ten-1 + 1 + clever(rev(x-(x%ten-1)));
}

int main(void) {
  // dp[1] = 1;
  // for (int i = 2; i < 11111111; i++) {
    // long long r = rev(i);
    // dp[i] = dp[i-1] + 1;
    // if (r < i && rev(r) == i) dp[i] = min(dp[i], dp[r]+1);
  // }
  // for (int i = 1; i < 55; i++) {
    // merr << i << "\t" << dp[i] << '\n';
    // if (dp[i] <= dp[i-1]) {
      // merr << i-1 << "\t" << dp[i-1] << '\n';
      // merr << i << "\t" << dp[i] << '\n';
    // }
  // }
  // for (int i = 1; i < 11111111; i++) {
    // if (dp[i] != clever(i)) {
      // merr << "EREOROEO!" << '\n';
      // merr << i << " " << dp[i] << " " << clever(i) << '\n';
      // cin.get();
    // }
  // }
  // return 0;
  int T;
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    long long n;
    cin >> n;
    cout << "Case #" << tt+1 << ": " << clever(n) << endl;
  }
  return 0;
}
