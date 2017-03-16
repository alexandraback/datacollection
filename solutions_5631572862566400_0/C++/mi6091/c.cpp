#include <iostream>
using namespace std;

int a[1024][1024];
int b[1024];
int n;

int used[1024];
int path[1024];
int where[1024];
int cycle[1024];
int dp[1024];

int maxCycle = 0;

void markCycle(int pos, int w)
{
  int temp = pos;

  do
  {
    cycle[temp] = w;
    temp = b[temp];
  }
  while(temp != pos);

}
void dfs(int pos, int br)
{
  used[pos] = 1;
  path[pos] = br;

  int i;
  for(i = 1; i <= n; i++)
  {
    if(!a[pos][i]) continue;

    if(!used[i])
    {
      dfs(i, br + 1);
    }
    else
    if(used[i] == 1)
    {
      int cycleSize = br - path[i] + 1;
      maxCycle = max(maxCycle, cycleSize);
      markCycle(pos, cycleSize);
    }
  }
  used[pos] = 2;
}

int dfs2(int pos)
{
  used[pos] = 1;
  int ret = 1;

  for(int i = 1; i <= n; i++)
  {
    if(a[pos][i] && !used[i] && cycle[i] == 0)
    {
      ret = max(ret, dfs2(i) + 1);
    }
  }

  return ret;
}
int solve()
{
  memset(used, 0, sizeof(used));
  memset(a, 0, sizeof(a));
  memset(dp, 0, sizeof(dp));
  memset(path, 0, sizeof(path));
  memset(cycle, 0, sizeof(cycle));

  maxCycle = 0;

  cin >> n;
  int i, j;
  for(i = 1; i <= n; i++)
  {
    int k;
    cin >> k;
    a[i][k] = 1;
    b[i] = k;
  }

  for(i = 1; i <= n; i++)
  {
    if(!used[i])
    {
      dfs(i, 0);
    }
  }

  for(i = 1; i<= n; i++)
  {
    if(cycle[i] > 2)
    {
      a[i][b[i]] = 0;
    }
  }

  for(i = 1; i <= n; i++)
    for(j = 1; j <= i; j++)
    {
      swap(a[i][j], a[j][i]);
    }

  memset(used, 0, sizeof(used));
  for(i = 1; i <= n; i++)
  {
    if(cycle[i] == 2)
    {
      dp[i] = dfs2(i);
    }
  }

  int res = maxCycle;
  int br2 = 0;
  for(i = 1; i <= n; i++)
  {
    if(cycle[i] == 2 && cycle[b[i]] == 2 && i < b[i])
    {
      br2 += dp[i] + dp[b[i]];
      res = max(res, dp[i] + dp[b[i]]);
    }
  }

  res = max( res, br2);
  return res;
}


int main ()
{
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++)
  {
    printf("Case #%d: %d\n", i, solve());
  }

  return 0;
}
