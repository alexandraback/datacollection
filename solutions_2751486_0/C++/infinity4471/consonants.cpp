#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAXN 100

using namespace std;

char vow[] = { 'a', 'e', 'i' , 'o', 'u' };

bool find( char c )
{
	for( int i = 0; i < 5; i++ ) {
		if( vow[ i ] == c ) {
			return true;
		}
	}
	return false;
}

int main( void )
{
	int T,cnt = 1;
	freopen("test.in","rt",stdin);
	freopen("test.out","wt",stdout);
	scanf("%d",&T);
	while( T-- ) {
		int n;
		char str[ MAXN + 1 ];
		scanf("%s%d",&str,&n);
		int N = strlen( str );
		int ans = 0;
		for( int i = 0; i < N; i++ ) {
			for( int j = i; j < N; j++ ) {
				int cons = 0,maxn = 0;
				for( int k = i; k <= j; k++ ) {
					if( !find( str[ k ] ) ) {
						cons++;
					} else {
						cons = 0;
					}
					if( cons >= n ) {
						maxn = max( maxn, cons );
					}
				}
				if( maxn >= n ) {
					//printf("valid -> (%d,%d)\n", i, j ) ;
					ans++;
				}
			}
		}
		printf("Case #%d: %d\n", cnt++, ans );
	}
	return 0;
}
