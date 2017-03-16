//by tzupengwang™
#include<bits/stdc++.h>
using namespace std;

#define FO(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
typedef long long ll;
typedef pair<int,int> ii;

int n ;
char s[ 10000 ] ;

void init() {
	scanf( "%d%s" , &n , s ) ;
}

void process() {
	int st = 0 , ans = 0 ;
	for ( int i = 0 ; i <= n ; i ++ ) {
		int now = s[ i ] - '0' ;
		if ( st < i ) ans += i - st , st = i ;
		st += now ;
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

