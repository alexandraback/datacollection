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

struct lvl
{
   lvl() : stage( 2 ), a( 0 ), b( 0 ), possible( false ) {}

   int stage;
   int a;
   int b;
   bool possible;
};

void DoTestCase( int caseNum )
{
   cout << "Case #" << caseNum << ": ";

   int N;
   cin >> N;

   vector<lvl> levels( N );
   for ( int i = 0; i < N; ++i )
   {
      cin >> levels[i].a >> levels[i].b;
   }

   vector<lvl> previousLevels;
   int stars = 0;
   int lvls = 0;
   while ( stars < 2 * N )
   {
      lvls++;
      bool foundBest = false;
      int possibles = 0;
      int minB = stars * N + 1;
      int minBIdx = 0;
      int maxB = -1;
      int maxBIdx = 0;

      for ( int i = 0; i < N; ++i )
      {
         if ( levels[i].stage == 2 )
         {
            if ( levels[i].b <= stars )
            {
               levels[i].stage = 0;
               stars += 2;
               foundBest = true;
               break;
            }
            else if ( levels[i].a <= stars )
            {
               levels[i].stage = 1;
               levels[i].possible = true;
               possibles++;

               if ( levels[i].b < minB )
               {
                  minB = levels[i].b;
                  minBIdx = i;
               }

               if ( levels[i].b > maxB )
               {
                  maxB = levels[i].b;
                  maxBIdx = i;
               }
            }
         }
         else if ( levels[i].stage == 1 )
         {
            if ( levels[i].b <= stars )
            {
               levels[i].stage = 0;
               stars += 1;
               foundBest = true;
               break;
            }
         }
      }

      if ( foundBest )
      {
         // Clear the possibles
         for ( int i = 0; i < N; ++i )
         {
            if ( levels[i].possible )
            {
               levels[i].stage++;
               levels[i].possible = false;
            }
         }
      }
      else if ( possibles > 0 )
      {
         if ( minB > stars + ( possibles - 1 ) )
         {
            levels[minBIdx].possible = false;
         }
         else
         {
            levels[maxBIdx].possible = false;
         }

         stars += 1;

         for ( int i = 0; i < N; ++i )
         {
            if ( levels[i].possible )
            {
               levels[i].stage += 1;
               levels[i].possible = false;
            }
         }
      }
      else
      {
         break;
      }
   }


   if ( stars < 2 * N )
   {
      cout << "Too Bad" << endl;
   }
   else
   {
      cout << lvls << endl;
   }
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
