#include "config.h"
#include <cmath>

using namespace std;

void reflectMapHori( Map& m, int height, int width );
void reflectMapVert( Map& m, int height, int width );
float Dist( int x1, int y1, int x2, int y2 );
int GCD( int A, int B );

int main()
{
   ifstream* ifs = openFileForInput( INPUT_FILE );
   ofstream* ofs = openFileForOutput( OUTPUT_FILE );

   int j, k;

   if ( !ifs || !ofs )
   {
      return 0;
   }

   Cases testCases = readFile( ifs );

   for ( int i = 0; i < testCases.numTestCases; ++i )
   {
      bool slopes[1000*1000];
      int myPosX = -1, myPosY;
      int total = 0;

      for ( k = 0; k < 1000*1000; ++k ) slopes[k] = false;

      // make map symmetrical
      reflectMapHori( testCases.testCase[i], testCases.testCase[i].height, testCases.testCase[i].width );
      reflectMapVert( testCases.testCase[i], testCases.testCase[i].height, testCases.testCase[i].width );
      
      while ( ((testCases.testCase[i].width-50) /2.0) <= testCases.testCase[i].distance )
      {
         reflectMapHori( testCases.testCase[i], testCases.testCase[i].height, testCases.testCase[i].width );
      }
      while ( ((testCases.testCase[i].height-50) /2.0) <= (float)testCases.testCase[i].distance*2 )
      {
         reflectMapVert( testCases.testCase[i], testCases.testCase[i].height, testCases.testCase[i].width );
      }
      for ( int y = 0; y < testCases.testCase[i].height; ++y )
      {
         for ( int x = 0; x < testCases.testCase[i].width; ++x )
         {
            if ( testCases.testCase[i].map[y][x] == 'X' )
            {
               if ( (x-1) >= testCases.testCase[i].distance &&
                    ((testCases.testCase[i].width-1) - (x-1)) >= testCases.testCase[i].distance &&
                    (y-1) >= testCases.testCase[i].distance &&
                    ((testCases.testCase[i].height-1) - (y-1)) >= testCases.testCase[i].distance )
               {
                  testCases.testCase[i].map[y][x] = 'O';
                  myPosX = x;
                  myPosY = y;
                  break;
               }

            }
         }
         if ( myPosX > -1 )
         {
            break;
         }
      }
      if ( myPosX == -1 )
      {
         cout << "FAILED..." << endl;
      }
      
      bool countHori = true;
      bool countVert = true;
      for ( j = 1; j < testCases.testCase[i].height-1; ++j )
      {
         for ( k = 1; k < testCases.testCase[i].width-1; ++k )
         {
            if ( testCases.testCase[i].map[j][k] == 'X' && (j != myPosY || k != myPosX ) )
            {
               //testCases.testCase[i].map[j][k] = '.';
               if ( Dist(k, j, myPosX, myPosY) > testCases.testCase[i].distance )
               {
                  continue;
               }

               {
                  int difX = k - myPosX;
                  int difY = j - myPosY;
                  int gcd = abs(GCD( difY, difX ));
                  difX = difX / gcd;
                  difY = difY / gcd;
                  ++total;
                  testCases.testCase[i].map[j][k] = '1';
                  int x = myPosX;
                  int y = myPosY;
                  while ( x > 0 && y > 0 && x < testCases.testCase[i].width && y < testCases.testCase[i].height-1 )
                  {
                     if ( testCases.testCase[i].map[y][x] == 'X' )
                        testCases.testCase[i].map[y][x] = '.';
                     x += difX;
                     y += difY;
                  }
                  x = k;
                  y = j;
               }
            }
         }
      }

      cout << total << endl;
      prepareTestCase( ofs, i + 1 );
      char num[17];
      _itoa_s(total, num, 16, 10 );
      ofs->write( num, strlen(num));
      ofs->put('\n');
   }

   closeInputFile( ifs );
   closeOutputFile( ofs );
}

int GCD( int A, int B )
{
   if ( B == 0 )
   {
      return A;
   }
   return GCD( B, A % B );
}

float Dist( int x1, int y1, int x2, int y2 )
{
   int d1 = abs(x1-x2);
   int d2 = abs(y1-y2);
   return sqrtf( static_cast<float>(d1*d1 + d2*d2) );
}

void reflectMapHori( Map& m, int height, int width )
{
   int w2 = (width - 2);
   int j;
   char** newMap = new char*[height];
   int newWidth = w2*2 + 2;
   m.width = newWidth;
   for ( int i = 0; i < height; ++i )
   {
      newMap[i] = new char[newWidth+1];
      
      for ( j = 0; j < width-1; ++j )
      {
         newMap[i][j] = m.map[i][j];
         newMap[i][newWidth-j-1] = m.map[i][j];
      }
      newMap[i][newWidth] = '\0';
      delete [] m.map[i];
   }
   delete [] m.map;
   m.map = newMap;
}
void reflectMapVert( Map& m, int height, int width )
{
   int h2 = (height - 2);
   int j;
   int newHeight = h2*2 + 2;
   char** newMap = new char*[newHeight];
   m.height = newHeight;
   for ( j = 0; j < newHeight; ++j )
   {
      newMap[j] = new char[width+1];
   }
   for ( int i = 0; i < width; ++i )
   {
      for ( j = 0; j < height-1; ++j )
      {
         newMap[j][i] = m.map[j][i];
         newMap[newHeight-j-1][i] = m.map[j][i];
      }
   }
   for ( j = 0; j < newHeight; ++j )
   {
      newMap[j][width] = '\0';
      if ( j < height ) delete [] m.map[j];
   }
   delete [] m.map;
   m.map = newMap;
}