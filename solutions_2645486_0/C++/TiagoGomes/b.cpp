#include <cstdio>
#include <cmath>
#include <climits>

#define MAX(a,b) ((a>b)?(a):(b))
#define MIN(a,b) ((a<b)?(a):(b))
#define ROUND(a) ((long int)((a)+0.5))

long int countMaxGain( long int E, long int R, long int N, long int * values )
{
  long unsigned int sum  = 0;
  long int          max  = LONG_MIN;
  long int          step = ROUND( (double) E / R );
  long int          currEnergy = E;
  long int          currIndex;

  for ( long int index = 0; index < N; ++index )
  {
    max = LONG_MIN;
    for ( currIndex = index + 1; currIndex <= step + index && currIndex < N && values[ currIndex ] < values[ index ]; ++currIndex );
    if ( currIndex == N )
    {
      sum += currEnergy * values[ index ];
      currEnergy = R;
    } else
    {
      sum += MIN( currEnergy, MAX( 0 , ( currEnergy + ( currIndex - index ) * R - E ) ) ) * values[ index ];
      currEnergy -= MIN( currEnergy, MAX( 0 , ( currEnergy + ( currIndex - index ) * R - E ) ) );
      if ( currEnergy + R > E )
      {
        sum += ( currEnergy + R - E ) * values[ index ];
        currEnergy = E;
      } else
      {
        currEnergy += R;
      }
    } 
  }

  return sum;
}

int main( void )
{
  int    numCases = 0;
  FILE * input    = fopen( "input.txt" , "rt" );
  FILE * output   = fopen( "output.txt", "wt" );

  /* Problem variables. */
  long int values[ 100000 ];
  long int E, R, N;

  fscanf( input, " %d", &numCases );

  for ( int ii = 1; ii <= numCases; ++ii )
  {
    /* Read inputs. */
    fscanf( input, " %ld %ld %ld", &E, &R, &N );

    /* Process data. */
    for ( long int index = 0; index < N; ++index )
    {
      fscanf( input, " %ld", &( values[ index ] ) );
    }

    /* Generate output. */
    fprintf( output, "Case #%d: %d\n", ii, countMaxGain( E, R, N, values ) );
  }
}