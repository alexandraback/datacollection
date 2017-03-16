//by tzupengwang™
#include<bits/stdc++.h>
using namespace std;

#define FO(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
typedef long long ll;
typedef pair<int,int> ii;

int a , b , c ;

void init() {
	scanf( "%d%d%d" , &a , &b , &c ) ;
	if ( b > c ) swap( b , c ) ;
}

bool process() {
	if ( ( b * c ) % a != 0 ) return false ;
	if ( a >= 7 ) return false ;
	else if ( a == 6 ) return b >= 5 || ( b == 4 && c != 4 ) ;
	else if ( a == 5 ) return b >= 3 ;
	else if ( a == 4 ) return b >= 3 && c != 3 ;
	else if ( a == 3 ) return b >= 2 ;
	else if ( a == 2 ) return true ;
	else if ( a == 1 ) return true ;
	return true ;
}

int main() {
	int Cases;
	scanf( "%d" , &Cases ) ;
	for ( int cases = 1 ; cases <= Cases ; cases ++ ) {
		init() ;
		printf( "Case #%d: " , cases ) ;
		if ( process() ) puts( "GABRIEL" ) ;
		else puts( "RICHARD" ) ;
	}
	return 0 ;
}

