#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int MAXN = 200 ;
const long long MODULA = 1000000007 ;

int n ;
vector <string> car ;
int g[ 26 ] [ 30 ] ;
bool is_head[ 26 ] [ MAXN ] , is_tail[ 26 ] [ MAXN ] , is_mid[ 26 ] [ MAXN ] , mid_has[ 26 ] [ MAXN ] ;
bool use[ 26 ] , usechar[ 26 ] ; int deg[ 26 ] ;
int count_is_mid[ 26 ] ;

int main() {
	freopen( "B-small-attempt1.in" , "r" , stdin ) ;
	freopen( "B-small-attempt1.out" , "w" , stdout ) ;
	// freopen( "B.in" , "r" , stdin ) ;

	int test_case ;
	cin >> test_case ;
	for ( int t = 1 ; t <= test_case ; t ++ ) {
		cin >> n ;
		car.clear() ;
		for ( int i = 0 ; i < n ; i ++ ) {
			string s ;
			cin >> s ;
			car.push_back( s ) ;
		}

		memset( is_head , false , sizeof( is_head ) ) ;
		memset( is_tail	, false , sizeof( is_tail ) ) ;
		memset( is_mid , false , sizeof( is_mid ) ) ;
		memset( mid_has , false , sizeof( mid_has ) ) ;
		memset( count_is_mid , 0 , sizeof( count_is_mid ) ) ;
		memset( g , 0 , sizeof( g ) ) ;
		memset( deg , 0 , sizeof( deg ) ) ;

		bool cando = true ;
		for ( int i = 0 ; i < n ; i ++ ) {
			int car_l = car[ i ].length() ;
			int fc = car[ i ] [ 0 ] - 'a' , lc = car[ i ] [ car_l - 1 ] - 'a' ;
			bool flag = true ;
			for ( int j = 0 ; j < car_l ; j ++ )
				if ( car[ i ] [ j ] != car[ i ] [ 0 ] )
					flag = false ;
			if ( flag ) {
				is_mid[ lc ] [ i ] = true ;
				count_is_mid[ lc ] ++ ;
				continue ;
			}

			g[ fc ] [ ++ g[ fc ] [ 0 ] ] = lc ;
			deg[ lc ] ++ ;
			is_head[ lc ] [ i ] = true ;
			is_tail[ fc ] [ i ] = true ;
			for ( int j = 0 ; j < car_l ; j ++ )
				if ( car[ i ] [ j ] != car[ i ] [ 0 ] && car[ i ] [ j ] != car[ i ] [ car_l - 1 ] )
					mid_has[ car[ i ] [ j ] - 'a' ] [ i ] = true ;

			memset( usechar , true , sizeof( usechar ) ) ;
			for ( int j = 0 ; j < car_l ; j ++ ) {
				if ( j > 0 && car[ i ] [ j ] != car[ i ] [ j - 1 ] && usechar[ car[ i ] [ j ] - 'a' ] == false )
					cando = false ;
				usechar[ car[ i ] [ j ] - 'a' ] = false ;
			}
		}

		for ( int c = 0 ; c < 26 ; c ++ ) {
			for ( int i = 0 ; i < n ; i ++ )
				for ( int j = 0 ; j < n ; j ++ )
					if ( i != j && mid_has[ c ] [ i ] && ( mid_has[ c ] [ j ] || is_head[ c ] [ j ] || is_tail[ c ] [ j ] ) )
						cando = false ;
			if ( deg[ c ] > 1 ) cando = false ;
			if ( g[ c ] [ 0 ] > 1 ) cando = false ;
		}
/*
		for ( int i = 0 ; i < 26 ; i ++ ) {
			if ( g[ i ] [ 0 ] == 0 ) continue ;
			cout << i << ':' ;
			for ( int j = 1 ; j <= g[ i ] [ 0 ] ; j ++ )
				cout << g[ i ] [ j ] << ' ' ;
			cout << endl;
		}
*/
		if ( cando ) {
			long long ans = 1 ;
			for ( int c = 0 ; c < 26 ; c ++ )
				for ( long long i = 1 ; i <= count_is_mid[ c ] ; i ++ )
					ans = ans * i % MODULA ;

			int part_count = 0 ;
			memset( use , true , sizeof( use ) ) ;
			for ( int c = 0 ; c < 26 ; c ++ )
				if ( deg[ c ] == 0 && g[ c ] [ 0 ] > 0 && use[ c ] ) {
					part_count ++ ;
					int now = c ;
					while ( true ) {
						use[ now ] = false ;
						if ( g[ now ] [ 0 ] == 0 ) break ;
						now = g[ now ] [ 1 ] ;
					}
					if ( ans == 0 ) break ;
				}
			for ( int c = 0 ; c < 26 ; c ++ )
				if ( deg[ c ] > 0 && use[ c ] )
					ans = 0 ;
			for ( int c = 0 ; c < 26 ; c ++ )
				if ( use[ c ] && count_is_mid[ c ] > 0 )
					part_count ++ ;
			for ( long long i = 1 ; i <= part_count ; i ++ )
				ans = ans * i % MODULA ;
			printf( "Case #%d: %lld\n" , t , ans ) ;
		} else 
			printf( "Case #%d: 0\n" , t ) ;
	}
}
