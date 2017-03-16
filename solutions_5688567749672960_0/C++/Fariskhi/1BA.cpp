#include <bits/stdc++.h>
using namespace std;

// O(N) Solution

int reverse(int x) {
  int res = 0;
  while (x) {
    int digit = x % 10;
    res = res * 10 + digit;
    x /= 10;
  }
  return res;
}

int main() {
  int tc;
  scanf("%d", &tc);

  int dp[1000005];
  memset(dp, 0, sizeof(dp));

  dp[0] = 0;
  for (int i = 1; i <= 1000000; i++) {
    int reversedNumber = reverse(i);
    if (dp[i] == 0) dp[i] = dp[i-1] + 1;
    dp[i] = min(dp[i], dp[i-1] + 1);
    if (reversedNumber > i) {
      dp[reversedNumber] = dp[i] + 1;
    }
  }

  for (int tcNumber = 1; tcNumber <= tc; tcNumber++) {
    int n;
    scanf("%d", &n);
    printf("Case #%d: %d\n", tcNumber, dp[n]);
  }
}
