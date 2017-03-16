// basic file operations
#include <iostream>
#include <fstream>
using namespace std;

#define DEBUG 0
#define trace if( DEBUG ) printf

/*
qsort( device, N, sizeof(uint64_t), compare );
int compare (const void * a, const void * b)
{
  return ( *(uint64_t*)a - *(uint64_t*)b );
}
*/

int main (int argc, char **argv)
{
   if( argc != 2 ) return -1;
   ifstream myfile;
   int ntests;

   myfile.open( argv[1] );
   myfile >> ntests;
   trace( "Ntests = %d\n", ntests );

   for( int i = 1; i <= ntests; i++ )
   {
      trace( "-----------\n" );
      trace( "| Test %02d |\n", i );
      trace( "-----------\n" );

      int smax = 0;
      char shy[1002];

      myfile >> smax >> shy;
      trace( "Smax = %d, shy = %s\n", smax, shy );

      int up = 0, added = 0;
      for( int level = 0; level <= smax; level++ )
      {
         shy[level] -= '0';
      }

      int max = 0;
      for( int level = 0; level <= smax; level++ )
      {
         int diff = level - up;
//         if( diff < 0 ) { diff = 0; }
         if( diff > max ) { max = diff; }

         trace( "L = %d, U = %d, A = %d\n", level, up, diff );
         if(up < level) { added += diff; }
         up += shy[level];
      }
      
      printf( "Case #%d: %d\n", i, max );
   }

   myfile.close();
   return 0;
}
