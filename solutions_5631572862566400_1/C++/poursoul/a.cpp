#include <bits/stdc++.h>
using namespace std ;

const int MAXN = 1005 ;
const int MAXE = 100005 ;

vector < int > G[MAXN] ;
int f[MAXN] ;
int S[MAXN] , top ;
int vis[MAXN] ;
int vis2[MAXN] ;
int tmp ;

int dfs ( int u , int f ) {
	int d1 = 0 ;
	vis2[u] = 1 ;
	for ( int i = 0 ; i < G[u].size () ; ++ i ) {
		int v = G[u][i] ;
		if ( v == f ) continue ;
		d1 = max ( d1 , dfs ( v , u ) ) ;
	}
	return d1 + 1 ;
}

void solve () {
	int n ;
	scanf ( "%d" , &n ) ;
	memset ( vis , 0 , sizeof vis ) ;
	memset ( vis2 , 0 , sizeof vis2 ) ;
	for ( int i = 1 ; i <= n ; ++ i ) {
		G[i].clear () ;
	}
	for ( int i = 1 ; i <= n ; ++ i ) {
		scanf ( "%d" , &f[i] ) ;
		G[f[i]].push_back ( i ) ;
	}
	int ans = 2 , ans2 = 0 ;
	for ( int i = 1 ; i <= n ; ++ i ) if ( !vis[i] ) {
		top = 0 ;
		int x = i , t = 0 ;
		while ( 1 ) {
			vis[x] = ++ t ;
			if ( vis2[f[x]] ) break ;
			if ( vis[f[x]] ) {
				int res = vis[x] - vis[f[x]] + 1 ;
				if ( res > 2 ) ans = max ( ans , res ) ;
				else if ( res == 2 ) ans2 += dfs ( x , f[x] ) + dfs ( f[x] , x ) ;
				break ;
			}
			x = f[x] ;
		}
		x = i ;
		while ( 1 ) {
			vis2[x] = 1 ;
			if ( vis2[f[x]] ) break ;
			x = f[x] ;
		}
	}
	printf ( "%d\n" , max ( ans , ans2 ) ) ;
}

int main () {
	int T ;
	freopen ( "C-large.in" , "r" , stdin ) ;
	freopen ( "C-large.out" , "w" , stdout ) ;
	scanf ( "%d" , &T ) ;
	for ( int i = 1 ; i <= T ; ++ i ) {
		printf ( "Case #%d: " , i ) ;
		solve () ;
	}
	return 0 ;
}