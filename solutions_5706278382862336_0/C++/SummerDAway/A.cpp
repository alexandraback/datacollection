#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>

using namespace std;

bool multi2( long long x ) {
	bool ret = true ;
	while( x > 1 ) {
		if( x & 1 ) {
			return false ;
		}
		x >>= 1 ;
	}
	return ret ;
}

int main(int argc, char* argv[]) {
	freopen( "A.in" , "r" , stdin ) ;
	freopen( "A.out" , "w" , stdout ) ;
	int TestCase ;
	scanf( "%d" , &TestCase ) ;
	for( int TC = 1 ; TC <= TestCase ; TC++ ) {	
		long long P, Q ;
		scanf( "%lld/%lld" , &P , &Q ) ;
		long long G = __gcd(P, Q) ;
		P /= G ;
		Q /= G ;
		printf( "Case #%d: ", TC ) ;
		if( !multi2(Q) ) {
			printf( "impossible\n" ) ;
			continue ;
		}
		int ans = 0 ;
		while( P < Q ) {
			Q >>= 1 ;
			ans++ ;
		}
		printf( "%d\n" , ans ) ;
	}
	return 0 ;
}

