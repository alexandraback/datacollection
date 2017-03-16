#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;


int t;
int p,q;
int x,ans;
bool gao()
{
    x=q;
    while(x%2==0)x/=2;
    if(x!=1)return false;
    ans=0;
    while(1)
    {
        if(p>=q)return ans;
        q/=2;
        ans++;
    }
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&t);
    int __=0;
    while(t--){

        scanf("%d/%d",&p,&q);
        x=__gcd(p,q);
        p/=x;
        q/=x;

        if(gao())
        printf("Case #%d: %d\n",++__,ans);
        else
        printf("Case #%d: impossible\n",++__);
    }
    return 0;
}
