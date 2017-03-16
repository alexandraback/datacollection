/* Written by Filip Hlasek 2015 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

long long solve(long long N) {
  if (N < 10) return N;
  long long _N = N;
  vector<int> digits;
  while (N) { digits.push_back(N % 10); N /= 10; } N = _N;
  int D = digits.size();
  long long m = 1, ans = 0;
  REP(i, D - 1) { ans += 9 + m; m *= 10; }
  reverse(digits.begin(), digits.end());
  if (N == m * digits[0] && digits[0] != 1) { N--; digits[0]--; ans++; }
  if (digits[0] == 1) ans += N - m;
  if (digits[0] != 1 && D > 1) ans += digits[0] + N - m * digits[0];
  return ans;
}

#define MAXN 1111111
long long dp[MAXN];
long long solve2(long long N) { return dp[N]; }

int main(int argc, char *argv[]) {
  dp[1] = 1;
  FOR(i, 2, MAXN - 1) {
    dp[i] = dp[i - 1] + 1;
    if (i % 10) {
      long long ii = i, ans = 0;
      while (ii) { ans = 10 * ans + ii % 10; ii /= 10; }
      if (ans < i) dp[i] = min(dp[i], dp[ans] + 1);
    }
  }
  int T;
  scanf("%d", &T);
  FOR(t, 1, T) {
    long long N;
    scanf("%lld", &N);
    printf("Case #%d: %lld\n", t, solve2(N));
  }
  return 0;
}
