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

map< vi , int > memo;

int dp( vi v ){
	if( v == vi( 10 , 0 ) ) return 0;
	if( memo.count( v ) ) return memo[ v ];
	vi w( v );
	REP( i , 9 ) w[ i ] = w[ i + 1 ];
	w[ 0 ] = w[ 9 ] = 0;
	int &dev = memo[ v ] = 1 + dp( w );
	for( int i = 2 ; i <= 9 ; ++i )
		if( v[ i ] ){
			for( int j = 1 ; j < i ; ++j ){
				w = v;
				w[ i ] --;
				w[ j ] ++;
				w[ i - j ] ++;
				dev = min( dev , 1 + dp( w ) );
			}
		}
	return dev;
}
int main(){
	/*
	vi vis( 10 );
	REP( i , 9 )REP( j , 9 )REP( k , 9 )REP( L , 9 )REP( m , 9 )REP( n , 9 ){
		vi w( 10 );
		w[ i + 1 ] ++;
		w[ j + 1 ] ++;
		w[ k + 1 ] ++;
		w[ L + 1 ] ++;
		w[ m + 1 ] ++;
		w[ n + 1 ] ++;
		dp( w );
		//cout << i << endl;
		if( !vis[ i ] ) cout << i << endl;
		vis[ i ] = 1;
	}
	*/
	int cases;
	sc( cases );
	REP( tc , cases ){
		int n;
		sc( n );
		vi F( 10 , 0 );
		REP( i , n ){
			int x;
			sc( x );
			F[ x ] ++;
		}
		printf( "Case #%d: %d\n" , tc + 1 , dp( F ) );
	}	
}


