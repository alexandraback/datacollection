#include "bits/stdc++.h"

using namespace std;

int n;
int macierz[20][20];
vector <int> G[20];
int sto[20], dp[20];

int check()
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
  int m;
  cin >> n >> m;
  if(m > (1<<(n-2)))
  {
    cout << "IMPOSSIBLE\n";
    return;
  }
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      macierz[i][j] = 0;
  for(int mas=0; mas<(1<<((n-1)*(n-1))); mas++)
  {
    int e = 0;
    for(int i=0; i<n-1; i++)
      for(int j=0; j<n; j++)
      {
        if(i == j)
          continue;
        if(mas & (1<<e))
          macierz[i][j] = 0;
        else
          macierz[i][j] = 1;
        e++;
      }
    if(check() == m)
    {
      cout << "POSSIBLE\n";
      for(int i=0; i<n; i++)
      {
        for(int j=0; j<n; j++)
          cout << macierz[i][j];
        cout << "\n";
      }
      return;
    }
  }
  cout << "IMPOSSIBLE\n";
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
