#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define rep(i,n) for(int i=0;i<n;i++)
#define A frist
#define B second
#define mp make_pair
#define LL long long
#define pb push_back
using namespace std;

int dp[11][6];
int v[15];
int e,r,n;
int main()
{
        freopen("B1.in","r",stdin);
        freopen("B1.txt","w",stdout);

    int T;
    scanf("%d",&T);
    rep(cas,T)
    {
        scanf("%d%d%d",&e,&r,&n);
        rep(i,n)scanf("%d",&v[i]);

        memset(dp,-1,sizeof(dp));

        dp[0][e] = 0;
        rep(i,n)
        {
            rep(j,e+1)
            {
                if(dp[i][j]==-1)continue;

                for(int k=0;k<=j;k++)
                {
                    dp[i+1][min(e,j-k+r)] = max(dp[i+1][min(e,j-k+r)],dp[i][j]+k*v[i]);
                }
            }
        }
        int ret = 0;
        rep(i,e+1)
            ret = max(ret,dp[n][i]);
        printf("Case #%d: %d\n",cas+1,ret);
    }
}






