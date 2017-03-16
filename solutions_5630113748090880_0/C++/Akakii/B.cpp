#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std ;

#define N 2500 + 10

int tax[N] , Ans[N] ;
int Test , n ;

int main() {
	freopen( "B.in" , "r" , stdin ) ;
	freopen( "B.out" , "w" , stdout ) ;
	scanf( "%d" , &Test ) ;
	for (int k = 1 ; k <= Test ; k ++ ) {
		memset( tax , 0 , sizeof(tax) ) ;
		memset( Ans , 0 , sizeof(Ans) ) ;
		printf( "Case #%d:" , k ) ;
		scanf( "%d" , &n ) ;
		for (int i = 1 ; i < 2 * n ; i ++ ) {
			int x ;
			for (int j = 1 ; j <= n ; j ++ ) {
				scanf( "%d" , &x ) ;
				tax[x] ^= 1 ;
			}
		}
		for (int i = 1 ; i < N ; i ++ ) {
			if ( tax[i] ) Ans[++Ans[0]] = i ;
		}
		for (int i = 1 ; i <= Ans[0] ; i ++ ) printf( " %d" , Ans[i] ) ;
		printf( "\n" ) ;
	}
	return 0 ;
}
