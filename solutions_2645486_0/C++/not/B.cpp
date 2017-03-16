#include<iostream>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

int main() {
  int t;
  cin >> t;
  rep (iii, t) {
    long long e, r, n;
    cin >> e >> r >> n;
    long long v[n];
    rep (i, n) cin >> v[i];
    long long dp[n + 1][e + 1];
    rep (i, n + 1) rep (j, e + 1) dp[i][j] = -1;
    dp[0][e] = 0;
    rep (i, n) rep (j, e + 1) rep (k, j + 1) {
      if (dp[i][j] < 0) continue;
      dp[i + 1][min(j + r - k, e)] = max(dp[i + 1][min(j + r - k, e)], dp[i][j] + k * v[i]);
    }
    long long res = 0;
    rep (i, e + 1) res = max(res, dp[n][i]);
    cout << "Case #" << iii + 1 << ": " << res << endl;
  }
  return 0;
}
