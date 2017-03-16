#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <string>
#include <map>
#include <math.h>
using namespace std;

void DoTestCase( int caseNum )
{
   cout << "Case #" << caseNum << ": ";

   long int A, B;
   cin >> A >> B;

   int digits = (int)( 1.0 + log10( double(B) ) );
   if ( digits < 2 )
   {
      cout << 0 << endl;
      return;
   }

   int count = 0;
   char buffer[10];
   char changedNum[10];

   vector<long int> foundNumbers;
   foundNumbers.reserve( 20 );

   memset( changedNum, 0, 10 );
   for (long int n = A; n <= B; ++n)
   {
      foundNumbers.clear();

      ltoa( n, buffer, 10 );
      for ( int i = 1; i < digits; ++i )
      {
         for ( int x = 0; x < digits; ++x )
         {
            if ( x < (digits - i) )
            {
               changedNum[x] = buffer[i + x];
            }
            else
            {
               changedNum[x] = buffer[x - (digits - i)];
            }
         }

         if ( changedNum[0] == '0' )
         {
            continue;
         }
         else
         {
            long int flipped = atol( changedNum );
            if ( n != flipped && n < flipped && flipped <= B )
            {
               if ( find( foundNumbers.begin(), foundNumbers.end(), flipped ) != foundNumbers.end() )
               {
                  continue;
               }

               foundNumbers.push_back( flipped );
               count++;
            }
         }
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
