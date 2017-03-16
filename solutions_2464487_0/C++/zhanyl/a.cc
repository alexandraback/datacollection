#include <cstdio>
#include <cstdlib>
#include <cstring>

long long a,b,l,r,mid;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%I64d%I64d",&a,&b);
        l=1;
        r=b;
        while(l+1<r)
        {
            mid=(l+r)>>1;
            if((double)(2*a+1+2*a+1+4*(mid-1))*mid/2.0>1e18)r=mid;
            else if((2*a+1+2*a+1+4*(mid-1))*mid/2.0>b)r=mid;
            else l=mid;
        }
        for(mid=l;mid<=r;mid++)
            if((2*a+1+2*a+1+4*(mid-1))*mid/2.0>b)break;
        printf("Case #%d: %I64d\n",cas,mid-1);
    }
    return 0;
}
