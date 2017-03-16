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
int cas;
long long n, m;
bool vis[10];
bool ok( long long x ){
	int y;
	while( x ){
		y = x % 10;
		x /= 10;
		vis[y] = true;
	}
	for( int i = 0 ; i < 10 ; i ++ )
		if( !vis[i] )
			return false;
	return true;
}
int main(){
	freopen( "A-large.in"  , "r" , stdin  );
	freopen( "A-large.out" , "w" , stdout );
	scanf( "%d" , &cas );
	for( int T = 1 ; T <= cas ; T ++ ){
		scanf( "%I64d" , &n );
		memset( vis , false , sizeof vis );
		if( n == 0 ){
			printf( "Case #%d: INSOMNIA\n" , T );
			continue;
		}
		m = n;
		while( !ok( m ) )
			m += n;
		printf( "Case #%d: %I64d\n" , T , m );
	}
	return 0;
}
