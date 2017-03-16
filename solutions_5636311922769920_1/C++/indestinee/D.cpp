/*
 *	Author:
 *		Indestinee
 *	Date:
 *		2016/04/09
 */
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int cas, k, c, s;
int main(){
	freopen( "D-large.in"  , "r" , stdin  );
	freopen( "D-large.out" , "w" , stdout );
	scanf( "%d" , &cas );
	for( int T = 1 ; T <= cas ; T ++ ){
		scanf( "%d%d%d" , &k , &c , &s );
		printf( "Case #%d:" , T );
		if( k == 1 ){
			puts( " 1" );
			continue;
		}
		if( c == 1 ){
			if( s < k )
				puts( " IMPOSSIBLE" );
			else{
				for( int i = 1 ; i <= k ; i ++ )
					printf( " %d" , i );
				puts( "" );
			}
			continue;
		}
		if( s < k - 1 ){
			puts( " IMPOSSIBLE" );
			continue;
		}
		for( int i = 2 ; i <= k ; i ++ )
			printf( " %d" , i );
		puts( "" );
	}
	return 0;
}
