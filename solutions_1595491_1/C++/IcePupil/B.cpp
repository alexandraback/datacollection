/**
 *	Author	:
 *		Pan Yuchao
 *	Date	:
 *		2012-04-14
 *	Description	:
 *		Problem B. Dancing With the Googlers
 *		Qualification Round 2012
 */
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
int N , S , p , F[ 111 ][ 111 ] ;
int TestCase ;
vector < int > A[ 33 ] , B[ 33 ] , C[ 33 ] ;

int main( int argc, char *argv[] )
{
	freopen( "input.txt" , "r" , stdin ) ;
	freopen( "output.txt" , "w" , stdout ) ;
	for ( int i = 0 ; i <= 10 ; i ++ ) {
		for ( int j = i ; j <= 10 && j <= i + 2 ; j ++ ) {
			for ( int k = j ; k <= 10 && k <= i + 2 ; k ++ ) {
				A[ i + j + k ].push_back( i ) ;
				B[ i + j + k ].push_back( j ) ;
				C[ i + j + k ].push_back( k ) ;
			}
		}
	}
	scanf( "%d" , &TestCase ) ;
	for ( int Case = 1 ; Case <= TestCase ; Case ++ ) {
		scanf( "%d%d%d" , &N , &S , &p ) ;
		memset( F , -2 , sizeof( F ) ) ;
		F[ 0 ][ 0 ] = 0 ;
		for ( int i = 0 ; i < N ; i ++ ) {
			int t ;
			scanf( "%d" , &t ) ;
			for ( int j = 0 ; j <= i ; j ++ )
			if ( F[ i ][ j ] >= 0 ) {
				for ( int k = 0 ; k < A[ t ].size() ; k ++ ) {
					int jj = j + ( C[ t ][ k ] - A[ t ][ k ] == 2 ) ;
					int kk = F[ i ][ j ] + ( C[ t ][ k ] >= p ) ;
					F[ i + 1 ][ jj ] = max( F[ i + 1 ][ jj ] , kk ) ;
				}
			}
		}
		printf( "Case #%d: %d\n" , Case , F[ N ][ S ] ) ;
	}
	return 0;
}
