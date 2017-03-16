#include <cstdio>
#include <cstdlib>
#include <cstring>
long long x,y; int t;
long long solve(long long x,long long y)
{
    long long l=1,r=1000000000ll,m;
    while(r-l>1)
    {
        m=(l+r)/2;
        if(x*m*2+m*m*2-m>y) r=m;
        else l=m;
    }
    return l;
}
int main()
{
    freopen("in1","r",stdin);
    freopen("out1","w",stdout);
    scanf("%d",&t);
    for(int I=1;I<=t;++I)
    {
        scanf("%lld%lld",&x,&y);
        printf("Case #%d: %lld\n",I,solve(x,y));
    }
    return 0;
}
