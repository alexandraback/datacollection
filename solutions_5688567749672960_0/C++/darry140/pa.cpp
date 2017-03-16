#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll rev(ll x)
{
    ll ret=0;
    while(x)
    {
        ret=ret*10+x%10;
        x/=10;
    }
    return ret;
}
ll find(ll x)
{
    static map<ll,ll> mp;
    if(mp.find(x)!=mp.end())
        return mp[x];
    ll ret;
    if(x==1)
        ret=1;
    else if(rev(x)<x&&x%10)
        ret=min(find(x-1),find(rev(x)))+1;
    else
        ret=find(x-1)+1;
    //printf("find(%lld) = %lld\n",x,ret);
    return mp[x]=ret;
}
void sol(int cas)
{
    for(ll i=1;i<=n;i++)
        find(i);
    ll tmp=find(n);
    printf("Case #%d: %lld\n",cas,tmp);
}
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%lld",&n);
        sol(cas);
    }
    return 0;
}
