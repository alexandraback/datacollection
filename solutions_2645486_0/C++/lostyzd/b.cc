#include <iostream>
#include <cstring>

int main() {
  int T;
  std::cin >> T;
  for (int test = 1; test <= T; ++test) {
    int E, R, N;
    std::cin >> E >> R >> N;
    int value[10000];
    for (int i = 0; i < N; ++i) std::cin >> value[i];

    long long ans = 0;
    if (E <= R) {
      for (int i = 0; i < N; ++i) {
        ans += E * value[i];
      }
    } else {
      long long dp[1000][100];
      memset(dp, 0, sizeof dp);
      for (int j = R; j <= E; ++j) dp[0][j] = (E + R - j) * value[0];
      for (int i = 1; i < N; ++i) {
        for (int j = R; j <= E; ++j) {
          long long tmp = dp[i - 1][j];
          for (int k = j - R; k <= E; ++k) {
            tmp = std::max(tmp, dp[i - 1][k] + (k + R - j) * value[i]);
          }
          dp[i][j] = tmp;
        }
      }

      for (int j = 0; j <= E; ++j) {
        if (dp[N - 1][j] > ans) ans = dp[N - 1][j];
      }
    }

    std::cout << "Case #" << test << ": " << ans << std::endl;
  }
}
