#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

int hash[ 10000 ] ;

int main() {
	freopen( "B-small-attempt0.in" , "r" , stdin ) ;
	freopen( "B-small-attempt0.out" , "w" , stdout ) ;

	int test_case ;
	scanf( "%d" , &test_case ) ;
	for ( int t = 1 ; t <= test_case ; t ++ ) {
		int a , b , k ;
		scanf( "%d%d%d" , &a , &b , &k ) ;

		memset( hash , 0 , sizeof( hash ) ) ;
		int ans = 0 ;
		for ( int i = 0 ; i < a ; i ++ )
			for ( int j = 0 ; j < b ; j ++ ) {
				int c = ( i & j ) ;
				if ( c < k ) {
					ans ++ ;
					// hash[ c ] = 1 ;
				}
			}
		printf( "Case #%d: %d\n" , t , ans ) ;
	}
}
