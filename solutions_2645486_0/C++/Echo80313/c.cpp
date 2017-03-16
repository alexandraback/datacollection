#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <climits>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#define REP(i,n) for( int (i)=0;(i)<(int)(n); ++(i))
#define REPR(i,n) for( int (i) = n; (i)>=0; --(i))
#define REPN(i,x,y) for( int i = x; (i) < (int)(y); (i)++ )
#define REPIT(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define ZERO(x) memset(x,0,sizeof(x))
#define RI(n) scanf("%d",&(n))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define OI(x) printf("%d\n",(x))
#define OII(x,y) printf("%d %d\n",(x),(y))
#define FT first
#define SD second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
LL LLMAX = 9223372036854775807LL;
const int MOD = 1000000007;
const int maxn = 10000+10;
int v[maxn+1];
int dp[50][110];
bool vis[50][110];
int T,N,R,E;
int dfs(int e,int p){
    if(p==N+1)return 0;
    if(vis[e][p])return dp[e][p];
    vis[e][p] = 1;
    int& x = dp[e][p];
    x=0;
    for(int i=0;i<=e;++i)
        x = max(x,dfs(min(e-i+R,E),p+1) + i*v[p]);
    return x;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("B-small-attempt1 (1).in","r",stdin);
	freopen("out.txt","w",stdout);
#endif
    //for(int i=0;i<10000001;++i)dp[i] = vector<int>(10001,0);

    RI(T);
    REPN(kase,1,T+1){
        RII(E,R);RI(N);
        for(int i=1;i<=N;++i)RI(v[i]);
        ZERO(dp);
        memset(vis,0,sizeof(vis));
        /*for(int i=1;i<=N;++i)
            for(int j=R;j<=E;++j)
                for(int k=0;k<=j;++k){
                    int ne = min(j-k+R,E);
                    dp[ne][i] = max(dp[ne][i],dp[j][i-1]+k*v[i]);
                }
                */
        int ans=dfs(E,1);
        //for(int i=R;i<=E;++i)ans = max(ans,dp[i][N]);
        cout<<"Case #"<<kase<<": "<<ans<<endl;
    }
}
