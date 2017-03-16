#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long llong;

int flags[10000001];

int bfs(int n)
{
  memset(flags, -1, sizeof(flags));
  queue<int> qu;
  flags[1] = 1;
  qu.push(1);
  while(!qu.empty())
  {
    int now = qu.front();
    qu.pop();
    if(now == n)
      return flags[n];
    if(flags[now + 1] < 0)
    {
      flags[now + 1] = flags[now] + 1;
      qu.push(now + 1);
    }
    int target = 0;
    for(int tmp = now; tmp != 0; tmp /= 10)
      target = target * 10 + tmp % 10;
    if(target <= 10000000 && flags[target] < 0)
    {
      flags[target] = flags[now] + 1;
      qu.push(target);
    }
  }
  return -1;
}

int main()
{
  int T = 0;
  scanf("%d", &T);
  for(int Case = 1; Case <= T; ++Case)
  {
    int n = 0;
    scanf("%d", &n);
    int ans = bfs(n);
    printf("Case #%d: %d\n", Case, ans);
  }
  return 0;
}
