#include "config.h"
#include <cmath>

using namespace std;

int Solve( int num, int maxSurp, int bestResult, int* scores, int scoreStart = 0, int totalSurprising = 0, int goodCount = 0, int curMax = 0 );

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
		int numGooglers, surprising, bestResult;

		item = strtok( testCases.testCase[i], " " );

		numGooglers = atoi( item );
		item = strtok( NULL, " " );
		surprising = atoi( item );
		item = strtok( NULL, " " );
		bestResult = atoi( item );
		item = strtok( NULL, " " );

		cout << numGooglers << " - " << surprising << " - " << bestResult << endl;

		int* scores = new int[numGooglers];
		for ( int j = 0; j < numGooglers; ++j )
		{
			scores[j] = atoi( item );
			item = strtok( NULL, " " );
		}

		int answer = Solve( numGooglers, surprising, bestResult, scores );

		prepareTestCase( ofs, i + 1 );
		char num[12] = {0};
		_itoa_s( answer, num, 11, 10 );
		ofs->write( num, strlen(num) );
		ofs->put('\n');
		delete [] scores;
	}

	closeInputFile( ifs );
	closeOutputFile( ofs );
}

// This is horrible, don't look!
int Solve( int num, int maxSurp, int bestResult, int* scores, int scoreStart, int totalSurprising, int goodCount, int curMax )
{
	if ( totalSurprising > maxSurp )
	{
		return curMax;
	}

	if ( scoreStart == num )
	{
		if ( totalSurprising == maxSurp )
		{
			return goodCount > curMax ? goodCount : curMax;
		}
		else
		{
			return curMax;
		}
	}
	if ( scoreStart > num )
	{
		return curMax;
	}
	int bestStart = static_cast<int>( static_cast<float>( scores[scoreStart] ) / 3.0f + 0.5f );

	// very lazy checking
	if ( bestStart <= 10 && bestStart >= 0 )
	{
		if ( bestStart == 10 )
		{
			curMax = Solve( num, maxSurp, bestResult, scores, scoreStart + 1, totalSurprising, goodCount + 1, curMax );
		}
		else if ( bestStart == 0 )
		{
			if ( bestResult == 0 )
			{
				curMax = Solve( num, maxSurp, bestResult, scores, scoreStart + 1, totalSurprising, goodCount + 1, curMax );
			}
			else
			{
				curMax = Solve( num, maxSurp, bestResult, scores, scoreStart + 1, totalSurprising, goodCount, curMax );
			}

		}
		else if ( bestStart >= bestResult )
		{
			curMax = Solve( num, maxSurp, bestResult, scores, scoreStart + 1, totalSurprising, goodCount + 1, curMax );
			curMax = Solve( num, maxSurp, bestResult, scores, scoreStart + 1, totalSurprising + 1, goodCount + 1, curMax );
		}
		else if ( bestStart + 1 == bestResult )
		{
			if ( bestStart*3 == scores[scoreStart] || (bestStart*3 - 1) == scores[scoreStart] )
			{
				curMax = Solve( num, maxSurp, bestResult, scores, scoreStart + 1, totalSurprising + 1, goodCount + 1, curMax );
				curMax = Solve( num, maxSurp, bestResult, scores, scoreStart + 1, totalSurprising, goodCount, curMax );
			}
			else if ( (bestStart*3 + 1) == scores[scoreStart] )
			{
				curMax = Solve( num, maxSurp, bestResult, scores, scoreStart + 1, totalSurprising, goodCount + 1, curMax );
				curMax = Solve( num, maxSurp, bestResult, scores, scoreStart + 1, totalSurprising + 1, goodCount + 1, curMax );
			}
			else
			{
				curMax = Solve( num, maxSurp, bestResult, scores, scoreStart + 1, totalSurprising, goodCount, curMax );
				curMax = Solve( num, maxSurp, bestResult, scores, scoreStart + 1, totalSurprising + 1, goodCount, curMax );
				return curMax;
			}
		}
		else
		{
			curMax = Solve( num, maxSurp, bestResult, scores, scoreStart + 1, totalSurprising, goodCount, curMax );
			curMax = Solve( num, maxSurp, bestResult, scores, scoreStart + 1, totalSurprising + 1, goodCount, curMax );
		}
	}

	return curMax;
}