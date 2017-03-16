#include <iostream>
using namespace std;

#define MAXN 17

pair<string, string> a[MAXN];
int n;
int dp[1<<MAXN];

bool canFake(int pos, int mask)
{
  bool firstok = false, secondok = false;
  for(int i = 0; i < n; i++)
  {
    if(i!= pos && (mask & (1<<i)) != 0)
    {
      firstok |= a[pos].first == a[i].first;
      secondok |= a[pos].second == a[i].second;
    }
  }

  return firstok && secondok;
}

int rec(int mask)
{
  if(mask == 0)
  {
    return 0;
  }
  if(dp[mask] != -1)
  {
    return dp[mask];
  }

  int i, ret = 0;
  for( i = 0; i < n; i++)
  {
    if((mask & (1 <<i)))
    {
      ret = max(ret, rec(mask ^ (1<<i)) + canFake(i, mask));
    }
  }

  return dp[mask] = ret;
}

void solve()
{
  memset(dp, -1, sizeof(dp));
  cin >> n;

  for(int i = 0; i < n; i++)
  {
    cin >> a[i].first >> a[i].second;
  }

  cout << rec((1<<n) - 1) << endl;
}

int main ()
{
  int t;
  cin >> t;

  for(int i = 1; i <= t; i++)
  {
    printf("Case #%d: ", i);
    solve();
  }

  return 0;
}
