#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;

const int MAXN = 1005 ;

char t[MAXN] , s[MAXN] , p[MAXN] ;
int K , L , S ;
int fail[MAXN] ;
int maxv , tot , cost ;

void get_fail () {
	fail[1] = 0 ;
	for ( int i = 2 , j = 0 ; i <= L ; ++ i ) {
		while ( j && p[i] != p[j + 1] ) j = fail[j] ;
		if ( p[i] == p[j + 1] ) ++ j ;
		fail[i] = j ;
	}
}

int kmp () {
	int ans = 0 ;
	for ( int i = 1 , j = 0 ; i <= S ; ++ i ) {
		while ( j && s[i] != p[j + 1] ) j = fail[j] ;
		if ( s[i] == p[j + 1] ) {
			++ j ;
			if ( j == L ) {
				++ ans ;
				j = fail[j] ;
			}
		} else j = fail[j] ;
	}
	return ans ;
}

void dfs ( int cur ) {
	if ( cur == S ) {
		++ tot ;
		s[cur + 1] = 0 ;
		int tmp = kmp () ;
		maxv = max ( maxv , tmp ) ;
		cost += tmp ;
		return ;
	}
	for ( int i = 0 ; i < K ; ++ i ) {
		s[cur + 1] = t[i] ;
		dfs ( cur + 1 ) ;
	}
}
	

void solve () {
	tot = maxv = cost = 0 ;
	scanf ( "%d%d%d" , &K , &L , &S ) ;
	scanf ( "%s%s" , t , p + 1 ) ;
	get_fail () ;
	dfs ( 0 ) ;
	//printf ( "%d %d\n" , cost , tot ) ;
	printf ( "%.6f\n" , maxv - ( double ) cost / tot ) ;
}

int main () {
	int T ;
	freopen ( "B-small-attempt0 (2).in" , "r" , stdin ) ;
	freopen ( "B-small-attempt0 (2)out" , "w" , stdout ) ;
	scanf ( "%d" , &T ) ;
	for ( int i = 1 ; i <= T ; ++ i ) {
		printf ( "Case #%d: " , i ) ;
		solve () ;
	}
	return 0 ;
}
