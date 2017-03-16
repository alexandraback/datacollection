#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

FILE *in = fopen( "f.in" , "r" );

int N , adj[ 1111 ][ 1111 ] , nadj[ 1111 ] , dp[ 1111 ];

void fill( int i ){
  if( dp[ i ] == 2 ) return ;
  dp[ i ] ++;
  for( int q = 0 ; q < nadj[ i ] ; q++ ){
    fill( adj[ i ][ q ] );
  }
  return ;
}

int main(){
  freopen( "f.out" , "w" , stdout );
  int T;
  fscanf( in , "%d" ,&T );
  
  for( int kase = 1 ; kase <= T ; kase++ ){
    fscanf( in , "%d" ,&N );
    for( int q = 0 ; q < N ; q++ ){
      fscanf( in , "%d" ,&nadj[ q ] );
      for( int w = 0 ; w < nadj[ q ] ; w++ ){
	fscanf( in , "%d" ,&adj[ q ][ w ] );
	adj[ q ][ w ] --;
      }
    }
    bool YES = 0;
    for( int q = 0 ; !YES && q < N ; q++ ){
      memset( dp , 0 , sizeof dp );
      fill( q );
      for( int w = 0 ; w < N ; w++ ){
	if( dp[ w ] >= 2 ){
	  YES = 1;
	  break;
	}
      }
    }
    if( YES ) printf( "Case #%d: Yes\n" ,kase );
    else printf( "Case #%d: No\n" ,kase );
  }
  
  return 0;
}
