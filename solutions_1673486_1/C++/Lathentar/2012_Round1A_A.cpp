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

void DoTestCase( int caseNum )
{
   cout << "Case #" << caseNum << ": ";

   int A, B;
   cin >> A >> B;

   vector<double> probs;
   probs.reserve( A );

   for ( int i = 0; i < A; ++i )
   {
      double P;
      cin >> P;
      probs.push_back( P );
   }

   vector<double> correctUpToProbs( probs.size(), 1.0f );
   float prob = 1.0f;
   for ( int i = 0; i < probs.size(); ++i )
   {
      prob *= probs[i];
      correctUpToProbs[i] = prob;
   }

   float minKeyStrokes = (float)(B + 2); // ENTER TWICE

   // Key strokes if I keep typing...
   for ( int i = A; i > 0; --i )
   {
      float keyStrokesIfCorrect = B - i + (A - i) + 1;   // plus 1 for enter
      float keyStrokesIfWrong = B + keyStrokesIfCorrect + 1; // plus 1 for enter
      float prob = correctUpToProbs[i - 1];
      float keyStrokes = prob * keyStrokesIfCorrect + (1.0f - prob) * keyStrokesIfWrong;

      if ( keyStrokes < minKeyStrokes )
      {
         minKeyStrokes = keyStrokes;
      }
   }

   printf( "%0.6f\n", minKeyStrokes );
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
