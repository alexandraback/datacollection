#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int Ti = 1; Ti <= T; Ti++) {
    int E, R, N;
    cin >> E >> R >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
      cin >> v[i];
    }

    vector<vector<int> > dp(N+1, vector<int>(E+1, -1));
    dp[0][E] = 0;
    for (int i = 0; i < N; i++) {
      for (int e = 0; e <= E; e++) {
        if (dp[i][e] != -1) {
          for (int k = 0; k <= e; k++) {
            const int ee = min(e-k+R, E);
            dp[i+1][ee] = max(dp[i+1][ee], dp[i][e] + k*v[i]);
          }
        }
      }
    }
    int ans = 0;
    for (int e = 0; e <= E; e++) {
      ans = max(ans, dp[N][e]);
    }
    cout << "Case #" << Ti << ": " << ans << endl;
  }
  return 0;
}
