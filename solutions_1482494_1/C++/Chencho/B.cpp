#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 100005

int caso() {
	int N ;
	int arr[lim][2], usd[lim][2], rem ;
	int carga = 0 ;
	int res = 0 ;
	
	scanf("%d", &N ) ;
	rem = 2*N ;
	for( int i=0; i<N; i++ ) {
		for( int j=0; j<2; j++ ) {
			scanf("%d", &arr[i][j] ) ;
			usd[i][j] = 0 ;
		}
	}
	
	while( rem ) {
		int pos = -1, w ;
		for( int i=0; i<N; i++ ) {
			if( !usd[i][1] && arr[i][1]<=carga ) {
				pos = i ;
				break ;
			}
		}
		
		if( pos!=-1 ) {
			res ++ ;
			rem -= 2 ;
			carga += 2 ;
			if( usd[pos][0] ) {
				rem ++ ;
				carga -- ;
			}
			usd[pos][0] = 1 ;
			usd[pos][1] = 1 ;			
			continue ;
		}
		
		w = -(1<<30) ;
		for( int i=0; i<N; i++ ) {
			if( !usd[i][0] && arr[i][0]<=carga ) {
				if( w<arr[i][1] ) {
					pos = i ;
					w = arr[i][1] ;
				}
			}
		}
		
		if( pos!=-1 ) {
			res ++ ;
			rem -- ;
			carga ++ ;
			usd[pos][0] = 1 ;
			continue ;
		}
		
		return -1 ;
	}
	
	return res ;
}

int main() {
	int T ;
	
	scanf("%d", &T )  ;
	for( int i=1; i<=T; i++ ) {
		int tmp = caso() ;
		if( tmp!=-1 )
			printf("Case #%d: %d\n", i, tmp ) ;
		else
			printf("Case #%d: Too Bad\n", i ) ;
	}
	
	return 0 ;
}
