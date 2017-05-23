// Dancing with Googlers.cpp
//

#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	int numTests = 0;
	cin >> numTests;
	for( int j = 0; j < numTests; ++j )
	{
		int possibleCount = 0;
		int sureCount = 0;

		int numofGooglers, numOfSurprisingTriplets, maxScore;
		cin >> numofGooglers >> numOfSurprisingTriplets >> maxScore;

		int possibilityLimit = (3 * maxScore) - 5;

		int suretyLimit = (3 * maxScore) - 2;
		if((maxScore == 0) || (maxScore == 1))
			suretyLimit = -1;


		int score = 0;
		for( int i = 0; i < numofGooglers; ++i )
		{
			cin >> score;

			if((score >= maxScore) && (score > possibilityLimit))
			{
				if( score < suretyLimit )
					++possibleCount;
				else
					++sureCount;
			}
		}

		if( possibleCount > numOfSurprisingTriplets )
			possibleCount = numOfSurprisingTriplets;

		printf("Case #%d: %u", j+1, sureCount + possibleCount );


		if( j < (numTests-1) )
			putchar('\n');
	}

	return 0;
}