#include <iostream>
#include <string.h>
#include <stdio.h>
#define ll long long
using namespace std;
ll min(ll a,ll b)
{
    return a<b?a:b;
}
int check(ll num,ll t,ll r)
{
    if(2*r+(2*num-1)<=t/num)
    return 1;
    return 0;
}
int main()
{
    //freopen("A-small-attempt0.in","r",stdin);
    //freopen("out.txt","w+",stdout);
    int ncase,time=0;
    scanf("%d",&ncase);
    while(ncase--)
    {
        printf("Case #%d: ",++time);
        ll ans=0,r,t;
        scanf("%I64d%I64d",&r,&t);
        ll mi=1,ma=min(t,717106780),mid;
        while(mi<=ma)
        {
            mid=(mi+ma)>>1;
            if(check(mid,t,r))
            {
                ans=mid;
                mi=mid+1;
            }
            else
            ma=mid-1;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
