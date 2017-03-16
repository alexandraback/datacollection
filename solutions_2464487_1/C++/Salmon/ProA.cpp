#include <cstdio>
long long bis(long long r,long long t,long long be,long long en)
{
    long long mid;
    while(be<en)
    {
        mid=(be+en)>>1;
        if(2*mid-1>t/mid)
        {
            en=mid;
            continue;
        }
        if(mid*2*r+(2*mid-1)*(mid)>t)
            en=mid;
        else
            be=mid+1;
    }
    return be;
}
int main()
{
    int test;
    long long r,t;
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&test);
    for(int i=1;i<=test;i++)
    {
        scanf("%lld%lld",&r,&t);
        printf("Case #%d: %lld\n",i,bis(r,t,1,t/2/r+1)-1);
    }
}
