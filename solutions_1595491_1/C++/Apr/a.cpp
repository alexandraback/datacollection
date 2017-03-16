#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T;
int N, S, p, t[100];
int dp[101][101];

int not_surp(int score)
{
  int a = score/3 + (score % 3 != 0);
  return a;
}

int surp(int score)
{
  if( score >= 29 ) return -1;
  if( score <= 1 ) return -1;

  int a = score/3 + (score % 3 == 2) * 2 + (score % 3 == 0) + ( score % 3 == 1 );
  return a;
}

int solve(int i, int s)
{
  if(s < 0) return -10000;
  if(i == N && s == 0) return 0;
  if(i == N) return -1000000;

  if(dp[i][s] == -1) {
    if(not_surp(t[i]) >= p)
      dp[i][s] = max(dp[i][s], solve(i+1, s) + 1);
    else
      dp[i][s] = max(dp[i][s], solve(i+1, s));
    if(surp(t[i]) >= p)
      dp[i][s] = max(dp[i][s], solve(i+1, s-1) + 1);
    if(surp(t[i]) < p && surp(t[i]) > -1)
      dp[i][s] = max(dp[i][s], solve(i, s-1));
  }
  return dp[i][s];
}

int main()
{
  scanf("%d\n", &T);
  for(int i = 1; i <= T; i++)
  {
    scanf("%d%d%d", &N, &S, &p);
    for(int j = 0; j < N; j++)
    {
      scanf("%d", t + j);
      //printf("%d: %d %d\n", t[j], not_surp(t[j]), surp(t[j]));
    }

    memset(dp, -1, sizeof(dp));
    printf("Case #%d: %d", i, solve(0, S));
    printf("\n");
  }
}

