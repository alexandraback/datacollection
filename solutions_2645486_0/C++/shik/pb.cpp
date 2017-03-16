// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
inline void chkmax( int &a, int b ) { if ( b>a ) a=b; }
#define N 20
#define E 10
#define INF 514514514
int e,r,n,v[N];
int dp[N][E];
void solve() {
    scanf("%d%d%d",&e,&r,&n);
    for ( int i=0; i<n; i++ ) scanf("%d",v+i);
    for ( int i=0; i<=n; i++ ) for ( int j=0; j<=e; j++ ) dp[i][j]=-INF;
    dp[0][e]=0;
    for ( int i=0; i<n; i++ ) for ( int j=0; j<=e; j++ ) if ( dp[i][j]>=0 ) {
        int me=dp[i][j];
        for ( int k=0; k<=j; k++ ) {
            int nj=min(e,j-k+r);
            chkmax(dp[i+1][nj],me+k*v[i]);
        }
    }
    int ans=0;
    for ( int i=0; i<=e; i++ ) ans=max(ans,dp[n][i]);
    printf("%d\n",ans);
}
int main()
{
    int t,cas=0;
    scanf("%d",&t);
    while ( t-- ) {
        printf("Case #%d: ",++cas);
        solve();
    }
    return 0;
}

