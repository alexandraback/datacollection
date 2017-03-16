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

double find_lowest_score( int const i, vector<double> scores, double scoreSum )
{
   double lowScore = 0.0f;
   double highScore = scoreSum;
   double epsilon = 0.000000001f;

   while (highScore - lowScore > epsilon )
   {
      double testScore = (highScore + lowScore) / 2.0;
      double minScore = scores[i] + testScore;

      double remainingScore = scoreSum - testScore;

      for (int x = 0; x < scores.size(); ++x)
      {
         if ( x != i )
         {
            double score = scores[x];
            double scoreDiff = minScore - score;
            if ( scoreDiff > 0 )
            {
               remainingScore -= scoreDiff;
            }
         }
      }

      if ( remainingScore > 0.0f )
      {
         lowScore = testScore;
      }
      else
      {
         highScore = testScore;
      }
   }

   return 100.0 * (highScore / scoreSum);
}

void DoTestCase( int caseNum )
{
   cout << "Case #" << caseNum << ": ";

   int N;
   cin >> N;

   vector<double> scores;
   double scoreSum = 0;
   for (int i = 0; i < N; ++i)
   {
      int S;
      cin >> S;
      scores.push_back( (double) S );
      scoreSum += S;
   }

   for ( int i = 0; i < N; ++i )
   {
      printf( "%0.6f", find_lowest_score( i, scores, scoreSum ) );
      cout << " ";
   }

   cout << endl;
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
