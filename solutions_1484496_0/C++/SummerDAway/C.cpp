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

int A[30] ;
int f[2000000] ;
bool v[2000000] ;
int TestCase , N ;

int sum( int x ) {
	int ret = 0 , i = 0 ;
	
	while( x ) {
		if( x & 1 ) {
			ret += A[i] ;
		}
		x = x >> 1 ;
		i++ ;
	}
	return ret ;
}

void Print( int x , int y ) {
	for( int i = 0 ; i < N ; i++ ) 
	if( ( ( x >> i ) & 1 ) == ( ( y >> i ) & 1 ) &&( ( y >> i ) & 1 ) == 1 ) {
		x = x ^ ( 1 << i ) ;
	 	y = y ^ ( 1 << i ) ;
	}
	int i = 0 ;
	while( x ) {
		if( x & 1 )	{
			printf( "%d" , A[i] ) ;
			if( x > 1 ) {
				printf( " " ) ;
			} else {
				printf( "\n" ) ;
			}
		}
		x = x >> 1 ;
		i++ ;
	}
	i = 0 ;
	while( y ) {
		if( y & 1 )	{
			printf( "%d" , A[i] ) ;
			if( y > 1 ) {
				printf( " " ) ;
			} else {
				printf( "\n" ) ;
			}
		}
		y = y >> 1 ;
		i++ ;
	}
	return ;
}

int main( int argc , char *argv[] )
{
	freopen( "C-small-attempt0.in" , "r" , stdin ) ;
	freopen( "C-small-attempt0.out" , "w" , stdout ) ;
	scanf( "%d" , &TestCase ) ;
	for( int TE = 1 ; TE <= TestCase ; TE++ ) {
		scanf( "%d" , &N ) ;
		for( int i = 0 ; i < N ; i++ ) {
			scanf( "%d" , &A[i] ) ;
		}
		int S = 1 << N ;
		memset( v , 0 , sizeof( v ) ) ;
		printf( "Case #%d:\n" , TE ) ;
		bool flag = true ;
		for( int i = 1 ; i < S ; i++ ) {
			f[i] = sum( i ) ;
			if( v[f[i]] ) {
				flag = false ;
				for( int j = 1 ; j < i ; j++ )
				if( f[j] == f[i] ) {
					Print( i , j ) ;
					break ;
				}
				break ;
			} 
			v[f[i]] = 1 ;
		}
		if( flag ) {
			printf( "impossible\n" ) ;
		}
	}
	return 0;
}
