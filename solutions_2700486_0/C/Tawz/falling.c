#include <stdio.h>
#include <stdlib.h>




int fX[ 20 ];
int fY[ 20 ];



int main( void )
{
    int T;

    scanf( "%d\n", &T );
    for( int test = 1; test <= T; ++test ) {

	/* Read input. */

	int N, X, Y;
	scanf( "%d %d %d\n", &N, &X, &Y );

	/* Solve problem. */

	int num_cases = (1 << N);
	int num_cases_with_diamonds_at_XY = 0;
	int num_real_cases = 0;

	for( int path = 0; path < num_cases; ++path ) {
	    //printf( "PATH %08x\n", path );
	    int invalid = 0;
	    for( int d = 0; d < N && ! invalid; ++d ) {
		int dir = (path >> d) & 0x1;
		if( dir == 0 )
		    dir = -1;

		/* ==== Simulate. */

		int dX = 0;
		int dY = 0;

		/* Find Y pos of fixed diamond at given X. */
		for( int k = 0; k < d; ++k ) {
		    if( fX[ k ] == dX ) {
			if( fY[ k ] + 2 > dY ) {
			    dY = fY[ k ] + 2;
			}
		    }
		}


		int can_move_left = 1;
		int can_move_right = 1;
		int at_ground_level = (dY == 0);
		for( int k = 0; k < d; ++k ) {
		    if( fX[ k ] == dX - 1 && fY[ k ] == dY - 1 ) {
			can_move_left = 0;
		    }
		    if( fX[ k ] == dX + 1 && fY[ k ] == dY - 1 ) {
			can_move_right = 0;
		    }
		}


		if( at_ground_level || (! can_move_left && ! can_move_right) ) {
		    if( dir == -1 ) {
			/* Stay here. */
			fX[ d ] = dX;
			fY[ d ] = dY;
		    } else {
			/* Invalid. */
			invalid = 1;
		    }
		} else if( dir == -1 && ! can_move_left ) {
		    invalid = 1;
		} else if( dir == 1 && ! can_move_right ) {
		    invalid = 1;
		} else {
		    for( int num_moves = 0; ; ++num_moves ) {
			/* Move sideways. */
			int newX, newY;
			newX = dX + dir;
			newY = dY - 1;
		    
			/* Ground penetration? */
			int ground_penetration = (newY < 0);
			
			/* Diamond penetration? */
			int diamond_penetration = 0;
			for( int k = 0; k < d; ++k ) {
			    if( fX[ k ] == newX && fY[ k ] == newY ) {
				diamond_penetration = 1;
				break;
			    }
			}

			if( ground_penetration || diamond_penetration ) {

			    fX[ d ] = dX;
			    fY[ d ] = dY;
			    break;
			} else {
			    dX = newX;
			    dY = newY;
			}
		    }
		}
	    }

	    if( ! invalid ) {
		//printf( " valid\n" );
		num_real_cases += 1;
		for( int k = 0; k < N; ++k ) {
		    //printf( "  %4d %4d\n", fX[ k ], fY[ k ] );
		}
		int has_diamond_at_XY = 0;
		for( int k = 0; k < N; ++k ) {
		    if( fX[ k ] == X && fY[ k ] == Y )
			has_diamond_at_XY = 1;
		}
		if( has_diamond_at_XY )
		    num_cases_with_diamonds_at_XY += 1;
	    } else {
		//printf( " invalid\n" );
	    }

	}

	double prob = (double) num_cases_with_diamonds_at_XY / num_real_cases;
	//printf( "num_cases_with_diamonds_at_XY = %d\n", num_cases_with_diamonds_at_XY );
	//printf( "num_real_cases = %d\n", num_real_cases );
	printf( "Case #%d: %.15lf\n", test, prob );

	//break;
    }
    return 0;
}
