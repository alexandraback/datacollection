#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <string>
#include <map>
using namespace std;

void DoTestCase( int caseNum )
{
   cout << "Case #" << caseNum << ": ";

   int N, S, p;
   cin >> N >> S >> p;

   int count = 0;
   int remainingSurprises = S;

   for (int i = 0; i < N; ++i)
   {
      int score;
      cin >> score;

      int maxScore = 0;
      int maxSurprisingScore = 0;

      int const div3 = (score % 3);
      switch (div3)
      {
      case 0:
         {
            if ( score != 0 )
            {
               maxScore = (score / 3);
               maxSurprisingScore = maxScore + 1;
            }
         }
         break;
      case 1:
         {
            maxScore = (score / 3) + 1;
            maxSurprisingScore = maxScore;
         }
         break;
      case 2:
         {
            maxScore = (score / 3) + 1;
            maxSurprisingScore = maxScore + 1;
         }
         break;
      }

      maxSurprisingScore = min( maxSurprisingScore, 10 );   // cap at 10

      if ( maxScore >= p )
      {
         count++;
      }
      else if ( remainingSurprises > 0 && maxSurprisingScore >= p )
      {
         count++;
         remainingSurprises--;
      }
   }

   cout << count << endl;
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
