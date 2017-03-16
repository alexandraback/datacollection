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
#define MAXN 110
#define MP(x,y) (make_pair((x),(y)))
#define FI first
#define SE second
using namespace std;
int mote[MAXN];
int dp[MAXN][30];
int main()
{
//    freopen("J:\\MyDocument\\Code\\input.txt","r",stdin);
//    freopen("J:\\MyDocument\\Code\\output.txt","w",stdout);
    int ncase,a,n;
    scanf("%d",&ncase);
    for(int h=1;h<=ncase;++h)
    {
        scanf("%d%d",&a,&n);
        for(int i=0;i<n;++i)
            scanf("%d",&mote[i]);
        sort(mote,mote+n);
        memset(dp,0,sizeof(dp));
        dp[0][0]=a;
        for(int i=0;i<n;++i)
            for(int j=0;j<=20;++j)
                if(dp[i][j]>mote[i])
                    dp[i+1][j]=max(dp[i+1][j],dp[i][j]+mote[i]);
                else    dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]),
                        dp[i][j+1]=max(dp[i][j+1],dp[i][j]*2-1);
        printf("Case #%d: ",h);
        for(int i=0;i<30;++i)
            if(dp[n][i]>0)
            {
                printf("%d\n",i);
                break;
            }
    }
    return 0;
}
