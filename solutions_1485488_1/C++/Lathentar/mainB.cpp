#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <string>
#include <map>
#include <math.h>
using namespace std;

struct vec2i
{
   vec2i( int _x, int _y ) : x( _x ) , y( _y ) {}

   int x;
   int y;
};

int GCD(int x,int y)
{
if(y==0) // base case, the programs stops if y reaches 0.
return x; //it returns the GCD
else
return GCD(y,x%y); //if y doesn't reach 0 then recursion continues
}

struct node
{
   bool   mAccessible;
   bool   mTouched;
   double mBestTime;

   int mCeiling;
   int mFloor;
};

bool can_reach( double startWaterHeight, node & nextNode, node & currentNode, double & atTime )
{
   if ( nextNode.mTouched || !nextNode.mAccessible )
   {
      return false;
   }

   if ( currentNode.mCeiling - nextNode.mFloor < 50 )
   {
      // Never work
      return false;
   }

   if ( nextNode.mCeiling - currentNode.mFloor < 50 )
   {
      // Never work
      return false;
   }

   double waterHeight = startWaterHeight - 10 * currentNode.mBestTime ;
   double waterTooHigh = 50 - (nextNode.mCeiling - waterHeight);
   if ( waterTooHigh > 0 )
   {
      // We actually CAN reach this value
      // In what time though?
      double waitForWaterTime = waterTooHigh * 0.1;
      double moveBoatTime = 1.0;
      if ( (waterHeight - waterTooHigh) - currentNode.mFloor < 20 )
      {
         moveBoatTime = 10.0;
      }

      atTime = currentNode.mBestTime + waitForWaterTime + moveBoatTime;
   }
   else if ( currentNode.mBestTime > 0 )
   {
      double moveBoatTime = 1.0;
      if ( waterHeight - currentNode.mFloor < 20 )
      {
         moveBoatTime = 10.0;
      }

      atTime = currentNode.mBestTime + moveBoatTime;
   }
   else
   {
      atTime = 0;
   }

   return true;
}

void DoTestCase( int caseNum )
{
   cout << "Case #" << caseNum << ": ";

   double H;
   int N, M;
   cin >> H >> N >> M;

   vector< vector<node> > map;
   for (int j = 0; j < N; ++j)
   {
      map.push_back( vector<node>() );
      for (int i = 0; i < M; ++i)
      {
         node mapNode;
         mapNode.mTouched = false;
         cin >> mapNode.mCeiling;
         map[j].push_back( mapNode );
      }
   }

   for (int j = 0; j < N; ++j)
   {
      for (int i = 0; i < M; ++i)
      {
         cin >> map[j][i].mFloor;

         // Determine accessible state
         map[j][i].mAccessible = ( map[j][i].mCeiling - map[j][i].mFloor >= 50 );
      }
   }

   map[0][0].mTouched = true;
   map[0][0].mBestTime = 0;

   double time = 0;
   while (1)
   {
      double bestNextTime = 100000000000000000;
      int bestJ = 0;
      int bestI = 0;

      // Do a full pass to see where we can be...
      for (int j = 0; j < N; ++j)
      {
         for (int i = 0; i < M; ++i)
         {
            double atTime = time;

            if ( map[j][i].mTouched )
            {
               // Check to see what else we can touch...
               if ( j - 1 >= 0 )
               {
                  // Up
                  double atTime = time;
                  if ( can_reach( H, map[j-1][i], map[j][i], atTime ) )
                  {
                     if ( atTime < bestNextTime )
                     {
                        bestNextTime = atTime;
                        bestJ = j - 1;
                        bestI = i;
                     }
                  }
               }
               
               if ( j + 1 < N )
               {
                  // Down
                  double atTime = time;
                  if ( can_reach( H, map[j+1][i], map[j][i], atTime ) )
                  {
                     if ( atTime < bestNextTime )
                     {
                        bestNextTime = atTime;
                        bestJ = j + 1;
                        bestI = i;
                     }
                  }
               }
               
               if ( i - 1 >= 0 )
               {
                  // Left
                  double atTime = time;
                  if ( can_reach( H, map[j][i-1], map[j][i], atTime ) )
                  {
                     if ( atTime < bestNextTime )
                     {
                        bestNextTime = atTime;
                        bestJ = j;
                        bestI = i - 1;
                     }
                  }
               }
               
               if ( i + 1 < M )
               {
                  // Right
                  double atTime = time;
                  if ( can_reach( H, map[j][i+1], map[j][i], atTime ) )
                  {
                     if ( atTime < bestNextTime )
                     {
                        bestNextTime = atTime;
                        bestJ = j;
                        bestI = i + 1;
                     }
                  }
               }               
            }
         }
      }

      if ( bestJ == 0 && bestI == 0 )
      {
         cout << "CRAP" << endl;
         return;
      }

      //cout << "Reached (" << bestJ << ", " << bestI << ") in " << bestNextTime << endl;

      map[bestJ][bestI].mTouched = true;
      map[bestJ][bestI].mBestTime = bestNextTime;

      double timePassed = (bestNextTime - time); 
      time = bestNextTime;

      if ( bestJ == N - 1 && bestI == M - 1 )
      {
         // Reached the end
         cout << time << endl;
         return;
      }
   }

   cout << "BAD TIMES" << endl;
}

int main(int argc, char* argv[])
{
   int numTestCases = 0;
   cin >> numTestCases;

   for ( int i = 0; i < numTestCases; ++i )
   {
      DoTestCase( i + 1 );
   }

   //cin >> numTestCases;
	return 0;
}
