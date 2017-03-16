#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std ;
#define LL long long 
LL ans, n, m ; 
int T, Case ;

inline LL gcd( LL a, LL b ) 
{
	if( ! b ) return a ;
	return gcd( b, a%b ) ; 	
}

inline bool Check( LL p )
{
	for( ; p != 1 ; ) {
		if( p & 1 ) return false ;
		p >>= 1 ;	
	}
	return true ;
}

int main()
{
	LL d ;
	
	freopen("A-small-attempt0.in","r",stdin) ;
	freopen("output.txt","w",stdout) ;
	
	for( scanf("%d", &T) ; T-- ; ) {
		ans = 1 ;
		
		scanf("%I64d/%I64d", &n, &m) ;
		
		d = gcd( n, m ) ;
		n /= d, m /= d ;
		
		if( Check( m ) ) {
			for( ; ; ) {
				if( n >= ( m >> 1 ) ) 
					break ;
				++ ans ;
				m >>= 1 ; 
			}
			if( ans <= 40 ) 
				printf("Case #%d: %d\n", ++ Case, ans ) ;
			else 
				printf("Case #%d: impossible\n", ++ Case ) ; 
		} else printf("Case #%d: impossible\n", ++ Case ) ;
	}
//	system("pause") ;
	return 0 ; 
}
