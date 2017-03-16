#include <cstdio>
#include <cstdlib>
#include <cstring>
double x,y; int t;
long long solve(double x,double y)
{
    long long l=1,r=5000000000ll,m;
    while(r-l>1)
    {
        m=(l+r)/2;
        if(x*(double)m*2+(double)m*(double)m*2-(double)m>y) r=m;
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
        scanf("%lf%lf",&x,&y);
        printf("Case #%d: %lld\n",I,solve(x,y));
    }
    return 0;
}
