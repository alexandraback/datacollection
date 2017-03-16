#include "bits/stdc++.h"

using namespace std;

int macierz[57][57];

int n;
long long dp[57];
int sto[57];

long long check()
{
  for(int i=0; i<n; i++)
    dp[i] = 0;
  for(int i=0; i<n; i++)
    sto[i] = 0;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      if(macierz[i][j])
        sto[j]++;
  queue <int> Q;
  for(int i=0; i<n; i++)
    if(sto[i] == 0)
      Q.push(i);
  dp[0] = 1;
  int ile = 0;
  while(!Q.empty())
  {
    int v = Q.front();
    ile++;
    Q.pop();
    for(int w=0; w<n; w++)
    {
      if(macierz[v][w] == 0)
        continue;
      dp[w] += dp[v];
      sto[w]--;
      if(sto[w] == 0)
        Q.push(w);
    }
  }
  if(ile != n)
    return -1;
  return dp[n-1];
}


void test()
{
  long long m;
  cin >> n >> m;
  if(m > (1LL<<(n-2)))
  {
    cout << "IMPOSSIBLE\n";
    return;
  }
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      macierz[i][j] = (i<j) ? 1 : 0;
  if(m == (1LL<<(n-2)))
  {
    assert(check() == m);
    cout << "POSSIBLE\n";
    for(int i=0; i<n; i++)
    {
      for(int j=0; j<n; j++)
        cout << macierz[i][j];
      cout << "\n";
    }
    return;
  }
  macierz[0][n-1] = 0;
  for(int i=1; i<n-1; i++)
    if((m & (1LL<<(i-1))) == 0)
      macierz[i][n-1] = 0;
  assert(check() == m);
  cout << "POSSIBLE\n";
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
      cout << macierz[i][j];
    cout << "\n";
  }
}

int main()
{
  int t;
  cin >> t;
  for(int tti=1; tti<=t; tti++)
  {
    //cerr << tti << "\n";
    cout << "Case #" << tti << ": ";
    test();
  }
}
