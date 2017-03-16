#include <iostream>

using namespace std;

const int z = -10000000;

int dp[100][100], v[100];

int main() {
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  int E, R, N;
  for (int i = 0; i < T; ++i) {
    cin >> E >> R >> N;
    for (int j = 0; j < N; ++j)
      cin >> v[j];
    for (int j = 0; j <= N; ++j)
      for (int k = 0; k <= E; ++k)
        dp[j][k] = z;
    dp[0][E] = 0;
    for (int j = 0; j < N; ++j)
      for (int k = 0; k <= E; ++k)
        for (int a = 0; a <= k; ++a)
          if (dp[j][k] + a * v[j] > dp[j + 1][min(E, k - a + R)])
             dp[j + 1][min(E, k - a + R)] = dp[j][k] + a * v[j]; 
    int ans = 0;
    for (int k = 0; k <= E; ++k)
      ans = max(ans, dp[N][k]);
    cout << "Case #" << (i + 1) << ": " << ans << '\n';
  }
  return 0;
}
