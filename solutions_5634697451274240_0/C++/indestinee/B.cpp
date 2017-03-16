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
int cas, n, m;
char s[200], p, delta = '+' ^ '-';
int main(){
	freopen( "B-small-attempt0.in"  , "r" , stdin  );
	freopen( "B-small-attempt0.out" , "w" , stdout );
	scanf( "%d" , &cas );
	s[0] = '1';
	for( int T = 1 ; T <= cas ; T ++ ){
		scanf( "%s" , s + 1 );
		n = strlen( s + 1 ), m = 0;
		for( int i = 1 ; i <= n ; i ++ )
			if( s[i] != s[i-1] )
				s[++m] = s[i];
		n = m, p = '+';
		printf( "Case #%d: %d\n" , T , m - ( s[m] == p ? 1 : 0 ) );
	}
	return 0;
}
