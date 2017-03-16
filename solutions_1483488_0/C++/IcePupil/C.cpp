/**
 *	Author	:
 *		Pan Yuchao
 *	Date	:
 *		2012-04-14
 *	Description	:
 *		Problem C. Recycled Numbers
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
int TestCase ;
int T[ 10 ][ 3000000 ] ;

inline int getLength( int n )
{
	int len = 0 ;
	for ( ; n > 0 ; n /= 10 , len ++ ) ;
	return len ;
}

inline int Change( int n , int l )
{
	int b = 1 ;
	for ( int i = 1 ; i < l ; i ++ ) {
		b *= 10 ;
	}
	int ret = n ;
	for ( int i = 1 ; i < l ; i ++ ) {
		int a = n / b ;
		n -= a * b ;
		n = n * 10 + a ;
		ret = min( ret , n ) ;
	}
	return ret ;
}

int main( int argc, char *argv[] )
{
	scanf( "%d" , &TestCase ) ;
	for ( int Case = 1 ; Case <= TestCase ; Case ++ ) {
		int A , B ;
		scanf( "%d%d" , &A , &B ) ;
		memset( T , 0 , sizeof( T ) ) ;
		for ( int i = A ; i <= B ; i ++ ) {
			int l = getLength( i ) ;
			T[ l ][ Change( i , l ) ] ++ ;
		}
		long long ret = 0 ;
		for ( int l = 0 ; l < 10 ; l ++ ) {
			for ( int i = 0 ; i < 2000000 ; i ++ )
			if ( T[ l ][ i ] ) {
				long long x = T[ l ][ i ] ;
				ret += x * ( x - 1 ) / 2 ;
			}
		}
		printf( "Case #%d: %lld\n" , Case , ret ) ;
	}
	return 0;
}
