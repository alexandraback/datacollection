#include <stdio.h>



int lawn[ 100 ][ 100 ];
int N, M;



/* Stupid brute force approach. The inputs are tiny and the complexity
 * of this algorithm is cubic (for square lawns), which should work
 * just fine. */
const char *analyze( void )
{
    /* For each square metre... */
    for( int r0 = 0; r0 < N; ++r0 ) {
	for( int c0 = 0; c0 < M; ++c0 ) {
	    int h0 = lawn[ r0 ][ c0 ];
	    int ok = 2;

	    /* Check row. */
	    for( int c = 0; c < M && ok; ++c ) {
		if( lawn[ r0 ][ c ] > h0 ) {
		    ok -= 1;
		    break;
		}
	    }

	    /* Check column. */
	    for( int r = 0; r < N && ok; ++r ) {
		if( lawn[ r ][ c0 ] > h0 ) {
		    ok -= 1;
		    break;
		}
	    }

	    if( ! ok )
		return "NO";
	}
    }
    return "YES";
}


int main( void )
{
    /* Read number of test cases. */
    int num_cases;
    scanf( "%d", &num_cases );

    /* For each test case... */
    for( int test = 1; test <= num_cases; ++test ) {

	/* Read size of lawn. */
	scanf( "%d %d\n", &N, &M );

	/* Read lawn. */
	for( int r = 0; r < N; ++r ) {
	    for( int c = 0; c < M; ++c ) {
		scanf( "%d", &lawn[ r ][ c ] );
	    }
	    scanf( "\n" );
	}

	/* Analyze lawn. */
	const char *outcome = analyze( );

	/* Print results. */
	printf( "Case #%d: %s\n", test, outcome );
    }

    return 0;
}
