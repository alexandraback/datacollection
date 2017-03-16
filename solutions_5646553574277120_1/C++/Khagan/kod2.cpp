//Khagan

#include <algorithm>
#include <stdio.h>
using    namespace std;
typedef  long long LL;

LL T,C,D,V;
LL ar[100];

int main()
{
  freopen("C-large.in","r",stdin);
  freopen("cikti2.txt","w",stdout);
  scanf("%lld",&T);
  for(LL t=1 ; t<=T ; t++)
  {
    scanf("%lld%lld%lld",&C,&D,&V);
    for(LL i=0 ; i<D ; i++)
      scanf("%lld",&ar[i]);
    LL sum=0,ans=0;
    for(LL i=0 ; i<D ; i++)
    {
      while(sum+1<ar[i])
      {
        ans++;
        LL x=sum+1;
        sum+=x*C;
      }
      sum+=ar[i]*C;
    }
    while(sum<V)
    {
      ans++;
      LL x=sum+1;
      sum+=x*C;
    }
    printf("Case #%lld: %lld\n",t,ans);
  }
  return 0;
}
