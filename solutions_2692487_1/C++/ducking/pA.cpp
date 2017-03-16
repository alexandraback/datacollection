/*
 * By Duck
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
// dp[add now many][number of operation][wanna eat this] = max volumn
// ok[..][..][..] = if fill
using std::min;
using std::max;
const int INF = 100000000;
const int N = 101;
int dp[N][N][N], ok[N][N][N];
int num[N];
int g(int a, int b, int c, int bol) {
	if( a<0 || b<0 || c<0 ) return -INF;
	if( bol && !ok[a][b][c] ) return -INF;
	return dp[a][b][c];
}
int main(){
	int t, a, n;
	scanf("%d", &t);
	for( int r=1; r<=t; r++ ) {
		scanf("%d %d", &a, &n);
		for( int i=1; i<=n; i++ ) 
			scanf("%d", num+i);
		std::sort(num+1, num+n+1);
		num[0] = 0;
		for( int i=0; i<=n; i++ ) for( int j=0; j<=n; j++ ) for( int k=0; k<=n; k++ ) dp[i][j][k]=-INF, ok[i][j][k]=0;
		dp[0][0][0] = a;
		ok[0][0][0] = 1;
		for( int k=0; k<=n; k++ ) {
			for( int j=0; j<=n; j++ ) {
				for( int i=0; i<=j; i++ ) {
					if( i==0&&j==0&&k==0 ) continue;
					dp[i][j][k] = max( dp[i][j][k], g(i-1,j-1,k-1,0) );
					if( g(i, j, k-1, 0)>num[k] )
						dp[i][j][k] = max( dp[i][j][k], g(i, j, k-1, 0)+num[k] );
					if( 2*g(i,j-1,k-1,0) - 1 > num[k] ) 
						dp[i][j][k] = min( INF, max( dp[i][j][k], 2*g(i,j-1,k-1,0)-1+num[k] ) );
					dp[i][j][k] = min( INF, max( dp[i][j][k], 2*g(i-1,j-1,k,0)-1 ) );
					if( dp[i][j][k] < 0 ) {
						dp[i][j][k] = min(INF, 2*g(i,j-1,k,1)-1);
						if( dp[i][j][k]<0 ) dp[i][j][k] = -INF;
					} else
						ok[i][j][k] = 1;
				}
			}
		}
		for( int i=0; i<=n; i++ ) 
			for( int j=0; j<=i; j++ )
				if( ok[j][i][n] ) {
					printf("Case #%d: %d\n", r, i);
					i = j = n+1;
				}
	}
	return 0;
}

