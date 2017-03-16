#include <stdio.h>
#include <cstdlib>

__int64 r,t,l,h;

const __int64 inf=10000000000ll;

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
   int T;
   scanf("%d",&T);
   for(int ca=1;ca<=T;ca++)
   {
        scanf("%I64d%I64d",&r,&t);
        l=0;
        h=inf;
        while(l!=h)
        {
            long long mid=(l+h)/2+1;
            double tmp1=2*r+(2*mid+1);
            double tmp2=t*1.0/(double)(mid+1);
            if( tmp1-tmp2<1e-9 ) l=mid; 
            else h=mid-1;
        }
        printf("Case #%d: %I64d\n",ca,l+1);
   }
}
