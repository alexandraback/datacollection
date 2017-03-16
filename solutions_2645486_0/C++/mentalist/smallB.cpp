#include <cstdio>

int bitmask[ 15 ];
int value[ 15 ];
int E, G, N;

bool increase( int size ) {
  int cnt = 0;
  for( int i = size-1; i >= 0; --i ) {
    if( bitmask[ i ] == 5 ) {
      bitmask[ i ] = 0;
      cnt++;
    } else {
      bitmask[ i ]++;
      return 1;
    }
  }
  return cnt != size;
}

int main( ) {
  freopen( "smallB.in", "r", stdin );
  freopen( "smallB.out", "w", stdout );
  
  int T;
  scanf( "%d", &T );
  
  for( int cs = 1; cs <= T; ++cs ) {
    scanf( "%d %d %d", &E, &G, &N );
    
    for( int i = 0; i < N; ++i ) {
      bitmask[ i ] = 0;
      scanf( "%d", value+i );
    }
    
    int max_gain = 0;
    int tmpE, tmp_gain;
    
    do {
      tmpE = E;
      tmp_gain = 0;
      bool ok = true;
      
      for( int i = 0; i < N; ++i ) {
        if( tmpE <= E ) {
          if( bitmask[ i ] > tmpE ) {
            ok = false;
            break;
          } else {
            tmp_gain += bitmask[ i ] * value[ i ];
            tmpE = tmpE - bitmask[ i ] + G;
          }
        }
      }
      
      if( ok && tmp_gain > max_gain ) {
        max_gain = tmp_gain;
      }
    } while( increase( N ) );
    
    printf( "Case #%d: %d\n", cs, max_gain );
  }
  
  return 0;
}