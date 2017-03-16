#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std ;

#define N 2000 + 10

char S[N] , Ans[N] , tmp1[N] , tmp2[N] ;
int T , Len ;

int main() {
	freopen( "A.in" , "r" , stdin ) ;
	freopen( "A.out" , "w" , stdout ) ;
	scanf( "%d" , &T ) ;
	for (int k = 1 ; k <= T ; k ++ ) {
		Ans[0] = '\0' ;
		printf( "Case #%d: " , k ) ;
		scanf( "%s" , S + 1 ) ;
		Len = strlen( S + 1 ) ;
		for (int i = 1 ; i <= Len ; i ++ ) {
			tmp1[0] = S[i] ;
			tmp1[1] = '\0' ;
			strcat( tmp1 , Ans ) ;
			strcpy( tmp2 , Ans ) ;
			tmp2[i-1] = S[i] ;
			tmp2[i] = '\0' ;
			if ( strcmp( tmp1 , tmp2 ) > 0 ) strcpy( Ans , tmp1 ) ;
			else strcpy( Ans , tmp2 ) ;
		}
		printf( "%s\n" , Ans ) ;
	}
	return 0 ;
}
