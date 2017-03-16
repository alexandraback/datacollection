#include <stdio.h>
#include <stdlib.h>



int mote[ 100 ] = { 0 };
int opsat[ 100 ] = { 0 };


int intcmp( const void *pa, const void *pb )
{
    int a = * (const int*) pa;
    int b = * (const int*) pb;

    if( a < b ) 
	return -1;
    if( a > b )
	return +1;
    return 0;
}


int main( void )
{
    int T;

    scanf( "%d\n", &T );

    for( int test = 1; test <= T; ++test ) {
	int answ = 0;

	int A, N;
	scanf( "%d %d\n", &A, &N );

	for( int k = 0; k < N; ++k ) {
	    scanf( "%d", &mote[ k ] );
	}

	/* Sort motes. */
	qsort( mote, N, sizeof( int ), intcmp );

	if( A > 1 ) {
	    /* Begin to gobble up other motes. */
	    for( int k = 0; k < N; ++k ) {
		if( mote[ k ] >= A ) {
		    /* Can't absorb yet. */
		    int num_growth = 0;
		    while( A <= mote[ k ] ) {
			A += A - 1;
			num_growth += 1;
		    }
		    opsat[ k ] = num_growth;
		} else {
		    opsat[ k ] = 0;
		}
		
		/* Can absorb (now). */
		A += mote[ k ];
	    }

	    /* Prefix sum ops. */
	    int s = 0;
	    for( int k = 0; k < N; ++k ) {
		int v = opsat[ k ];
		opsat[ k ] = s;
		s += v;
	    }
	    int best = s;

	    /* Find cut-off where it is more effective to drop motes. */
	    for( int k = 0; k < N; ++k ) {
		int rem = N - k;
		int newops = rem + opsat[ k ];
		if( newops < best )
		    best = newops;
	    }
	    answ = best;
	} else {
	    answ = N;
	}

	printf( "Case #%d: %d\n", test, answ );
    }

    return 0;
}
