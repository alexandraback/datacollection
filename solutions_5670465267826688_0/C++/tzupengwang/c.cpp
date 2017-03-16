//by tzupengwang™
#include<bits/stdc++.h>
using namespace std;

#define FO(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
typedef long long ll ;
typedef pair<int,int> ii ;
typedef pair< char , char > cc ;

int mp[ 6 ][ 6 ] = {
	{ 0 , 0 , 0 , 0 , 0 } ,
	{ 0 , 1 , 2 , 3 , 4 } ,
	{ 0 , 2 , -1 , 4 , -3 } ,
	{ 0 , 3 , -4 , -1 , 2 } ,
	{ 0 , 4 , 3 , -2 , -1 } } ;

int L , X ;
char s[ 10005 ] ;

void init() {
	ll tmp ;
	scanf( "%d%lld%s" , &L , &tmp , s ) ;
	X = (int)min( 8LL + tmp % 4 , tmp ) ;
}

void process() {
	int now = 1 , sign = 1 ;
	bool one = false , two = false ;
	for ( int i = 0 ; i < X ; i ++ ) {
		for ( int j = 0 ; j < L ; j ++ ) {
			int next ;
			if ( s[ j ] == 'i' ) next = 2 ;
			else if ( s[ j ] == 'j' ) next = 3 ;
			else next = 4 ;
			int mul = mp[ now ][ next ] ;
			now = abs( mul ) ; sign *= ( mul < 0 ) ? -1 : 1 ;
			if ( !one && now == 2 && sign == 1 ) one = true ;
			if ( one && !two && now == 4 && sign == 1 ) two = true ;
		}
	}
	if ( one && two && now == 1 && sign == -1 ) puts( "YES" ) ;
	else puts( "NO" ) ;
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

