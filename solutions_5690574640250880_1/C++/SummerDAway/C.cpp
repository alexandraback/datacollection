#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std ;

int TestCase ;
int N , M , K ;
int ans[55][55] ;


int main( int argc , char* argv[] ) {
	freopen( "C.in" , "r" , stdin ) ;
	freopen( "C.out" , "w" , stdout ) ;
	scanf( "%d" , &TestCase ) ;
	for( int TC = 1 ; TC <= TestCase ; TC++ ) {
		scanf( "%d%d" , &N , &M ) ;
		scanf( "%d" , &K ) ;
		printf( "Case #%d:\n" , TC ) ;
		if( K == N*M ) {
			for( int i = 1 ; i <= N ; i++ , printf( "\n" ) )
				for( int j = 1 ; j <= M ; j++ ) {
					printf( "*" ) ;
				}
			continue ;
		}
		if( N*M-K == 1 ) {
			for( int i = 1 ; i <= N ; i++, printf( "\n" ) )
				for( int j = 1 ; j <= M ; j++ ) {
					if( i == 1 && j == 1 ) {
						printf( "c" ) ;
					} else {
						printf( "*" ) ;
					}
				}
			continue ;
		}

		memset( ans , 0 , sizeof( ans ) ) ;
		if( N == 1 ) {
			for( int i = 1 ; i <= K ; i++ ) {
				printf( "*" ) ;
			}
			for( int i = K + 1 ; i < M ; i++ ) {
				printf( "." ) ;
			}
			printf( "c\n" ) ;
			continue ;
		}
		if( M == 1 ) {
			for( int i = 1 ; i <= K ; i++ ) {
				printf( "*\n" ) ;
			}
			for( int i = K + 1 ; i < N ; i++ ) {
				printf( ".\n" ) ;
			}
			printf( "c\n" ) ;
			continue ;
		}
		if( N == 2 || M == 2 ) {
			if( (K & 1) || (N*M-K ==2) ) {
				printf( "Impossible\n" ) ;
				continue ;
			}
			if( N > 2 ) {
				for( int i = K >> 1 ; i >= 1 ; i-- ) {
					printf( "**\n" ) ;
				}
				for( int i = (K >> 1) + 1 ; i < N ; i++ ) {
					printf( "..\n" ) ;
				}
				printf( ".c\n" ) ;
			} else {
				for( int i = K >> 1 ; i >= 1 ; i-- ) {
					printf( "*" ) ;
				}
				for( int i = ( K >> 1 ) + 1 ; i <= M ; i++ ) {
					printf( "." ) ;
				}
				printf( "\n" ) ;
				for( int i = K >> 1 ; i >= 1 ; i-- ) {
					printf( "*" ) ;
				}
				for( int i = ( K >> 1 ) + 1 ; i < M ; i++ ) {
					printf( "." ) ;
				}
				printf( "c\n" ) ;
			}
			continue ;
		}

		int t = N*M - K ;
		if( t < 4 || t == 5 || t == 7 ) {
			printf( "Impossible\n" ) ;
			continue ;
		}
		for( int i = 1 ; i <= 2 ; i++ )
		for( int j = 1 ; j <= 2 ; j++ ) {
			ans[i][j] = 1 ;
		}
		t -= 4 ;
		if( t > 0 ) {
			ans[3][1] = ans[3][2] = 1 ;
			t -= 2 ;
		}
		if( t > 0 ) {
			ans[1][3] = ans[2][3] = 1 ;
			t -= 2 ;
		}
		if( t > 0 ) {
			int k = min( N - 3 , t >> 1 ) ;
			for( int i = 1 ; i <= k ; i++ ) {
				ans[i+3][1] = ans[i+3][2] = 1 ;
			}
			t -= k<<1 ;
			if( t > 0 ) {
				k = min( M - 3 , t >> 1 ) ;
				for( int i = 1 ; i <= k ; i++ ) {
					ans[1][i+3] = ans[2][i+3] = 1 ;
				}
				t -= k << 1 ;
				if( t > 0 ) {
					for( int i = 1 ; i <= t/(M-2) ; i++ ) {
						for( int j = 1 ; j <= M - 2 ; j++ ) {
							ans[i+2][j+2] = 1 ;
						}
					}
					for( int i = 1 ; i <= t%(M-2) ; i++ ) {
						ans[t/(M-2)+1+2][i+2] = 1 ;
					}
				}
			}
		}
		for( int i = 1 ; i <= N ; i++ , printf( "\n" ) )
		for( int j = 1 ; j <= M ; j++ ) {
			if( i == 1 && j == 1 ) {
				printf( "c" ) ;
			} else {
				printf( ans[i][j] == 1 ? "." : "*" ) ;
			}
		}
	}
	return 0 ;
}



