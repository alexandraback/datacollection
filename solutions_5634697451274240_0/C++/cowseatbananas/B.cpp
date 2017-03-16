#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;

int T, N;
int dp[101][2];
char S[101];

int main() {
  scanf("%d", &T);
  REP (t, T) {
    scanf("%s", S);
    N = strlen(S);

    dp[0][0] = dp[0][1] = 0;
    int pre;
    FOR (i, N) {
      if (!i || S[i] != S[i - 1]) pre = i;
      bool p = S[i] == '+';
      dp[i + 1][p] = dp[pre][p];
      dp[i + 1][!p] = dp[pre][p] + 1;
    }

    printf("Case #%d: %d\n", t, dp[N][1]);
  }
  return 0;
}
