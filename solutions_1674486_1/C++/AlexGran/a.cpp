#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

#define sz(a) (int)(a.size())

int used[2000];
vector <int> g[2000];

bool check (int v)
{  
  used[v] = 1;
  bool res = 0;

  for (int i = 0; i < sz(g[v]); i++)
  {
    if (used[g[v][i]])
      res = true;
    else
      res = max(res, check(g[v][i]));
  }    
  return res;
      
}

void solve (int tst_num)
{ 
  int n;
  
  scanf ("%d", &n);

  for (int i = 1; i <= n; i++)
  {
    int m;
    g[i].clear();
    scanf ("%d", &m);

    for (int j = 0; j < m; j++)
    {
      int u;
      scanf ("%d", &u);
      g[i].push_back(u);
    }
  }
  for (int i = 1; i <= n; i++)
  {
    memset(used, 0, sizeof(used));
    if (check(i))
    {
      printf ("Case #%d: Yes\n", tst_num);
      return;
    }
  }
  printf ("Case #%d: No\n", tst_num);
}

int main (void)
{
  freopen ("input.txt", "rt", stdin);
  freopen ("output.txt", "wt", stdout);

  int T;

  scanf ("%d", &T);

  for (int i = 1; i <= T; i++)
    solve(i);

  return 0;
}

