#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long int64;

int N , M;
int64 A[ 111 ][ 2 ] , B[ 111 ][ 2 ] , SA[ 111 ][ 111 ] , SB[ 111 ][ 111 ];
int64 dp[ 111 ][ 111 ];

int64 getint(){
  int64 x = 0; char c = getchar();
  while( c < '0' || c > '9' ) c = getchar();
  while( c >= '0' && c <= '9' ) x = (x << 1ll) + (x << 3ll) + c - '0' , c = getchar();
  return x;
}

int main(){
  freopen( "f.in" , "r" , stdin );
  freopen( "f.out" , "w" , stdout );
  int T;
  T = getint();
  
  for( int kase = 1 ; kase <= T ; kase++ ){
    N = getint();
    M = getint();
    for( int q = 0 ; q < N ; q++ ){
      A[ q ][ 0 ] = getint();
      A[ q ][ 1 ] = getint();
    }
    for( int q = 0 ; q < M ; q++ ){
      B[ q ][ 0 ] = getint();
      B[ q ][ 1 ] = getint();
    }
    for( int t = 0 ; t <= 100 ; t++ ){
      SB[ t ][ M ] = 0;
      for( int q = M - 1 ; q >= 0 ; q-- ){
	SB[ t ][ q ] = SB[ t ][ q + 1 ];
	if( B[ q ][ 1 ] == t ) SB[ t ][ q ] += B[ q ][ 0 ];
      }
    }
    for( int t = 0 ; t <= 100 ; t++ ){
      SA[ t ][ M ] = 0;
      for( int q = M - 1 ; q >= 0 ; q-- ){
	SA[ t ][ q ] = SA[ t ][ q + 1 ];
	if( A[ q ][ 1 ] == t ) SA[ t ][ q ] += A[ q ][ 0 ];
      }
    }
    for( int q = 0 ; q <= N ; q++ ){
      dp[ q ][ M ] = 0;
    }
    for( int q = 0 ; q <= M ; q++ ){
      dp[ N ][ q ] = 0;
    }
    for( int i = N - 1 ; i >= 0 ; i-- ){
      for( int j = M - 1 ; j >= 0 ; j-- ){
	dp[ i ][ j ] = 0;
	int type = A[ i ][ 1 ];
	for( int q = i ; q <= N ; q++ ){
	  for( int w = j ; w <= M ; w++ ){
	    dp[ i ][ j ] = max( dp[ i ][ j ] , min( SA[ type ][ i ] - SA[ type ][ q ] , SB[ type ][ j ] - SB[ type ][ w ] ) + dp[ q ][ w ] );
	  }
	}
      }
    }
    printf( "Case #%d: %lld\n" ,kase ,dp[ 0 ][ 0 ] );
  }
  
  return 0;
}
