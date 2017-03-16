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
   trace( "Ntests = %d\n",  ntests );

   for( int i = 1; i <=  ntests; i++ )
   {
      trace( "-----------\n" );
      trace( "| Test %02d |\n", i );
      trace( "-----------\n" );

      int x, r, c;
      myfile >> x >> r >> c;
      trace( "XRC = %d %d %d\n", x, r, c );

      bool result = true;

      if( (r*c) % x != 0 ) { result = false; }
      if( x > 2 && ( r == 1 || c == 1) ) { result = false; }
      if( x == 4 && ( r < 3 || c < 3) ) { result = false; }

      printf( "Case #%d: %s\n", i, result ? "GABRIEL" : "RICHARD" );
   }

   myfile.close();
   return 0;
}
