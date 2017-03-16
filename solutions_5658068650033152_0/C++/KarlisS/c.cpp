#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

char s[32][32];
static const int dx[]={1, -1, 0, 0};
static const int dy[]={0, 0, -1, 1};

static int dfs(int x, int y)
{
  if (s[y][x])return 0;
  int ans = 1;
  s[y][x] = 1;
  for (int j=0; j<4; j++)
  {
    int tx = x+dx[j];
    int ty = y+dy[j];
    ans += dfs(tx, ty);
  }
  return ans;
}

static bool test(int n, int m, int k, int mask)
{
  int cnt =n*m;
  for (int i=1; i<=m; i++)
  for (int j=1; j<=n; j++)
  {
    s[i][j] = mask&1;
    mask /= 2;
  }
  for (int i=1; i<=n; i++) {
      cnt -= dfs(i, 1);
      cnt -= dfs(i, m);
  }
  for (int i=1; i<=m; i++)
  {
    cnt -= dfs(1, i);
    cnt -= dfs(n, i);
  }
  return (cnt >= k);
}

int solve(int n, int m, int k)
{
  memset(s, 1, sizeof(s));
  int ans = k;
  int sz=n*m;
  for (int i=0; i<(1<<sz); i++)
  {
    if (__builtin_popcount(i) < ans) {
      if (test(n, m, k, i))ans = __builtin_popcount(i);
    }
  }
  return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++)
    {
        int n, m, k;
        scanf("%d %d %d",&n,&m,&k);
        printf("Case #%d: %d\n", i, solve(n, m, k));
    }
}
