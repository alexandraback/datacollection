#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double a[205];
int b[205];

int main(){
  int T, ca, N, i;
  double sum, avg, k;
  double neg;
  int count;

  scanf("%d\n", &T);

  for ( ca = 1; ca <= T; ca++ ) {
    scanf("%d\n", &N );

    memset( b, 0, sizeof( b ) );
    sum = 0.0;
    for ( i = 0; i < N; i++ ) {
      scanf( "%lf\n", &a[i] );
      sum += a[i];
    }
    avg = ( sum / N ) * 2;
    neg = 0.0;

    count = 0;
    printf("Case #%d:", ca );
    for ( i = 0; i < N; i++ ) {
      k = ( ( avg - a[i] ) * 100.0 ) / sum;
      if ( k < 0 ) { neg += a[i]; b[i] = 1; }
      else count++;
    }
    avg = ( ( sum * 2 - neg ) / count );
    for ( i = 0; i < N; i++ ) {
      k = ( ( avg - a[i] ) * 100.0 ) / sum;
      if ( k < 0 ) k = 0;
      if ( b[i] ) k = 0;
      printf(" %lf", k );
    }

    printf("\n");
  }

  return 0;
}
