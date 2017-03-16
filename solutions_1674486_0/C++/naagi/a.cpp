#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MaxN = 1111;

int u[MaxN];

//vector <vector <int> > g;
int g[MaxN][MaxN];
int nres;

void dfs (int i)
{
  int j;
  u[i] = 1;
  for (j = 1; j <= g[i][0]; j++)
  {
    if (u[g[i][j]] == 1)
    {
      nres = 1;
//      cout << g[i][j] << '\n';
    }
    else
      dfs (g[i][j]);
  }
}
              
int main (void)
{
  int test, tests;
  char res[][10]  = {"No", "Yes"};

  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {
    int i, j, n, m, a;
    scanf ("%d", &n);
//    g.clear();
//    g.resize(n);
    for (i = 1; i <= n; i++)
    {
      scanf ("%d", &m);
      g[i][0] = m;
      for (j = 1; j <= m; j++)
        scanf ("%d", &a),
        g[i][j] = a;
    }
    nres = 0;
    for (i = 1; i <= n; i++)
    {
      memset (u, 0, sizeof(u));
      dfs (i);
    }
          
    printf ("Case #%d: %s\n", test + 1, res[nres]);
    
  }
  return 0;
}
