#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#define DBLE 1e-8
#define PI 3.1415926535898
#define INF 1000000000
#define MAXN 100010
#define MP(x,y) (make_pair((x),(y)))
#define FI first
#define SE second
using namespace std;
int dp[MAXN];
int main()
{
//    freopen("J:\\MyDocument\\Code\\input.txt","r",stdin);
//    freopen("J:\\MyDocument\\Code\\output2.txt","w",stdout);
    int ncase;
    int e,r,n,top,v,dif;
    long long tmp;
    scanf("%d",&ncase);
    for(int h=1;h<=ncase;++h)
    {
        scanf("%d%d%d",&e,&r,&n);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;++i)
        {
            scanf("%d",&v);
            for(int j=1;j<=e;++j)
                for(int k=0;k<=j;++k)
                    dp[j-k]=max(dp[j-k],dp[j]+k*v);
            for(int j=e-1;j>=0;--j)
                dp[min(e,j+r)]=max(dp[min(e,j+r)],dp[j]);
        }
        tmp=0;
        for(int i=0;i<=e;++i)
            tmp=max(tmp,(long long)dp[i]);
        printf("Case #%d: ",h);
        cout<<tmp<<'\n';
    }
    return 0;
}

