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
int N , A[1111111] ;

int main( int argc, char *argv[] )
{
	freopen( "input.txt" , "r" , stdin ) ;
	freopen( "output.txt" , "w" , stdout ) ;
	int TestCase , nCase = 0 ;
	scanf( "%d" , &TestCase ) ;
	while ( TestCase -- ) {
		scanf( "%d" , &N ) ;
		int S = 0 ;
		for ( int i = 0 ; i < N ; i ++ ) {
			scanf( "%d" , &A[i] ) ;
			S += A[i] ;
		}
		double L = 0 , R = 1e10 ;
		for ( int i = 0 ; i < 100 ; i ++ ) {
			double M = ( L + R ) / 2.0 ;
			double T = 0 ;
			for ( int j = 0 ; j < N ; j ++ )
			if ( A[j] < M ) {
				T += M - A[j] ;
			}
			if ( T > S ) {
				R = M ;
			} else {
				L = M ;
			}
		}
		printf( "Case #%d:" , ++ nCase ) ;
		double T = ( L + R ) / 2.0 ;
		for ( int i = 0 ; i < N ; i ++ ) {
			if ( A[i] > T ) {
				printf( " %.6lf" , 0.0 ) ;
			} else {
				printf( " %.6lf" , ( T - A[i] ) / S * 100.0 ) ;
			}
		}
		printf( "\n" ) ;
	}
	return 0;
}
