#include <cstdio>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std ;

const int MAXN = 205 ;
const double eps = 1e-8 ;

char t[MAXN] , p[MAXN] ;
int G[MAXN] ;
int K , L , S ;
int fail[MAXN] ;

void get_fail () {
	fail[1] = 0 ;
	for ( int i = 2 , j = 0 ; i <= L ; ++ i ) {
		while ( j && p[i] != p[j + 1] ) j = fail[j] ;
		if ( p[i] == p[j + 1] ) ++ j ;
		fail[i] = j ;
	}
}

void solve () {
	memset ( G , 0 , sizeof G ) ;
	scanf ( "%d%d%d" , &K , &L , &S ) ;
	scanf ( "%s%s" , t , p + 1 ) ;
	get_fail () ;
	int maxv = ( S - L ) / ( L - fail[L] ) + 1 ;
	for ( int i = 0 ; i < K ; ++ i ) {
		G[t[i]] ++ ;
	}
	for ( int i = 1 ; i <= L ; ++ i ) {
		if ( !G[p[i]] ) {
			printf ( "0.0\n" ) ;
			return ;
		}
	}
	double cost = ( S - L + 1 ) ;
	//printf ( "%.6f\n" , cost ) ;
	double tot = pow ( K * 1.0 , L - 1.0 ) ;
	for ( int i = 1 ; i <= L ; ++ i ) {
		cost *= ( double ) G[p[i]] / K ;
	}
	//printf ( "%d %.f %.f\n" , maxv , cost , tot ) ;
	printf ( "%.6f\n" , maxv - cost ) ;
}

int main () {
	int T ;
	freopen ( "B-large (2).in" , "r" , stdin ) ;
	freopen ( "B-large (2).out" , "w" , stdout ) ;
	scanf ( "%d" , &T ) ;
	for ( int i = 1 ; i <= T ; ++ i ) {
		printf ( "Case #%d: " , i ) ;
		solve () ;
	}
	return 0 ;
}
