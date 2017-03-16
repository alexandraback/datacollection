#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int a[505];
int b[100000*25];

int main(){
  int T, ca, i, j;
  int N, sum, f;

  scanf("%d\n", &T);

  for ( ca = 1; ca <= T; ca++ ) {
    scanf("%d\n", &N);

    for ( i = 0; i < N; i++ ) {
      scanf("%d\n", &a[i]);
    }

    memset( b, 0, sizeof( b ) );
    sum = 0;

    for ( i = 0; i < ( 1 << N ); i++ ) {
      sum = 0;
      for ( j = 0; j < N; j++ ) {
	if ( ( ( 1 << j ) & ( i ) ) > 0 ) {
	  sum += a[j];
	}
      }

      if ( b[sum] > 0 ) {
	printf("Case #%d:\n", ca );

	for ( f = j = 0; j < N; j++ ) {
	  if ( ( ( 1 << j ) & ( i ) ) > 0 ) {
	    if ( f ) printf(" ");
	    printf("%d", a[j]);
	    f = 1;
	  }
	}
	printf("\n");

	for ( f = j = 0; j < N; j++ ) {
	  if ( ( ( 1 << j ) & ( b[sum] ) ) > 0 ) {
	    if ( f ) printf(" ");
	    printf("%d", a[j]);
	    f = 1;
	  }
	}
	printf("\n");

	break;
      }
      else {
	b[sum] = i;
      }
    }


  }

  return 0;
}
