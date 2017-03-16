
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <time.h>
#include <cstdlib>
#include <iostream>
using namespace std;
#define mp make_pair
#define pii pair<int,int>
#define pb push_back

int dp[1000001];

long long rev(long long x)
{
    long long ret=0;
    while (x)
    {
        ret=ret*10+x%10;
        x/=10;
    }
    return ret;
}

inline int countbit(long long n)
{
    int ret=0;
    for (;n;n/=10,++ret);
    return ret;
}

int calc(long long n)
{
    int ret=0,d,bit;
    long long tmp,tmp2;
    while (n>19)
    {
        bit=countbit(n)/2;
        for (tmp2=1;bit>0;--bit) tmp2*=10;
        d=n%tmp2;
        if (d==0) --n,++ret;
        else
        {
            ret+=d;
            n-=d-1;
            tmp=rev(n);
            if (tmp<n) n=tmp;
            else --n;
        }
    }
    return ret+n;
}

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.txt","w",stdout);
    for (int i=1;i<=1000000;++i) dp[i]=i;
    for (int i=1;i<=1000000;++i)
    {
        dp[i]=min(dp[i],dp[i-1]+1);
        int j=rev(i);
        dp[j]=min(dp[j],dp[i]+1);
    }
    int t;
    long long n;
    scanf("%d",&t);
    for (int cas=1;cas<=t;++cas)
    {
        scanf("%I64d",&n);
        printf("Case #%d: %d\n",cas,calc(n));
    }
    return 0;
}
