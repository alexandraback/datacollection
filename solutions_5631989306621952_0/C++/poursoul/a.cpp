#include <bits/stdc++.h>
using namespace std ;

const int MAXN = 1005 ;

char s[MAXN] ;
char p[MAXN] ;
char a[MAXN] ;
int n ;

void solve () {
	scanf ( "%s" , s + 1 ) ;
	n = strlen ( s + 1 ) ;
	p[0] = 0 ;
	for ( int i = 1 ; i <= n ; ++ i ) {
		p[i] = max ( p[i - 1] , s[i] ) ;
	}
	int l = 1 , r = n ;
	for ( int i = n ; i >= 1 ; -- i ) {
		if ( s[i] == p[i] ) a[l ++] = s[i] ;
		else a[r --] = s[i] ;
	}
	a[n + 1] = 0 ;
	printf ( "%s\n" , a + 1 ) ;
}

int main () {
	int T ;
	freopen ( "A-small-attempt0.in" , "r" , stdin ) ;
	freopen ( "A-small-attempt0.out" , "w" , stdout ) ;
	scanf ( "%d" , &T ) ;
	for ( int i = 1 ; i <= T ; ++ i ) {
		printf ( "Case #%d: " , i ) ;
		solve () ;
	}
	return 0 ;
}