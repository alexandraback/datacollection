#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

typedef long long int lld;
typedef pair<int, int> pii;
typedef pair<pii, pii> line;

#define F first
#define S second

int done[1000001];

int rev(int cur)
{
  int tmp = 0;
  while (cur)
  {
    tmp *= 10;
    tmp += cur % 10;
    cur /= 10;
  }

  return tmp;
}

int calc(int cur)
{
  if (cur <= 101)
    return done[cur];
  if (((cur - 1 + 100) % 100) == 0)
  {
    if (cur == rev(cur))
      return 1 + calc(cur - 1);
    return 1 + calc(rev(cur));
  }

  return ((cur - 1 + 100) % 100) + calc(cur - ((cur - 1 + 100) % 100));
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
    if (suc < 1000001 && !done[suc])
    {
      done[suc] = nx.S + 1;
      q.push(pii(suc, nx.S + 1));
    }

    suc = rev(nx.F);
    if (suc < 1000001 && !done[suc])
    {
      done[suc] = nx.S + 1;
      q.push(pii(suc, nx.S + 1));
    }
  }

  scanf("%d", &T);

  for (t = 1; t <= T; t++)
  {
    int n;
    scanf("%d", &n);
    printf("Case #%d: %d\n", t, done[n]);
  }

  return 0;
}
