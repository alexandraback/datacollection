#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef pair<int,int> PII;
#define For(i,n) for(int i=0;i<n;i++)
#define sz(i) int(i.size())
#define mst(i,n) memset(i,n,sizeof(i))
#define eps 1e-11
#define MOD 1000000007
#define LL long long
#define pi acos(-1)
#define ALL(n) n.begin(),n.end()
#define pb push_back
#define mp make_pair
#define iFor(i,n) for(typeof(n.begin()) i=n.begin();i!=n.end();i++)
int n,k;
int s[555];
int open[555];
int keynum[555];
int key[555][555];
int dp[1<<21];
bool DP(int basemask,int cur)
{
    int hh[555]= {};
    For(j,k) hh[ s[j] ]++;
    For(j,n) if(basemask&(1<<j))
    {
        hh[ open[j] ]--;
        For(t,keynum[j]) hh[ key[j][t] ]++;
    }
    if(hh[open[cur] ]==0)
        return false;
    mst(dp,0);
    dp[1<<cur] = 1;

    for(int mask=0;mask<(1<<n);mask++)
    {
        if(mask&basemask) continue;
        if(!dp[mask]) continue;
        int hand[555]= {};
        For(j,k) hand[ s[j] ]++;
        For(j,n) if((mask|basemask)&(1<<j))
        {
            hand[ open[j] ]--;
            For(t,keynum[j]) hand[ key[j][t] ]++;
        }
        For(j,n) if((mask&(1<<j))==0){
            if(hand[open[j]]){
                dp[(mask|(1<<j))] = 1;
            }
        }
    }
    return dp[(1<<n)-1-basemask];
}
int main()
{
    freopen("D-small-attempt3.in","r",stdin);
    freopen("D-small-attempt3.out","w",stdout);
    int ca = 0;
    scanf("%d",&ca);
    For(c, ca)
    {
        scanf("%d %d",&k,&n);
        For(i,k) scanf("%d",s+i);
        For(i,n)
        {
            scanf("%d %d",open+i,keynum+i);
            For(j,keynum[i])
                scanf("%d",key[i]+j);
        }
        bool pos = false;
        int basemask = 0;
        printf("Case #%d:",c+1);
        For(i,n)
        {
            int ans = -1;
            For(cur,n)
            {
                if( (1<<cur)&basemask) continue;
                if(DP(basemask, cur))
                {
                    ans = cur;
                    break;
                }
            }
            if(ans==-1) break;
            else pos = true;
            basemask |= 1<<ans;
            printf(" %d",ans+1);
        }
        if(!pos)printf(" IMPOSSIBLE");
        printf("\n");
        //printf("Case #%d: %d\n",c+1,res);
    }
}
