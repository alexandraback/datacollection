#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;

const int MAXN = 105;
char buf[MAXN];

ll solve(char *S, int L) {
  vector<ll> dp(L);
  if (S[L-1] == '-') dp[L-1] = 1;
  for (int i = L-2; i >= 0; --i) {
    if (S[i] == S[i+1]) dp[i] = dp[i+1];
    else dp[i] = 1 + dp[i+1];
  }
  return dp[0];
}

int main() {
  int T;
  scanf("%d",&T);
  for (int i = 1; i <= T; ++i) {
    scanf("%s",buf);
    printf("Case #%d: %lld\n", i, solve(buf,strlen(buf)));
  }
  return 0;
}
