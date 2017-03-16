#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

#define endl "\n"
#define all(x) x.begin(), x.end()

void solve()
{
  int n;
  cin >> n;
  vector <int> dp(n + 1, (int) 1e9);
  dp[1] = 1;

  for (int i = 1; i < n; i++) {
    if (dp[i] < (int) 1e9) {
      dp[i + 1] = min(dp[i + 1], dp[i] + 1);
      int x = 0;
      int y = i;
      while (y) {
        x *= 10;
        x += y % 10;
        y /= 10;
      }
      if (x <= n) {
        dp[x] = min(dp[x], dp[i] + 1);
      }
    }
  }
  cout << dp[n] << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int test_cases;
  cin >> test_cases;

  for (int t = 1; t <= test_cases; t++) {
    cout << "Case #" << t << ": ";
    solve();
  }

  return 0;
}
