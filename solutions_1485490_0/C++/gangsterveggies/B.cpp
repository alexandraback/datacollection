#include <stdio.h>

struct node
{
  int val;
  long long int qt;
} typedef node;

node alist [102], blist [102];
int N, M;
long long int mx;

long long int min(long long int a, long long int b)
{
  return (a < b) ? a : b;
}

void dfs(int cn, int cm, long long int cost, long long int qn, long long int qm)
{
  if (cn == N || cm == M)
  {
    if (cost > mx)
      mx = cost;
    return;
  }
  if (alist[cn].val == blist[cm].val)
  {
    long long int nqn, nqm;
    int sn = 0, sm = 0;
    if (qn > qm)
    {
      nqn = qn - qm;
      nqm = blist[cm + 1].qt;
      sm = 1;
    }
    if (qn < qm)
    {
      nqm = qm - qn;
      nqn = alist[cn + 1].qt;
      sn = 1;
    }
    if (qn == qm)
    {
      nqn = alist[cn + 1].qt;
      nqm = blist[cm + 1].qt;
      sm = 1;
      sn = 1;
    }
    dfs(cn + sn, cm + sm, cost + min(qn, qm), nqn, nqm);
  }
  else
  {
    dfs(cn + 1, cm, cost, alist[cn + 1].qt, qm);
    dfs(cn, cm + 1, cost, qn, blist[cm + 1].qt);
  }
}

int main()
{
  int t, T, i;
  scanf("%d", &T);
  for (t = 0; t < T; t++)
  {
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++)
      scanf("%lld %d", &alist[i].qt, &alist[i].val);
    for (i = 0; i < M; i++)
      scanf("%lld %d", &blist[i].qt, &blist[i].val);
    mx = 0;
    dfs(0, 0, 0L, alist[0].qt, blist[0].qt);
    printf("Case #%d: %lld\n", t + 1, mx);
  }
  return 0;
}

