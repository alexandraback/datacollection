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

struct Node{
	int a , b , c , d;
	Node(){}
	Node( int a , int b , int c , int d ) : a( a ) , b( b ) , c( c ) , d( d ){}
};
void get( int a1 , int b1 , int c1 , int d1 , int a2 , int b2 , int c2 , int d2 , int &a3 , int &b3 , int &c3 , int &d3 ){
	a3 = a1 * a2 - b1 * b2 - c1 * c2 - d1 * d2;
	b3 = a1 * b2 + b1 * a2 + c1 * d2 - d1 * c2;
	c3 = a1 * c2 - b1 * d2 + c1 * a2 + d1 * b2;
	d3 = a1 * d2 + b1 * c2 - c1 * b2 + d1 * a2;
}
Node operator * ( const Node &x , const Node &y ){
	Node z;
	get( x.a , x.b , x.c , x.d , y.a , y.b , y.c , y.d , z.a , z.b , z.c , z.d );
	return z;
}
bool operator == ( const Node &x , const Node &y ){
	return x.a == y.a && x.b == y.b && x.c == y.c && x.d == y.d;
}
bool operator != ( const Node &x , const Node &y ){
	return !( x == y );
}
Node pow( Node a , ll b ){
	Node ans( 1 , 0 , 0 , 0 );
	while( b ){
		if( b & 1 ) ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}
int main(){
	int cases;
	cin >> cases;
	REP( tc , cases ){
		int n;
		ll L;
		cin >> n >> L;
		string s;
		cin >> s;
		if( L <= 4 ) {
			string t;
			REP( i , L ) t += s;
			s = t;
			n *= L;
			vector< Node > V( n );
			REP( i , n ){
				if( s[ i ] == 'i' ) V[ i ] = Node( 0 , 1 , 0 , 0 );
				if( s[ i ] == 'j' ) V[ i ] = Node( 0 , 0 , 1 , 0 );
				if( s[ i ] == 'k' ) V[ i ] = Node( 0 , 0 , 0 , 1 );
			}
			int a = -1 , b = -1;
			Node T( 1 , 0 , 0 , 0 );
			REP( i , n ){
				T = T * V[ i ];
				if( T == Node( 0 , 1 , 0 , 0 ) ){
					a = i;
					break;
				}
			}
			T = Node( 1 , 0 , 0 , 0 );
			for( int i = n - 1 ; i >= 0 ; --i ){
				T = V[ i ] * T;
				if( T == Node( 0 , 0 , 0 , 1 ) ){
					b = i;
					break;
				}
			}
			T = Node( 1 , 0 , 0 , 0 );
			REP( i , n ) T = T * V[ i ];
			if( T != Node( -1 , 0 , 0 , 0 ) ){
				printf( "Case #%d: NO\n" , tc + 1 );
				continue;
			}
			if( a == -1 || b == -1 ){
				printf( "Case #%d: NO\n" , tc + 1 );
				continue;
			}
			if( a < b ) printf( "Case #%d: YES\n" , tc + 1 );
			else printf( "Case #%d: NO\n" , tc + 1 );
		}else{
			string t;
			REP( i , 4 ) t += s;
			s = t;
			n *= 4;
			vector< Node > V( n );
			REP( i , n ){
				if( s[ i ] == 'i' ) V[ i ] = Node( 0 , 1 , 0 , 0 );
				if( s[ i ] == 'j' ) V[ i ] = Node( 0 , 0 , 1 , 0 );
				if( s[ i ] == 'k' ) V[ i ] = Node( 0 , 0 , 0 , 1 );
			}
			ll a = -1 , b = -1;
			Node T( 1 , 0 , 0 , 0 );
			REP( i , n ){
				T = T * V[ i ];
				if( T == Node( 0 , 1 , 0 , 0 ) ){
					a = i;
					break;
				}
			}
			T = Node( 1 , 0 , 0 , 0 );
			ll ct = 0;
			for( int i = n - 1 , pos = 0 ; i >= 0 ; --i , pos ++ ){
				T = V[ i ] * T;
				if( T == Node( 0 , 0 , 0 , 1 ) ){
					ct = pos;
					b = i;
					break;
				}
			}
			T = Node( 1 , 0 , 0 , 0 );
			n /= 4;
			REP( i , n ) T = T * V[ i ];
			T = pow( T , L );
			if( T != Node( -1 , 0 , 0 , 0 ) ){
				printf( "Case #%d: NO\n" , tc + 1 );
				continue;
			}
			if( a == -1 || b == -1 ){
				printf( "Case #%d: NO\n" , tc + 1 );
				continue;
			}
			b = n * L - 1 - ct;
			if( a < b ) printf( "Case #%d: YES\n" , tc + 1 );
			else printf( "Case #%d: NO\n" , tc + 1 );
		}
	}
}


