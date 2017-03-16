#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
#define eps 1e-8
ll rr,t;

bool fun(ll x)
{
    if(2*rr+2*x-1<t/(x+0.0)+eps)
        return true;
    else
        return false;
}
ll bin(ll l,ll r)
{
    ll mid;
    while (l<=r)
    {
        mid = (l+r)>>1;
       // printf("%lld %d\n",mid,fun(mid));
        if (fun(mid)) l=mid+1;
        else r=mid-1;
    }
    return r;
}

int main()
{
    int T;
    int ca=0;
    freopen("A-large.in","r",stdin);
    freopen("a.txt","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&rr,&t);
  //      for(int i=1;i<=10;i++)
  //          printf("%d\n",fun(i));
        ll res=bin(1,1000000000000000000LL);
        printf("Case #%d: %lld\n",++ca,res);
    }
    return 0;
}
