#include <cstdio>

#define MAX 204

int S[MAX];
int N, x;

bool ok( int k, double y ) {
  double left = 1 - y;
  double me = S[k] + x * y;
  for ( int i = 0; i < N; ++i ) {
    if ( i == k ) continue;
    if ( S[i] >= me ) continue;
    left -= (me - S[i]) / x;
    if ( left < 0 ) return true;
  }
  return false;
}

int main(void) {
  int T;
  
  scanf("%d", &T);
  for ( int t = 1; t <= T; ++t ) {
    scanf("%d", &N);
    
    x = 0;
    for ( int i = 0; i < N; ++i ) {
      scanf("%d", S + i );
      x += S[i];
    }
    
    printf("Case #%d:", t);
    
    for ( int i = 0; i < N; ++i ) {
      double low = 0, middle, high = 1;
      for ( int step = 0; step < 50; ++step ) {
        middle = (low + high) / 2;
        if ( ok( i, middle ) )
          high = middle;
        else
          low = middle;
      }
      
      printf(" %lf", 100.0 * (low + high) / 2);
    }
    
    printf("\n");
  }
  return 0;
}
