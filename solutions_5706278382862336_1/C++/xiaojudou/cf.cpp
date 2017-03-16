#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;


int t;
long long p,q;
long long x,ans;
bool gao()
{
    x=q;
    while(x%2ll==0)x/=2ll;
    if(x!=1ll)return false;
    ans=0;
    while(1)
    {
        if(p>=q)return ans;
        q/=2ll;
        ans++;
    }
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&t);
    int __=0;
    while(t--){

        scanf("%lld/%lld",&p,&q);
        x=__gcd(p,q);
        p/=x;
        q/=x;

        if(gao())
        printf("Case #%d: %lld\n",++__,ans);
        else
        printf("Case #%d: impossible\n",++__);
    }
    return 0;
}
