/*
 *	Author:
 *		Indestinee
 *	Date:
 *		2016/04/16
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
const int M = 52;
int vis[2600], a, n, m, cas;
int main(){
	freopen( "B-small-attempt0.in"  , "r" , stdin  );
	freopen( "B-small-attempt0.out" , "w" , stdout );
	scanf( "%d" , &cas );
	for( int T = 1 ; T <= cas ; T ++ ){
		scanf( "%d" , &n );
		m = ( n << 1 ) - 1;
		for( int i = 1 ;i <= m ; i ++ )
			for( int j = 1 ; j <= n ; j ++ ){
				scanf( "%d" , &a );
				vis[a] ^= 1;
			}
		printf( "Case #%d:" , T );
		for( int i = 1 ; i <= 2500 ; i ++ ){
			if( vis[i] ){
				vis[i] ^= 1;
				printf( " %d" , i );
			}
		}
		puts("");
		

	}
	return 0;
}
