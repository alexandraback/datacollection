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

double P[111111] , Q[111111] ;
int n , m ;


int main( int argc , char *argv[] )
{
	freopen( "A-small-attempt0.in" , "r" , stdin ) ;
	freopen( "A-small-attempt0.out" , "w" , stdout ) ;
	int TestCase ;
	scanf( "%d" , &TestCase ) ;
	for( int T = 0 ; T < TestCase ; T++ ) {
		scanf( "%d%d" , &m , &n ) ;
		for( int i = 0 ; i < m ; i++ ) {
			scanf( "%lf" , &P[i] ) ;
			P[i] = 1 - P[i] ;
			i == 0 ? Q[i] = 1 : Q[i] = Q[i-1] * ( 1 - P[i-1] ) ;
		}
		double ans = 10000000 ;
		for( int i = 1 ; i <= m ; i++ ) {
			int k = m - i ;
			ans = fmin( ans , (2*n+2+2*i-m)*(1-Q[k])+(n+1+2*i-m)*Q[k] ) ;
		}
		
		ans = fmin( ans , (double)( n + 2 ) ) ;
		double p = Q[m-1] * ( 1 - P[m-1] ) ;
		double ans1 = p * ( n - m + 1 ) + ( 1 - p ) * ( n - m + 1 + n + 1 ) ;
		ans = fmin( ans , ans1 ) ;
		printf( "Case #%d: %lf\n" , T + 1 , ans ) ;
	}
		
			
	return 0;
}
