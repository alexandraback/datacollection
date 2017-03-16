#include <stdio.h>
#define MAX 10000000

typedef long long ll;

ll dig[20],pre[MAX];

bool pal(ll x)
{
    ll cnt,i;
    cnt=0;
    while (x)
    {
        dig[cnt++]=x%10;
        x/=10;
    }
    for (i=0;i<cnt;i++)
    {
        if (dig[i]!=dig[cnt-1-i]) break;
    }
    return i==cnt;
}

int main()
{
    freopen("cin.txt","r",stdin);
    freopen("cout.txt","w",stdout);
    ll i,test,cas,a,b,lo,hi,mid,cnt,x;
    cnt=0;
    for (i=1;i<=MAX;i++)
    {
        if (pal(i)&&pal(i*i))
        {
            pre[cnt++]=i*i;
        }
    }
    scanf("%lld",&test);
    for (cas=1;cas<=test;cas++)
    {
        scanf("%lld%lld",&a,&b);
        lo=0;
        hi=cnt-1;
        while (lo<hi)
        {
            mid=(lo+hi)/2;
            if (pre[mid]>=a) hi=mid;
            else lo=mid+1;
        }

        if (pre[lo]>=a&&pre[lo]<=b)
        {
            x=lo;
            lo=x;
            hi=cnt-1;
            while (lo<hi)
            {
                mid=(lo+hi+1)/2;
                if (pre[mid]<=b) lo=mid;
                else hi=mid-1;
            }
            printf("Case #%lld: %lld\n",cas,lo-x+1);
        }
        else printf("Case #%lld: 0\n",cas);
    }
    return 0;
}
