#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
#define pb push_back
const int N = 1010;
int t;
vector <int> g[N];
bool used[N], res;
int n, k, x;
void dfs(int v)
{
  used[v] = true;
  for(int i = 0; i < (int)g[v].size(); i++)
  {
    int to = g[v][i];
    if (used[to])
      res = true;
    else
      dfs(to);
  }
}
int main()
{
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("O.txt", "w", stdout);
  cin >> t;
  for(int q = 0; q < t; q++)
  {
    cin >> n;
    for(int i = 0; i < n; i++)
    {
      cin >> k;
      g[i + 1].clear();
      for(int j = 0; j < k; j++)
      {
        cin >> x;
        g[i + 1].pb(x);
      }
    }
    res = false;
    for(int i = 1; i <= n; i++)
    {
      for(int j = 1; j <= n; j++)
        used[j] = false;
      dfs(i);
    }
    cout << "Case #" << q + 1 << ": ";
    if (res)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
