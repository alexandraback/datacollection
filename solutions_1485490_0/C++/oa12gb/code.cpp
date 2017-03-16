#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

FILE *in = fopen( "f.in" , "r" );

typedef long long int64;

int N , M;
int64 A[ 111 ][ 2 ] , B[ 111 ][ 2 ] , SA[ 111 ][ 111 ] , SB[ 111 ][ 111 ];
int64 dp[ 111 ][ 111 ];

int64 f( int i , int j ){
  if( i == N || j == M ) return 0;
  int64 &ret = dp[ i ][ j ];
  if( ret != -1 ) return ret;
  ret = 0;
  
  for( int k = j ; k <= M ; k++ ){
    for( int e = i ; e <= N ; e++ ){
      int type = A[ i ][ 1 ];
      int64 tmp = min( SA[ type ][ i ] - SA[ type ][ e ]  , SB[ type ][ j ] - SB[ type ][ k ] ) + f( e , k );
      ret = max( ret , tmp );
    }
  }
  
  return ret;
}

int main(){
  freopen( "f.out" , "w" , stdout );
  int T;
  fscanf( in , "%d" ,&T );
  
  for( int kase = 1 ; kase <= T ; kase++ ){
    fscanf( in , "%d%d" ,&N ,&M );
    for( int q = 0 ; q < N ; q++ ){
      fscanf( in , "%lld%lld" ,&A[ q ][ 0 ] ,&A[ q ][ 1 ] );
    }
    for( int q = 0 ; q < M ; q++ ){
      fscanf( in , "%lld%lld" ,&B[ q ][ 0 ] ,&B[ q ][ 1 ] );
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
    memset( dp , -1 , sizeof dp );
    int64 res = f( 0 , 0 );
    printf( "Case #%d: %lld\n" ,kase ,res );
  }
  
  return 0;
}
