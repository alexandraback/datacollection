#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;
typedef long long ll;


ll find_exp(ll x)
{
  if(x==0)
    return -1;
  ll reponse = 0;
  while(x > 1)
  {
    reponse++;
    x/=2;
  }
  return reponse;
  
}

bool estnormal(ll x)
{
  ll expo = find_exp(x);
  return x == ( (1 << (expo + 1)) - 1);
}

ll calc(ll a, ll b, ll k)
{
  if(k >= a || k >= b)
    return (a+1)*(b+1);
  if(a > b)
    return calc(b,a,k);
  if(a == 0)
    return b+1;
  ll pa = find_exp(a), pb = find_exp(b), pk = find_exp(k);

  if(pa < pb)
  {
    if(estnormal(b))
      return 2*calc(a,(1<<pb) - 1, k);
    return calc(a, b - (1 << pb), k) + calc(a, (1<<pb) - 1,k);
  }
  if(pk < pa)
  {
    if(estnormal(b) && estnormal(a))
    {
      return 3*calc((1<<pa) -1, (1<<pb) - 1, k);
    }
    return calc(a - (1<<pa),(1<<pb) - 1,k) + calc( (1<<pa) - 1, b - (1<<pb), k) + calc((1<<pa) - 1, (1<<pb) - 1, k);
  }
  if(estnormal(a) && estnormal(b))
  {
    return 3*calc((1<<pa) - 1, (1<<pb) - 1,k) + calc((1<<pa) - 1, (1<<pb) - 1, k - (1<<pk));
  }
  return calc(a - (1<<pa), (1<<pb) - 1, k) + calc((1<<pa) - 1, b - (1<<pb), k) + calc((1<<pa) - 1, (1<<pb) - 1,k) + calc(a - (1<<pa), b - (1<<pb), k - (1<<pk));

}

void do_case()
{
  ll a,b,k;
  scanf("%lld %lld %lld", &a,&b,&k);
  printf("%lld\n", calc(a-1,b-1,k-1));
  return;

}


int main()
{
  int t;
  scanf("%d", &t);
  for(int i = 1; i <= t; i++)
  {
    printf("Case #%d: ", i);
    do_case();

  }
  return 0;
}
