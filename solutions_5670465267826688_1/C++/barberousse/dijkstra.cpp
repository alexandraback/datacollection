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

char mult[256][256];
int  sign[256][256];

void fillMult();
int findIndex( char *dev, int index, char target, int64_t &page, int64_t L );

int main (int argc, char **argv)
{
   if( argc != 2 ) return -1;
   ifstream myfile;
   int ntests;

   myfile.open( argv[1] );
   myfile >> ntests;
   trace( "Ntests = %d\n", ntests );

   fillMult();

   for( int i = 1; i <= ntests; i++ )
   {
      trace( "------------\n" );
      trace( "| Test #%02d |\n", i );
      trace( "------------\n" );

      int64_t L, X;
      char in[10001], dev[50001];

      myfile >> L >> X >> in;
//      trace( "IN: %lld %lld %s\n", L, X, in );

      int64_t len = L * X;
      trace( "LEN: %lld\n", len );
      
      int index = 0;
      for( int j = 0; j < 5; j++ )
      {
         for( int k = 0; k < L; k++ )
         {
            dev[index] = in[k];
            index++;
         }
      }
      dev[index] = '\0';

      trace( "DEV: %s\n", dev );

      index = 0;
      int64_t page = X - 5;
      if( X <= 5 ) { index = (5 - X) * L; page = 0; }

      trace( "START: %d %lld\n", index, page );

      int indexI = findIndex( dev, index , 'i', page, L );
      int indexJ = findIndex( dev, indexI, 'j', page, L );
      int indexK = findIndex( dev, indexJ, 'k', page, L );
      trace( "INDEXK: %d\n", indexK );

      char res[4];
      if( indexK == 5 * L )
         strcpy( res, "YES" );
      else
         strcpy( res, "NO" );

      printf( "Case #%d: %s\n", i, res );
   }

   myfile.close();
   return 0;
}

int findIndex( char *dev, int index, char target, int64_t &page, int64_t L )
{
   trace( "INDEX: %d %lld %c\n", index, page, target );
   if( index == -1 || dev[index] == '\0' ) { return -1; }
   
//   trace( "%c: %s\n", target, &(dev[index]) );

   int ts = 1, tl = '1';
   char cc = dev[index];
   while( cc != '\0' && !( ts == 1 && tl == target && target != 'k' ) )
   {
//      trace( "\t%c%c * %c = ", ts < 0 ? '-' : ' ', tl, cc );
      trace( "%c", cc );

      ts *= sign[ tl ][ cc ];
      tl  = mult[ tl ][ cc ];

//      trace( "%c%c\n", ts < 0 ? '-' : ' ', tl );

      index++;
      cc = dev[index];
   }
   trace( "\n" );

   if( target == 'k' )
   {
      trace( "FINPAR: %c%c\n", ts < 0 ? '-' : ' ', tl );
      page = page % 4;
      index = (5 - page) * L;
      cc = dev[index];
      trace( "FININD: %d %lld\n", index, page );

      while( cc != '\0' )
      {
         trace( "%c", cc );
         ts *= sign[ tl ][ cc ];
         tl  = mult[ tl ][ cc ];

         index++;
         cc = dev[index];
      }
      trace( "\n" );
      trace( "FINRES: %c%c\n", ts < 0 ? '-' : ' ', tl );
   }
   else if( ts == 1 && tl == target )
   {
      while( index >= L && page > 0 ) { index -= L; page--; }
   }

   if( cc == '\0' && ( ts != 1 || tl != target ) ) { index = -1; page = -1; }

   return index;
}




void fillMult()
{
   mult['1']['1'] = '1';
   mult['1']['i'] = 'i';
   mult['1']['j'] = 'j';
   mult['1']['k'] = 'k';
   mult['i']['1'] = 'i';
   mult['i']['i'] = '1';
   mult['i']['j'] = 'k';
   mult['i']['k'] = 'j';
   mult['j']['1'] = 'j';
   mult['j']['i'] = 'k';
   mult['j']['j'] = '1';
   mult['j']['k'] = 'i';
   mult['k']['1'] = 'k';
   mult['k']['i'] = 'j';
   mult['k']['j'] = 'i';
   mult['k']['k'] = '1';

   sign['1']['1'] =  1;
   sign['1']['i'] =  1;
   sign['1']['j'] =  1;
   sign['1']['k'] =  1;
   sign['i']['1'] =  1;
   sign['i']['i'] = -1;
   sign['i']['j'] =  1;
   sign['i']['k'] = -1;
   sign['j']['1'] =  1;
   sign['j']['i'] = -1;
   sign['j']['j'] = -1;
   sign['j']['k'] =  1;
   sign['k']['1'] =  1;
   sign['k']['i'] =  1;
   sign['k']['j'] = -1;
   sign['k']['k'] = -1;

   if( DEBUG & 0 )
   {
      char seq[4] = { '1', 'i', 'j', 'k' };
      for( int i = 0; i < 4; i++ )
      {
         char ca = seq[i];
         for( int j = 0; j < 4; j++)
         {
            char cb = seq[j];
            trace( "%c%c ", sign[ca][cb] < 0 ? '-' : ' ', mult[ca][cb] );
         }
         trace( "\n" );
      }
   }
}
