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

   char const * const abc = "abcdefghijklmnopqrstuvwxyz";
   char const * const map = "yhesocvxduiglbkrztnwjpfmaq";

   char line[256];
   do
   {
      cin.getline( line, 256 );
   }
   while( strlen( line ) == 0 );

   int len = strlen( line );
   for (int i = 0; i < len; ++i )
   {
      if ( 'a' <= line[i] && line[i] <= 'z' )
      {
         line[i] = map[ line[i] - 'a' ];
      }
   }

   cout << line << endl;
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
