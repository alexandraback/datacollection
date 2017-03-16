#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
main()
{
      int tc ,u=1;
      scanf("%d",&tc);
      while(tc--)
      {
         ll a,b,k;
         scanf("%lld %lld %lld",&a,&b,&k);
         ll i,j,count=0;
         for( i=0;i<a;i++)
         {
              for(j=0;j<b;j++)
              {
                 ll c;
                 c = i&j;
                 if(c<k)
                 count++;
              }
         }
         printf("Case #%d: %lld\n",u,count);
         u++;
      }
}
