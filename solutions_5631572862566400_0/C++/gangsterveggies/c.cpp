#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

#define F first
#define S second

int next[2000];
vector<int> prev[2000];
int bout[2000];
int vis[2000];
int mark[2000];
int cycle, nc = 0;
vector<int> lc[2000];

int calc_prev(int cur, int forb)
{
  if (bout[cur] != -1)
    return bout[cur];

  int bs = 0, i;
  for (i = 0; i < (int)prev[cur].size(); i++)
    if (prev[cur][i] != forb)
      bs = max(bs, calc_prev(prev[cur][i], forb));

  return bout[cur] = 1 + bs;
}

void cycle_next(int cur, int ini)
{
  if (vis[cur] == ini)
  {
    if (ini == cur)
    {
      cycle = 1;
      nc++;
      return;
    }

    return;
  }
  vis[cur] = ini;

  cycle_next(next[cur], ini);
  if (cycle)
  {
    mark[cur] = 1;
    lc[nc].push_back(cur);
  }
}

int main()
{
  int t, T, n;
  scanf("%d", &T);

  for (t = 1; t <= T; t++)
  {
    memset(bout, -1, sizeof bout);
    memset(vis, -1, sizeof vis);
    memset(mark, 0, sizeof mark);

    int i, j;
    scanf("%d", &n);

    for (i = 0; i < nc; i++)
      lc[i].clear();

    for (i = 0; i < n; i++)
      prev[i].clear();

    for (i = 0; i < n; i++)
    {
      scanf("%d", &next[i]);
      next[i]--;
      prev[next[i]].push_back(i);
    }

    nc = -1;
    for (i = 0; i < n; i++)
      if (!mark[i])
      {
        cycle = 0;
        cycle_next(i, i);
        if (cycle)
          reverse(lc[nc].begin(), lc[nc].end());
      }
    nc++;

/*    for (i = 0; i < nc; i++)
    {
      int sz = (int)lc[i].size();
      for (j = 0; j < sz; j++)
        printf("%d ", lc[i][j]);
      printf("\n");
      }*/

    int ansg = 0;
    int anst = 0;
    for (i = 0; i < nc; i++)
    {
      int sz = (int)lc[i].size();
      ansg = max(ansg, sz);
      if (sz == 2)
      {
        int tmp = calc_prev(lc[i][0], lc[i][1]) + calc_prev(lc[i][1], lc[i][0]);
        anst += tmp;
      }
    }

    printf("Case #%d: %d\n", t, max(ansg, anst));
  }
  
  return 0;
}
