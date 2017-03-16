#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

FILE *in = fopen( "f.in" , "r" );

int N , A[ 20 ] , Can[ 3000000 ] , Path[ 3000000 ][ 2 ];

void print( int X ){
  if( X == 0 ) return ;
  printf( " %d" ,X - Path[ X ][ 0 ] );
  print( Path[ X ][ 0 ] );
  return ;
}

int main(){
  freopen( "f.out" , "w" , stdout );
  int T;
  fscanf( in , "%d" ,&T );
  
  for( int kase = 1 ; kase <= T ; kase++ ){
    fscanf( in , "%d" ,&N );
    int SUM = 0;
    for( int q = 0 ; q < N ; q++ ){
      fscanf( in , "%d" ,&A[ q ] );
      SUM += A[ q ];
    }
    memset( Can , 0 , sizeof Can );
    Can[ 0 ] = 1;
    for( int q = 0 ; q < N ; q++ ){
      for( int w = SUM - A[ q ] ; w >= 0 ; w-- ){
	if( Can[ w ] ){
	  Can[ w + A[ q ] ] ++;
	  if( Can[ w + A[ q ] ] > 4 ) Can[ w + A[ q ] ] = 4;
	  if( Can[ w + A[ q ] ] <= 2 ){
	    Path[ w + A[ q ] ][ Can[ w + A[ q ] ] - 1 ] = w;
	  }
	}
      }
    }
    printf( "Case #%d:\n" ,kase );
    bool found = 0;
    for( int q = 0 ; !found && q <= SUM ; q++ ){
      if( Can[ q ] >= 2 ){
	printf( "%d" ,q - Path[ q ][ 0 ] );
	print( Path[ q ][ 0 ] );
	printf( "\n" );
	printf( "%d" ,q - Path[ q ][ 1 ] );
	print( Path[ q ][ 1 ] );
	printf( "\n" );
	found = 1;
      }
    }
    if( !found ) printf( "Impossible\n" );
    
  }
  
  return 0;
}
