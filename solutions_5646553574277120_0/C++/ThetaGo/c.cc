#include <iostream>
#include <stdint.h>
#include <cstring>
using namespace std;

// const int64_t SIZE = 1000000001;
#define SIZE 10001
bool all_true(bool* b, int64_t n, int64_t* min_val)
{
  for (int64_t i = 0; i < n; ++i) {
    if (b[i] == false) {
      *min_val = i;
      return false;
    }
  }
  return true;
}

int main()
{
  // cout << "ttt" << endl;
  int T;
  cin >> T;
  // cout << T << endl;
  for (int t = 0; t < T; ++t) {
    // cout << t << endl;
    int64_t old_vals[100];
    // int64_t ans;
    int64_t c, v, d;
    cin >> c >> d >> v;
    // cout << "~" << endl;
    bool dp[SIZE];
    memset(dp, 0, sizeof(dp));
    int used_coins[SIZE];

    // cout << "?..?" << endl;

    for (int64_t i = 0; i < d; ++i) {
      cin >> old_vals[i];
    }

    // cout << "?? "<< endl; 
    // int64_t ans = 0;
    dp[0] = true;
    for (int64_t i = 0; i < d; ++i) {
      memset(used_coins, 0, sizeof(used_coins));
      int64_t val = old_vals[i];
      for (int64_t j = val; j <= v; ++j) {
        if (dp[j] == false && dp[j-val] == true && used_coins[j-val] < c) {
          dp[j] = true;
          used_coins[j] = used_coins[j-val] + 1;
        }
      }
    }

    int64_t ans = 0;
    int64_t min_val;
    while (!all_true(dp, v+1, &min_val)) {
      ++ans;
      memset(used_coins, 0, sizeof(used_coins));
      for (int64_t i = min_val; i <= v; ++i) {
        if (dp[i] == false && dp[i-min_val] == true && used_coins[i-min_val] < c) {
          dp[i] = true;
          used_coins[i] = used_coins[i-min_val] + 1;
        }
      }
    }

    cout << "Case #" << t+1 << ": " << ans << endl;
  }
  return 0;
}