#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
string s;

const int MAXN = 1111111;

long long dp[MAXN];

int main() {
  int cases;
  scanf("%d", &cases);
  for (int T = 1; T <= cases; ++T) {
    long long n;
    scanf("%lld", &n);
    long long ans = 0;
    // while (n) {
    //   s = to_string(n);
    //   reverse(s.begin(), s.end());
    //   long long nn = stoi(s);
    //   if (nn < n - 1) {
    //     n = nn;
    //   } else {
    //     n = n - 1;
    //   }
    //   ++ans;
    // }
    dp[0] = 0;
    for (long long i = 1; i <= n; ++i) {
      s = to_string(i);
      reverse(s.begin(), s.end());
      long long ii = stoi(s);
      // printf("%lld %lld\n", i, ii);
      dp[i] = dp[i - 1] + 1;
      if (i % 10 && ii < i) {
        dp[i] = min(dp[i], dp[ii] + 1);
      }
    }
    printf("Case #%d: %lld\n", T, dp[n]);
  }
}