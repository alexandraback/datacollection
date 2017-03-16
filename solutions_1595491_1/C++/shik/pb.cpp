// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,s,p,t[N],dp[N][N];
int go( int x, int y ) {
	if ( x==n ) return y==s?0:-N;
	int &r=dp[x][y];
	if ( r!=-1 ) return r;
	r=-N;
	for ( int i=0; i<=10; i++ ) for ( int j=i; j<=10&&j<=i+2; j++ ) for ( int k=j; k<=10&&k<=i+2; k++ ) if ( i+j+k==t[x] ) {
		if ( k-i==2 && y==s ) continue;
		r=max(r,go(x+1,y+(k-i==2))+(k>=p));
	}
	return r;
}
int main()
{
	int T,cas=0;
	scanf("%d",&T);
	while ( T-- ) {
		scanf("%d%d%d",&n,&s,&p);
		for ( int i=0; i<n; i++ ) scanf("%d",t+i);
		memset(dp,-1,sizeof(dp));
		printf("Case #%d: %d\n",++cas,go(0,0));
	}
	return 0;
}
