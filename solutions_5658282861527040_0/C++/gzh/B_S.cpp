#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std ;
#define rep( i, j, k ) for( i = j ; i <= k ; ++i )
int T, Case, A, B, C, Ans ;

int main()
{
	int i, j ;
	
	freopen("B-small-attempt1.in","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	for( scanf("%d", &T) ; T-- ; ) {
		Ans = 0 ;
		
		scanf("%d%d%d", &A, &B, &C) ;
		rep( i, 0, A-1 ) 
			rep( j, 0, B-1 ) {
		//		printf("%d %d %d\n", i, j, i&j ) ;
				if( ( i & j ) < C ) 
					++ Ans ;
			}
		printf("Case #%d: %d\n", ++ Case, Ans) ;
	}
//	system("pause") ;
	return 0 ; 	
}
	
