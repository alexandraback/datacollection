#include <cstdio>

bool inc( int *A, int N, int base ) {
  int cnt = 0;
  for( int i = N-1; i >= 0; --i ) {
    if( A[ i ] != base-1 ) {
      A[ i ]++;
      return 1;
    } else {
      A[ i ] = 0;
      cnt++;
    }
  }
  return cnt != N;
}

bool possible( int *A, int N, int req ) {
  if( req == 1 ) return true;
  
  int *bm = new int[ N ];
  for( int i = 0; i < N; ++i ) bm[ i ] = 0;
  while( inc( bm, N, 2 ) ) {
    int prod = 1;
    for( int i = 0; i < N; ++i ) {
      if( bm[ i ] ) {
        prod *= A[ i ];
      }
    }
    if( prod == req ) return 1;
  }
  return 0;
}

int main( ) {
  freopen( "smallC.in", "r", stdin );
  freopen( "smallC.out", "w", stdout );
  
  int T, *A, *B;
  int R, N, M, K;
  
  scanf( "%d", &T );
  scanf( "%d %d %d %d", &R, &N, &M, &K );
  
  A = new int[ N ];
  B = new int[ N ];
  printf( "Case #1:\n" );
  
  for( int ci = 0; ci < R; ++ci ) {
    for( int i = 0; i < K; ++i ) {
      scanf( "%d", A+i );
    }
    for( int i = 0; i < N; ++i ){
      B[ i ] = 0;
    }
    
    do {
      bool ok = true;
      for( int i = 0; i < N; ++i ) {
        if( B[ i ] < 2 ) {
          ok = false;
          break;
        }
      }
      
      /*
      for( int i = 0; i < N; ++i ) {
        printf( "%d", B[ i ] );
      }
      puts( "" );
      */
      
      if( !ok ) continue;
      
      for( int i = 0; i < K; ++i ) {
        if( !possible( B, N, A[ i ] ) ) {
          ok = false;
          break;
        }
      }
      
      if( ok ) {
        for( int i = 0; i < N; ++i ) {
          printf( "%d", B[ i ] );
        }
        puts( "" );
        break;
      }
    } while( inc( B, N, M+1 ) );
  }
  
  return 0;
}
    
    
    
    
    
    
    
  