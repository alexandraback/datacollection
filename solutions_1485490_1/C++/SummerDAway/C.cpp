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

long long f[111][111] ;
long long X[111] , Y[111] , A[111] , B[111] ;
int TestCase , N , M ;

int main( int argc , char *argv[] )
{
	freopen( "C-large.in" , "r" , stdin ) ;
	freopen( "C-large.out" , "w" , stdout ) ;
	scanf( "%d" , &TestCase ) ;
	for( int TE = 1 ; TE <= TestCase ; TE++ ) {
		scanf( "%d%d" , &N , &M ) ;
		memset( f , 0 , sizeof( f ) ) ;
		for( int i = 1 ; i <= N ; i++ ) {
			scanf( "%lld%lld" , &X[i] , &A[i] ) ;
		}
		for( int i = 1 ; i <= M ; i++ ) {
			scanf( "%lld%lld" , &Y[i] , &B[i] ) ;
		}
		for( int i = 1 ; i <= N ; i++ )
		for( int j = 1 ; j <= M ; j++ ) {
			f[i][j] = max( f[i][j] , f[i-1][j] ) ;
			f[i][j] = max( f[i][j] , f[i][j-1] ) ;
			if( A[i] == B[j] ) {
				long long x = X[i] ;
				long long y = Y[j] ;
				int t = i , k = j ;
				while( t <= N && k <= M ) {
					f[t][k] = max( f[t][k] , f[i-1][j-1] + min( x , y ) ) ;
					if( x < y ) {
						t++ ;
						if( A[t] == A[i] ) {
							x = x + X[t] ;
						}
					} else {
						k++ ;
						if( B[k] == B[j] ) {
							y = y + Y[k] ;
						}
					}
				}
			}
		}
		printf( "Case #%d: %lld\n" , TE , f[N][M] ) ;
	}
	return 0;
}
