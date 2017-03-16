#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;

void solve () {
	int R , C , W ;
	scanf ( "%d%d%d" , &R , &C , &W ) ;
	int ans = R * ( C / W ) + W ;
	if ( C % W == 0 ) -- ans ;
	printf ( "%d\n" , ans ) ;
}

int main () {
	int T ;
	freopen ( "A-small-attempt2.in" , "r" , stdin ) ;
	freopen ( "A-small-attempt2.out" , "w" , stdout ) ;
	scanf ( "%d" , &T ) ;
	for ( int i = 1 ; i <= T ; ++ i ) {
		printf ( "Case #%d: " , i ) ;
		solve () ;
	}
	return 0 ;
}
