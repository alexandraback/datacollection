#include <cstdio>
#include <cmath>
#include <climits>

#define MAX(a,b) ((a>b)?(a):(b))
#define MIN(a,b) ((a<b)?(a):(b))
#define ROUND(a) ((long unsigned int)((a)+0.5))

long int countMaxGain( long unsigned int E, long unsigned int R, long unsigned int N, long unsigned int * values )
{
  long unsigned int sum  = 0;
  long unsigned int max  = LONG_MIN;
  long unsigned int step = ROUND( (double) E / R );
  long unsigned int currEnergy = E;
  long unsigned int currIndex;

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
  long unsigned int values[ 100000 ];
  long unsigned int E, R, N;

  fscanf( input, " %d", &numCases );

  for ( int ii = 1; ii <= numCases; ++ii )
  {
    /* Read inputs. */
    fscanf( input, " %lu %lu %lu", &E, &R, &N );

    /* Process data. */
    for ( long int index = 0; index < N; ++index )
    {
      fscanf( input, " %lu", &( values[ index ] ) );
    }

    /* Generate output. */
    fprintf( output, "Case #%d: %lu\n", ii, countMaxGain( E, R, N, values ) );
  }
}