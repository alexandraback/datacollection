#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define INF (1<<29)

typedef vector< int > vi;
typedef long long ll;
typedef pair< int , int > pii;

bool f( int n , int m , int R ){
	if( n % 3 != 0 ) return 0;
	if( (n / 3)%2 == 0 ){
		if( m == 1 ) return 0;
		return 1;
	}else{
		if( m % 2 == 0 ) return 1;
		return 0;
	}
}
bool iCanFeel( int n , int m , int R ){
	if( R >= 4 ) return 0;
	if( R == 1 ) return 1;
	if( R == 2 ) {
		if( (n * m) % 2 == 0 ) return 1;
		return 0;
	}
	if( (n * m) % 3 != 0 ) return 0;
	if( f( n , m , R ) ) return 1;
	if( f( m , n , R ) ) return 1;
	return 0;
}
int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int x , R , C;
		sc( x ) , sc( R ) , sc( C );
		printf( "Case #%d: " , tc + 1 );
		puts( iCanFeel( R , C , x ) ? "GABRIEL" : "RICHARD" );
	}
}

