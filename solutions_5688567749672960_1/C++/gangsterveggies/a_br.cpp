#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

typedef long long int lld;
typedef pair<int, int> pii;
typedef pair<pii, pii> line;

#define F first
#define S second

int done[11000001];
lld po[30];

lld rev(lld cur)
{
  lld tmp = 0;
  while (cur)
  {
    tmp *= 10;
    tmp += cur % 10;
    cur /= 10;
  }

  return tmp;
}

int len(lld vl)
{
  int tmp = 0;
  while (vl)
  {
    tmp++;
    vl /= 10;
  }

  return tmp;
}

int calc(lld cur)
{
//  printf("%lld\n", cur);
  if (cur <= 101)
    return done[cur];
  if (((cur - 1 + 10) % 10) == 0)
  {
    if (cur <= rev(cur))
      return 1 + calc(cur - 1);
    return 1 + calc(rev(cur));
  }

  return ((cur - 1 + 10) % 10) + calc(cur - ((cur - 1 + 10) % 10));
}

lld calc2(lld cur)
{
//  printf("%lld\n", cur);
  if (cur <= 100000)
    return done[cur];

  lld pot = po[1 + max(0, len(cur) / 2 - 1)];

  if (((cur - 1 + pot) % pot) == 0)
  {
    if (cur <= rev(cur))
      return 1 + calc2(cur - 1);
    return 1 + calc2(rev(cur));
  }

  return ((cur - 1 + pot) % pot) + calc2(cur - ((cur - 1 + pot) % pot));
}

int main()
{
  int i;
  int t, T;

  memset(done, 0, sizeof done);
  queue<pii> q;
  q.push(pii(1, 1));
  done[1] = 1;
  while (!q.empty())
  {
    pii nx = q.front();
    q.pop();

    int suc = nx.F + 1;
    if (suc < 11000001 && !done[suc])
    {
      //printf("%d -> %d (%d)\n", suc, nx.F, nx.S + 1);
      done[suc] = nx.S + 1;
      q.push(pii(suc, nx.S + 1));
    }

    suc = rev(nx.F);
    if (suc < 11000001 && !done[suc])
    {
      //printf("%d -> %d (%d)\n", suc, nx.F, nx.S + 1);
      done[suc] = nx.S + 1;
      q.push(pii(suc, nx.S + 1));
    }
  }

  po[0] = 1;
  for (i = 1; i < 15; i++)
    po[i] = 10 * po[i - 1];

  scanf("%d", &T);

  for (t = 1; t <= T; t++)
  {
    lld n;
    scanf("%lld", &n);
    printf("Case #%d: %lld\n", t, calc2(n));
  }

  return 0;
}
