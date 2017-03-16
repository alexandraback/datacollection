#include <cstdio>
#include <cmath>
#include <inttypes.h>

typedef uintmax_t uint;

int main( ) {
  freopen( "smallA.in", "r", stdin );
  freopen( "smallA.out", "w", stdout );
  
  int T;
  scanf( "%d", &T );
  
  for( int cs = 1; cs <= T; ++cs ) {
    uint R, T;
    scanf( "%ju %ju", &R, &T );
    
    uint lo = 1, hi = 10000000000000000000U;
    uint best = 0;
    
    while( lo < hi ) {
      if( lo == hi-1 ) {
        for( uint i = lo; i <= hi; ++i ) {
          uint tmp = 2*R*i - i + 2*i*i;
          if( tmp <= T && tmp > best ) best = i;
        }
        break;
      }
      
      uint mid = ( lo+hi )/2;
      if( 2*R*mid - mid + 2*mid*mid <= T ) {
        best = mid;
        lo = mid;
      } else {
        hi = mid;
      }
    }
    
    printf( "Case #%d: %ju\n", cs, best ); 
  }
  
  return 0;
}
    