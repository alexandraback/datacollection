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

long long p10[100];
long long power10[100];

long long solve(long long N) {
  if (N < 10) return N;
  if (!(N % 10)) return solve(N - 1) + 1;
  long long _N = N;
  vector<int> digits;
  while (N) { digits.push_back(N % 10); N /= 10; } N = _N;
  int D = digits.size();
  long long best = power10[D - 1] + N - p10[D - 1];
  FOR(cut, 1, D - 1) {
    long long ans = power10[D - 1];
    long long tmp = 0;
    FORD(i, cut - 1, 0) tmp = 10 * tmp + digits[i];
    ans += tmp;
    reverse(digits.begin(), digits.end());
    tmp = 0;
    FORD(i, D - cut - 1, 0) tmp = 10 * tmp + digits[i];
    ans += tmp;
    reverse(digits.begin(), digits.end());
    best = min(best, ans);
  }
  return best;
}
/*
#define MAXN 1111111
long long dp[MAXN];
long long solve2(long long N) { return dp[N]; }
*/

int main(int argc, char *argv[]) {
  /*
  dp[1] = 1;
  FOR(i, 2, MAXN - 1) {
    dp[i] = dp[i - 1] + 1;
    if (i % 10) {
      long long ii = i, ans = 0;
      while (ii) { ans = 10 * ans + ii % 10; ii /= 10; }
      if (ans < i) dp[i] = min(dp[i], dp[ans] + 1);
    }
  }
  */
  p10[0] = 1; REP(i, 99) p10[i + 1] = p10[i] * 10;
  power10[0] = 1; power10[1] = 10;
  FOR(i, 2, 99) power10[i] = power10[i - 1] + p10[i / 2] + p10[(i + 1) / 2] - 1;
  // REP(i, 10) printf("%lld\n", power10[i]);

  int T;
  scanf("%d", &T);
  FOR(t, 1, T) {
    long long N;
    scanf("%lld", &N);
    printf("Case #%d: %lld\n", t, solve(N));
  }
  return 0;
}
