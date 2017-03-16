//by tzupengwang™
#include<bits/stdc++.h>
using namespace std;

#define FO(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
typedef long long ll;
typedef pair<int,int> ii;

int n ;
int s[ 10000 ] ;
int MX ;

void init() {
	scanf( "%d" , &n ) ;
	MX = 0 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		scanf( "%d" , &s[ i ] ) ;
		MX = max( MX , s[ i ] ) ;
	}
}

void process() {
	int ans = MX ;
	for ( int i = 1 ; i < MX ; i ++ ) {
		int need = 0 ;
		for ( int j = 0 ; j < n ; j ++ ) {
			need += ( s[ j ] - 1 ) / i ;
		}
		ans = min( ans , need + i ) ;
	}
	printf( "%d\n" , ans ) ;
}

int main() {
	int Cases;
	scanf( "%d" , &Cases ) ;
	for ( int cases = 1 ; cases <= Cases ; cases ++ ) {
		init() ;
		printf( "Case #%d: " , cases ) ;
		process() ;
	}
	return 0 ;
}

