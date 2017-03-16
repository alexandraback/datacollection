#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long gcd( long long a , long long b ) {
	if ( b == 0 ) return a ;
	return gcd( b , a % b ) ;
}

int main() {
	freopen( "A-small-attempt0.in" , "r" , stdin ) ;
	freopen( "A-small-attempt0.out" , "w" , stdout ) ;

	int test_case ; 
	scanf( "%d\n" , &test_case ) ;
	for ( int t = 1 ; t <= test_case ; t ++ ) {
		long long a , b ;
		scanf( "%lld/%lld\n" , &a , &b ) ;
		long long c = gcd( a , b ) ;
		a /= c ;
		b /= c ;

		long long k = 1 ;
		int ans = 0 ;
		while ( k < b ) {
			k *= 2LL ;
			ans ++ ;
		}

		if ( k == b ) {
			// cout << a << ' ' << b << endl;
			long long l = 1 ;
			while ( l <= a ) {
				l *= 2LL ;
				ans -- ;
			}
			ans ++ ;
			printf( "Case #%d: %d\n" , t , ans ) ;
		} else 
			printf( "Case #%d: impossible\n" , t ) ;
	}
}