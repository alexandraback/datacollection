#include<cstdio>

using namespace std;

long long cmmdc(long long a, long long b)
{
  long long c, d, e;
  c = a;
  d = b;
  while(d)
  {
    e = c % d;
    c = d;
    d = e;
  }
  return c;
}

bool notright(long long a)
{
  if(a == 1)
    return 0;
  else
  {
    if(a & 1)
      return 1;
    else
      return notright((a >> 1));
  }
}

int main()
{
  int n, i, first, j;
  long long p, q, d;
  scanf("%d", &n);
  for(i = 1; i <= n; ++ i)
  {
    scanf("%lld/%lld", &p, &q);
    d = cmmdc(p, q);
    p /= d;
    q /= d;
    if(notright(q))
      printf("Case #%d: impossible\n", i);
    else
    {
      first = 0;
      j = 1;
      while(p)
      {
        if(p + p >= q)
        {
          first = j;
          break;
        }
        else
          q = (q >> 1);
        ++ j;
      }
      printf("Case #%d: %d\n", i, first);
    }
  }
  return 0;
}
