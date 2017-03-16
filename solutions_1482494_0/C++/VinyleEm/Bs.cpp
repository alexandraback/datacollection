#include <stdio.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>

using namespace std ;
#define lint long long
#define FOREACH(it,v) for( typeof((v).begin()) it = (v).begin() ; it != (v).end() ; it++ )
#define ALL(v) (v).begin(),(v).end()

const int infinity = 0x3fffffff ;
const lint linfinity = 0x3fffffffffffffffLL ;


const int maxn = 11 ;
int n , dp[1<<20] ;
int a[maxn] , b[maxn] ;

int state( int mask , int x ){
	mask >>= x+x ;
	mask &= 3 ;

	return mask ;
}

int rem( int mask , int i ){
	mask &= ~( 3 << (i+i) ) ;
	return mask ;
}

string solveASingleCase(){
	cin >>  n ;
	for( int i = 0 ;i < n ; ++i )
		cin >> a[i] >> b[i] ;
	
	dp[0] = 0 ;
	for( int mask = 1 ; mask < 1<<(2*n) ; mask++ ){
		dp[mask] = infinity ;

		int ps = 0 ;
		for( int i = 0 ;i < n ; i++ ){
			int s = state(mask , i ) ;
			if( s == 0 ) ps += 2 ;
			else if( s == 2 ) ps ++ ;
		}

		for( int i = 0 ;i < n ; i++ )
			if( state(mask , i ) > 0 ){
				int s = state(mask , i ) ;
				if( s >= 2 and b[i] <= ps ){
					dp[mask] = min( dp[mask] , 1 + dp[ rem(mask,i) ] ) ;
				}
				if( s%2 == 1 and a[i] <= ps ){
					dp[mask] = min( dp[mask] , 1 + dp[mask&(~(1<<(i+i)))] )  ;
				}
			}
	}

	int ans = dp[(1<<(2*n))-1 ] ; 
	if( ans >= infinity ) return "Too Bad" ;

	char bf[32] ;
	sprintf( bf , "%d" , ans ) ;
	return string(bf) ;
}

int main(){
	int cases ;
	cin >> cases ;

	for( int cs = 1 ; cs <= cases ; cs++ ){
		cout << "Case #" << cs << ": " << solveASingleCase() << endl ;
	}

	return 0 ;
}
