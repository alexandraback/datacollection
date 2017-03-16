#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std ;
#define LS(t) ((t)<<1)
#define RS(t) (((t)<<1)+1)
#define MD(l,r) (((l)+(r))>>1)
#define PI 3.1415926535897932384626433832795
int TestCase , N , M ;
long long a[111] , b[111] ;
int A[111] , B[111] ;
long long F[111][111] ;

int main( int argc, char *argv[] )
{
	freopen( "input.txt" , "r" , stdin ) ;
	freopen( "output.txt" , "w" , stdout ) ;
	scanf( "%d" , &TestCase ) ;
	for ( int Case = 1 ; Case <= TestCase ; Case ++ ) {
		scanf( "%d%d" , &N , &M ) ;
		for ( int i = 1 ; i <= N ; i ++ ) {
			scanf( "%lld%d" , &a[i] , &A[i] ) ;
		}
		for ( int i = 1 ; i <= M ; i ++ ) {
			scanf( "%lld%d" , &b[i] , &B[i] ) ;
		}
		memset( F , 0 , sizeof( F ) ) ;
		for ( int i = 0 ; i <= N ; i ++ ) {
			for ( int j = 0 ; j <= M ; j ++ ) {
				F[i+1][j] = max( F[i+1][j] , F[i][j] ) ;
				F[i][j+1] = max( F[i][j+1] , F[i][j] ) ;
				if ( A[i+1] == B[j+1] ) {
					int x = i + 1 , y = j + 1 ;
					long long S1 = a[i+1] ;
					long long S2 = b[j+1] ;
					for ( ; x <= N && y <= M ; ) {
						F[x][y] = max( F[x][y] , F[i][j] + min( S1 , S2 ) ) ;
						if ( S1 < S2 ) {
							x ++ ;
							if ( A[x] == A[i+1] ) {
								S1 += a[x] ;
							}
						} else {
							y ++ ;
							if ( B[y] == B[j+1] ) {
								S2 += b[y] ;
							}
						}
					}
				}
			}
		}
		printf( "Case #%d: %lld\n" , Case , F[N][M] ) ;
	}
	return 0;
}
