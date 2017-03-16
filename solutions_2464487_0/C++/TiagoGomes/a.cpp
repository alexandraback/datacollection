#include <cstdio>
#include <cmath>

int calcNumRings( long double r, long double t )
{
  long int    numRings  = 0;
  long double oldRadius = r;

  while ( t > 0.0 )
  {
    ++numRings;
    t -= ( 2 * oldRadius + 1.0 );
    oldRadius += 2.0;
  }

  if ( t < 0.0 ) { --numRings; }

  return numRings;
}

int main( void )
{
  int      numCases = 0;
  long int numRings = 0;
  FILE *   input    = fopen( "input.txt" , "rt" );
  FILE *   output   = fopen( "output.txt", "wt" );

  /* Problem variables. */
  long double r, t;

  fscanf( input, " %d", &numCases );

  for ( int caseID = 1; caseID <= numCases; ++caseID )
  {
    /* Read inputs. */
    fscanf( input, " %lf %lf", &r, &t );

    /* Process data. */

    /* Generate output. */
    fprintf( output, "Case #%d: %ld\n", caseID, calcNumRings( r, t ) );
  }
}