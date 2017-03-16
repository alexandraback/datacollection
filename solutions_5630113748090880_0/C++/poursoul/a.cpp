#include <bits/stdc++.h>
using namespace std ;

const int MAXN = 2505 ;

int a[MAXN] , n ;

void solve () {
	memset ( a , 0 , sizeof a ) ;
	scanf ( "%d" , &n ) ;
	for ( int i = 1 ; i < 2 * n ; ++ i ) {
		for ( int j = 1 ; j <= n ; ++ j ) {
			int x ;
			scanf ( "%d" , &x ) ;
			a[x] ^= 1 ;
		}
	}
	for ( int i = 1 ; i <= 2500 ; ++ i ) {
		if ( a[i] ) printf ( " %d" , i ) ;
	}
	puts ( "" ) ;
}

int main () {
	int T ;
	freopen ( "B-small-attempt0.in" , "r" , stdin ) ;
	freopen ( "B-small-attempt0.out" , "w" , stdout ) ;
	scanf ( "%d" , &T ) ;
	for ( int i = 1 ; i <= T ; ++ i ) {
		printf ( "Case #%d:" , i ) ;
		solve () ;
	}
	return 0 ;
}