#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

FILE *in = fopen( "f.in" , "r" );

int N , A[ 222 ] , SUM;
double ans[ 222 ];

double needs( int i , double score ){
  return 100 * (score - A[ i ]) / SUM;
}

bool wins( double score ){
  double add = 0;
  for( int q = 0 ; q < N ; q++ ){
    add += max( 0.0 , needs( q , score ) );
  }
  if( add - 100 >= -1e-9 ) return 1;
  return 0;
}

int main(){
  
  freopen( "f.out" , "w" , stdout );
  int T;
  fscanf( in , "%d" ,&T );
  
  for( int kase = 1 ; kase <= T ; kase++ ){
    fscanf( in , "%d" ,&N );
    SUM = 0;
    for( int q = 0 ; q < N ; q++ ){
      fscanf( in , "%d" ,&A[ q ] );
      SUM += A[ q ];
    }
    double score;
    double s = 0 , e = SUM + SUM;
    for( int iter = 0 ; iter < 100 ; iter++ ){
      double mid = (s + e) / 2;
      if( wins( mid ) ){
	e = mid;
	score = mid;
      }
      else{
	s = mid;
      }
    }
    printf( "Case #%d:" ,kase );
    for( int q = 0 ; q < N ; q++ ){
      printf( " %lf" ,max( 0.0 , needs( q , score ) ) );
    }
    printf( "\n" );
  }
  
  return 0;
}
