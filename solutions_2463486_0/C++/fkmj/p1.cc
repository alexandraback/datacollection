#include <cstdio>
#include <set>

using namespace std;

typedef long long ll;

set<int> fq;

bool ispalin(ll x)
{
  ll xx = x;
  ll nn=0;
  while(xx > 0) {
    nn *= 10;
    nn += (xx%10);
    xx /= 10;
  }
  return nn == x;
}

ll fqlist[100];
int fqcount;

main()
{
  fqcount = 0;
  for(ll i=1; i<=20000000; i++)
    if(ispalin(i)) {
      ll i2 = i*i;
      if(ispalin(i2)) {
        fqlist[fqcount] = i2;
        fqcount++;
      }
    }

  int t;
  scanf("%d",&t);
  for(int tt=0; tt<t; tt++) {
    ll a,b;
    scanf("%lld %lld",&a,&b);
    int c = 0;
    for(int i=0; i<fqcount; i++)
      if((a <= fqlist[i]) && (fqlist[i] <= b))
        c++;
    printf("Case #%d: %d\n",tt+1,c);
  }
}
