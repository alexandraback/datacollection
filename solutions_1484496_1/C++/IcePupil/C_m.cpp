#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std ;
#define LS(t) ((t)<<1)
#define RS(t) (((t)<<1)+1)
#define MD(l,r) (((l)+(r))>>1)
#define PI 3.1415926535897932384626433832795
const int MOD = 10000007 ;
int TestCase , N ;
long long A[11111] ;
vector < long long > X , Y ;
map < long long , long long > F ;
long long S1 , S2 ;

inline bool Contain( long long s , int k )
{
	return ( s >> k ) & 1 ;
}

inline bool Search( int k , int K , long long S , long long SUM )
{
	if ( K == 0 ) {
		if ( F.find( SUM ) == F.end() ) {
			F[SUM] = S ;
			return false ;
		} else {
			S1 = F[SUM] ;
			S2 = S ;
			return true ;
		}
	} else {
		for ( int i = k ; i < N ; i ++ ) {
			if ( Search( i + 1 , K - 1 , S | ( 1LL << i ) , SUM + A[i] ) ) {
				return true ;
			}
		}
		return false ;
	}
}

int main( int argc, char *argv[] )
{
	freopen( "input.txt" , "r" , stdin ) ;
	freopen( "output.txt" , "w" , stdout ) ;
	scanf( "%d" , &TestCase ) ;
	for ( int Case = 1 ; Case <= TestCase ; Case ++ ) {
		scanf( "%d" , &N ) ;
		for ( int i = 0 ; i < N ; i ++ ) {
			scanf( "%lld" , &A[i] ) ;
		}
		for ( int i = 0 ; i < N ; i ++ ) {
			int x = rand() % N ;
			int y = rand() % N ;
			swap( A[x] , A[y] ) ;
		}
		N = 50 ;
		S1 = -1 , S2 = -1 ;
		F.clear() ;
		for ( int i = 1 ; i <= N ; i ++ )
		if ( Search( 0 , i , 0LL , 0LL ) ) {
			break ;
		}
		printf( "Case #%d:\n" , Case ) ;
		if ( S1 == -1 ) {
			printf( "Impossible\n" ) ;
		} else {
			X.clear() ;
			Y.clear() ;
			for ( int i = 0 ; i < N ; i ++ ) {
				if ( Contain( S1 , i ) && !Contain( S2 , i ) ) {
					X.push_back( A[i] ) ;
				}
				if ( Contain( S2 , i ) && !Contain( S1 , i ) ) {
					Y.push_back( A[i] ) ;
				}
			}
			printf( "%lld" , X[0] ) ;
			for ( int i = 1 ; i < X.size() ; i ++ ) {
				printf( " %lld" , X[i] ) ;
			}
			printf( "\n" ) ;
			printf( "%lld" , Y[0] ) ;
			for ( int i = 1 ; i < Y.size() ; i ++ ) {
				printf( " %lld" , Y[i] ) ;
			}
			printf( "\n" ) ;
		}
	}
	return 0;
}
