#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 13;
const int M = 13;
typedef vector<int> vi;
#define pb push_back

int dp[N][M], n, e, r;
vi m;

void init()
{
  memset(dp, -1, sizeof(dp));
  cin>>e>>r>>n;
  m = vi(n);
  for(int i = 0; i < n; i++)
  {
    cin>>m[i];
  }
}

int cal(int p, int t)
{
  if(dp[p][t] != -1)
  {
    return dp[p][t];
  }
  if(p >= n) return 0;
  int Max = 0;
  for(int i = 0; i <= t; i++)
  {
    int tmp = m[p] * i;
    tmp += cal(p + 1, min(t - i + r, e));
    Max = max(Max, tmp);
  }
  return dp[p][t] = Max;
}

void solve(int tcase)
{
  int res = cal(0, e);
  /*for(int i = 0; i < n; i++)
  {
    for(int j = 0; j <= e; j++)
    {
      printf("%d ", dp[i][j]);
    }
    printf("\n");
  }*/
  printf("Case #%d: %d\n", tcase, res);
}

int main()
{
  int T;
  cin>>T;
  for(int i = 1; i <= T; i++)
  {
    init();
    solve(i);
  }
}