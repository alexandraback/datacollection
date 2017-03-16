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

set<int> S ;


int shiftleft( int x , int k ) {
	int y = 1 ;
	while( k ) {
		y *= 10 ;
		k-- ;
	}
	k = y / 10 ;
	x = ( x % 10 ) * k + x / 10 ;
	return x ;
}

int bits( int x ) {
	int ret = 0 ;
	while( x ) {
		x /= 10 ;
		ret++ ;
	}
	return ret ;
}

int main( int argc , char *argv[] )
{
	freopen( "C-small-attempt0.in" , "r" , stdin ) ;
	freopen( "C-small-attempt0.out" , "w" , stdout ) ;
	int T , A , B ;
	scanf( "%d" , &T ) ;
	for( int te = 1 ; te <= T ; te++ ) {
		scanf( "%d%d" , &A , &B ) ;
		int ans = 0 ;
		for( int i = A ; i < B ; i++ ) {
			int k = bits( i ) ;
			int n = i ;
			S.clear() ;
			for( int j = 0 ; j < k ; j++ ) {
				n = shiftleft( n , k ) ;
				//printf( "%d %d\n" , i , n ) ;
				if( n > i && n <= B && S.find( n ) == S.end() ) {
					ans++ ;
					S.insert( n ) ;
				}
			}
		}
		printf( "Case #%d: %d\n" , te , ans ) ;
	}
				
	return 0;
}
