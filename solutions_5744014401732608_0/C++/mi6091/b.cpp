#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n, m;

bool isPrime(int pos)
{
  for(int i = 2; i*i <= pos; i++)
  {
    if(pos%i == 0)
    {
      return false;
    }
  }
  return true;
}

int a[8][8];
int dp[10];

void makeDP()
{
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  int i, j;
  for(i = 1; i < n; i++)
  {
    for(j = 0; j < i; j++)
    {
      if(a[j][i])
      {
        dp[i] += dp[j];
      }
    }
  }
}

void printresult()
{
  cout << "POSSIBLE" << endl;

  int i, j;
  for(i = 0; i < n; i++)
  {
    for(j=0; j< n; j++)
    {
      cout << a[i][j];
    }
    cout << endl;
  }

}
void solve()
{
  cin >> n >> m;

  vector<pair<int, int> > e;

  int i, j;
  for(i = 0; i < n; i++)
  {
      for(j = i+1; j < n; j++)
      {
        e.push_back(make_pair(i, j));
      }
  }

  int k = e.size();

  int mask;
  for(mask = 0; mask < (1<<k); mask++)
  {
    memset(a, 0, sizeof(a));
    for(i = 0; i < k; i++)
    {
      if(mask&(1<<i))
      {
        a[e[i].first][e[i].second] = 1;
      }
    }

    makeDP();

    if(dp[n - 1] == m)
    {
      printresult();
      return;
    }
  }
  cout << "IMPOSSIBLE" <<endl;
}
int main()
{
  int t;
  scanf("%d", &t);

  for(int i = 1; i<=t; i++)
  {
    printf("Case #%d: ", i);
    solve();
  }
  return 0;
}
