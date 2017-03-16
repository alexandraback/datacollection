//------------------------------------------------------------------------------
//  Problem : 
//  User    : 
//  Date    : 
//------------------------------------------------------------------------------


#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define sqr(x) ( (x)*(x) ) ;

int N , A , TestCase ;
double P[10] , T[10] , D , G ;

int main( int argc , char *argv[] )
{
	freopen( "B-small-attempt0.in" , "r" , stdin ) ;
	freopen( "B-small-attempt0.out" , "w" , stdout ) ;
	scanf( "%d" , &TestCase ) ;
	for( int TE = 1 ; TE <= TestCase ; TE++ ) {
		scanf( "%lf%d%d" , &D , &N , &A ) ;
		for( int i = 0 ; i < N ; i++ ) {
			scanf( "%lf%lf" , &T[i] , &P[i] ) ;
		}
		printf( "Case #%d:\n" , TE ) ;
		for( int i = 0 ; i < A ; i++ ) {
			scanf( "%lf" , &G ) ;
			if( N < 2 || P[0] >= D ) {
				printf( "%.8lf\n" , sqrt( 2 * D / G ) ) ;
			} else {
				T[1] = ( D - P[0] ) / ( ( P[1] - P[0] ) / ( T[1] - T[0] ) ) ;
				P[1] = D ;
				double a = 2 * D / sqr( T[1] - T[0] ) ;
				if( a < G ) {
					printf( "%.8lf\n" , T[1] - T[0] ) ;
				} else {
					printf( "%.8lf\n" , sqrt( 2 * D / G ) ) ;
				}
			}
		}
	}
	return 0;
}
