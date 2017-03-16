#include "config.h"
#include <cmath>

using namespace std;

int main()
{
	ifstream* ifs = openFileForInput( INPUT_FILE );
	ofstream* ofs = openFileForOutput( OUTPUT_FILE );

	if ( !ifs || !ofs )
	{
		return 0;
	}

	Cases testCases = readFile( ifs );

	for ( int i = 0; i < testCases.numTestCases; ++i )
	{
		if ( !testCases.testCase[i] )
		{
			continue;
		}

		char* item;
		char digits[12];
		int minVal, maxVal;

		item = strtok( testCases.testCase[i], " " );
		for ( int j = 0; j <= strlen( item ); ++j ) digits[j] = item[j];
		minVal = atoi( item );
		item = strtok( NULL, " " );
		maxVal = atoi( item );

		int numDigits = strlen(digits);
		int powTen = pow( 10.0, numDigits-1 );
		int lowestLeftPos = static_cast<int>( digits[0] );
		
		unsigned int total = 0;

		for ( int j = minVal; j <= maxVal; ++j )
		{
			int leftmost = j / powTen;
			int val = j;
			int fdig = val%10;
			bool good = true;
			bool same = fdig == leftmost;
			while ( val > 0 )
			{
				int d = val % 10;

				if ( d != fdig )
				{
					same = false;
				}
				val /= 10;
			}
			if ( !good || same )
			{
				continue;
			}

			val = j;
			do 
			{
				int first = val % 10;
				val /= 10;
				val += (powTen * first);
				if ( val >= minVal && val <= maxVal && val > j )
				{
					++total;
				}
			} while ( val != j );

		}
		prepareTestCase( ofs, i + 1 );
		char num[17];
		_itoa_s(total, num, 16, 10 );
		ofs->write( num, strlen(num));
		ofs->put('\n');
	}

	closeInputFile( ifs );
	closeOutputFile( ofs );
}