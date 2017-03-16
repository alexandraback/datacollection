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
int TestCase , N , A[30] ;
vector < int > X , Y ;
int F[2222222] ;

inline bool Contain( int s , int k )
{
	return ( s >> k ) & 1 ;
}

int main( int argc, char *argv[] )
{
	freopen( "input.txt" , "r" , stdin ) ;
	freopen( "output.txt" , "w" , stdout ) ;
	scanf( "%d" , &TestCase ) ;
	for ( int Case = 1 ; Case <= TestCase ; Case ++ ) {
		scanf( "%d" , &N ) ;
		for ( int i = 0 ; i < N ; i ++ ) {
			scanf( "%d" , &A[i] ) ;
		}
		memset( F , -1 , sizeof( F ) ) ;
		int S1 = -1 , S2 = -1 ;
		for ( int i = 1 ; i < 1 << N ; i ++ ) {
			int S = 0 ;
			for ( int j = 0 ; j < N ; j ++ )
			if ( i & ( 1 << j ) ) {
				S += A[j] ;
			}
			if ( F[S] == -1 ) {
				F[S] = i ;
			} else {
				S1 = F[S] ;
				S2 = i ;
				break ;
			}
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
			printf( "%d" , X[0] ) ;
			for ( int i = 1 ; i < X.size() ; i ++ ) {
				printf( " %d" , X[i] ) ;
			}
			printf( "\n" ) ;
			printf( "%d" , Y[0] ) ;
			for ( int i = 1 ; i < Y.size() ; i ++ ) {
				printf( " %d" , Y[i] ) ;
			}
			printf( "\n" ) ;
		}
	}
	return 0;
}
