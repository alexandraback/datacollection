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

int A[111] ;
int N , S , B ; 
int T ;

int main( int argc , char *argv[] )
{
	freopen( "B-small-attempt0.in" , "r" , stdin ) ;
	freopen( "B-small-attempt0.out" , "w" , stdout ) ;
	scanf( "%d" , &T ) ;
	for( int te = 1 ; te <= T ; te++ ) {
		int ans = 0 , M = 0 ;
		scanf( "%d%d%d" , &N , &S , &B ) ;
		for( int i = 0 ; i < N ; i++ ) {
			int x ;
			scanf( "%d" , &x ) ;
			if( x % 3 == 1 ) {
				if( x/3+1 >= B ) {
					ans++ ;
				}
			} else {
				A[M++] = x ;
			}
		}
		sort( A , A + M ) ;
		for( int i = M - 1 ; i >= 0 ; i-- ) {
			if( A[i] % 3 == 0 ) {
				if( A[i]/3 >= B ) {
					ans++ ;
				} else {
					if( A[i]/3+1 >= B && S > 0 && A[i] > 0 ) {
						S-- ;
						ans++ ;
					}
				}
			} else {
				if( A[i]/3 + 1 >= B ) {
					ans++ ;
				} else {
					if( A[i]/3 + 2 >= B && S > 0 ) {
						S-- ;
						ans++ ;
					}
				}
			}
		}
		printf( "Case #%d: %d\n" , te , ans ) ;
	}
	return 0;
}
