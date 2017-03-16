#include <cstdio>
#include <cassert>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int MaxN = 55;
int g[MaxN][MaxN];
int gold[MaxN];
string zip[MaxN];
int p[MaxN], u[MaxN], u1[MaxN];

int n;

int f (int i, int j)
{
  return zip[i] < zip[j];
}

void dfs (int v)
{
  int i;
  u1[v] = 1;
  for (i = 0; i < n; i++)
    if (g[v][i] && u1[i] == 0)
      dfs (i);
}

void dfs1 (int v)
{
  int i;
  u1[v] = 1;
  if (u[v])
    for (i = 0; i < n; i++)
      if (g[v][i] && u1[i] == 0)
        dfs1 (i);
}
              
int main (void)
{
  int test, tests;

  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {
    string res;
    int m, a, b, i, j, k, cur;
    scanf (" %d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
      cin >> zip[i], 
      p[i] = i;
    }
    sort (p, p + n, f);
    memset (g, 0, sizeof(g));
    for (j = 0; j < m; j++)
    {
      scanf ("%d %d", &a, &b);
      a--, b--;
      g[a][b] = g[b][a] = 1;
    }
    memset (u, 0, sizeof(u));
    u[p[0]] = 1;
    res = zip[p[0]];
    cur = p[0];
    for (i = 1; i < n; i++)
    {
      for (j = 0; j < n; j++)
      {
        if (u[p[j]] == 0)
        {
          //try to go there
          int ok = 0;
          if (g[cur][p[j]])
          {
            ok = 1;
          }
          else
          {
            for (k = 0; k < n; k++)
            {
              gold [k] = g[cur][k];
              g[cur][k] = 0;
            }
            memset (u1, 0, sizeof(u1));
            dfs (p[0]);
            for (k = 0; k < n; k++)
              if (u[k] == 0 && u1[k] == 0)
                break;
            if (k == n)
            {
              memset (u1, 0, sizeof(u1));              
              dfs1 (p[0]);
              if (u1[p[j]] == 1)
                ok = 1;
            }
            if (!ok)
              for (k = 0; k < n; k++)
                g[cur][k] = gold [k];
          }
//          printf ("%d %d %d\n", cur, p[j], ok);
          if (ok)
          {
            u[p[j]] = 1;
            res += zip[p[j]];
            cur = p[j];
            break;
          }
        }
      }
    }
    assert (res.size() == n * 5);
    printf ("Case #%d: %s\n", test + 1, res.c_str());
  }
  return 0;
}
