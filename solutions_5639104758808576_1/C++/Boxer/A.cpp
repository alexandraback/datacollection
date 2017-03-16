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

typedef vector< int > vi;
typedef long long ll;
typedef pair< int , int > pii;

int main(){
	int cases;
	cin >> cases;
	REP( tc , cases ){
		int n;
		string s;
		cin >> n >> s;
		REP( i , SZ( s ) ) s[ i ] -= '0';
		vi A( all( s ) );
		for( int i = 1 ; i <= n ; ++i ) A[ i ] += A[ i - 1 ];
		int ans = 0 ;
		for( int i = 1 ; i <= n ; ++i ) ans = max( ans , i - A[ i - 1 ] );
		printf( "Case #%d: %d\n" , tc + 1 , ans );
	}
}


