#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>

#define MAXN 100001

using namespace std;

// 0 -> E, 1 -> W, 2 -> N , 3 -> S

int main( void )
{
	int T;
	freopen("test.in","rt",stdin);
	scanf("%d",&T);
	for( int z = 1; z <= T; z++ ) {
		int x,y;
		int cnt = 1;
		int dir[ 2*MAXN + 1 ];
		scanf("%d%d",&x,&y);
		if( x > 0 ) {
			dir[ 0 ] = 0;
		} else {
			dir[ 0 ] = 1;
		}
		for( int i = 1; i < abs( x ); i++  ){
			if( dir[ i - 1 ] == 0 ) {
				dir[ i ] = 1;
			} else {
				dir[ i ] = 0;
			}
		}
		cnt = abs( x );
		if( y < 0 ) {
			dir[ cnt ] = 3;
		} else {
			dir[ cnt ] = 2;
		}
		cnt++;
		for( int i = 1; i < abs( y ); i++ ) {
			if( dir[ cnt - 1 ] == 3 ) {
				dir[ cnt ] = 2;
			} else {
				dir[ cnt ] = 3;
			}
			cnt++;
		}
		printf("Case #%d: ", z );
		for( int i = 0; i < cnt; i++ ) {
			if( dir[ i ] == 0 ) {
				printf("E");
			}
			else if( dir[ i ] == 1 ) {
				printf("W");
			}
			else if( dir[ i ] == 2 ) {
				printf("N");
			}
			else if( dir[ i ] == 3 ) {
				printf("S");
			}
		}
		printf("\n");
	}
	return 0;
}
