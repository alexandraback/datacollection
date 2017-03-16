#include <stdio.h>
#include <string.h>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std ;

typedef long long LL ;

#define clr( a , x ) memset ( a , x , sizeof a )
#define cpy( a , x ) memcpy ( a , x , sizeof a )

const int MAXN = 1000005 ;

int n ;
int d[MAXN] ;
int Q[MAXN] , head , tail ;

int rev ( int x ) {
	int ans = 0 ;
	while ( x ) {
		ans = ans * 10 + x % 10 ;
		x /= 10 ;
	}
	return ans ;
}

void bfs () {
	head = tail = 0 ;
	clr ( d , 0 ) ;
	Q[tail ++] = 1 ;
	d[1] = 1 ;
	while ( head != tail ) {
		int u = Q[head ++] ;
		if ( u + 1 > 1000000 ) continue ;
		if ( !d[u + 1] ) {
			d[u + 1] = d[u] + 1 ;
			Q[tail ++] = u + 1 ;
		}
		int x = rev ( u ) ;
		if ( !d[x] ) {
			d[x] = d[u] + 1 ;
			Q[tail ++] = x ;
		}
	}
}

void solve ( int T ) {
	scanf ( "%d" , &n ) ;
	printf ( "Case #%d: %d\n" , T , d[n] ) ;
}


int main () {
	int T ;
	bfs () ;
	freopen ( "A-small-attempt0.in" , "r" , stdin ) ;
	freopen ( "A-small-attempt0.out" , "w" , stdout ) ;
	scanf ( "%d" , &T ) ;
	for ( int i = 1 ; i <= T ; ++ i ) {
		solve ( i ) ;
	}
	return 0 ;
}