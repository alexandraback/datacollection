#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
int a[20],b[200],tot,tt;
ll l,r;
bool check(ll o)
{
    memset(a,0,sizeof(a));
    int n=0;
    while (o!=0)
    {
        a[++n]=o%10;
        o/=10;
    }
    for(int i=1;i<=n/2;++i)
        if (a[i]!=a[n-i+1]) return false;
    return true;
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("test.out","w",stdout);
    for(ll i=1;i<=2001002;++i)
    {
        ll o=i*i;
        if (check(i) && check(o))
            b[++tot]=i;
    }
    scanf("%d",&tt);
    for(int o=1;o<=tt;++o)
    {
        int ans=0;
        printf("Case #%d: ",o);
        scanf("%lld %lld",&l,&r);
        for(int i=1;i<=tot;++i)
            if (b[i]<=sqrt(r)) ++ans;
        for(int i=1;i<=tot;++i)
            if (b[i]<sqrt(l)) --ans;
        printf("%d\n",ans);
    }
}
