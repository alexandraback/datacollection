#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

int ProcessCase();

const int maxCases = 100;
const int maxScore = 10;
const int numJudges = 3;
const int surpriseRange = 2;

int main()
{

    int numCases;
    cin >> numCases;

    assert( numCases > 0 && numCases <= maxCases );

    cin.ignore(1000, '\n');

    for( int i = 1; i <= numCases; ++ i )
    {
        int p = ProcessCase();

        cout << "Case #" << i << ": " << p << endl;
    }

	return 0;
}

int ProcessCase()
{
    int numScores;
    cin >> numScores;

    int numSurprises;
    cin >> numSurprises;

    int bestResultTarget;
    cin >> bestResultTarget;

    assert( numSurprises >= 0 );
    assert( numSurprises <= numScores );
    assert( bestResultTarget <= maxScore );

    int bestResultAboveTargetCount = 0;
    int surprisesUsed = 0;

    for( int i = 0; i < numScores; ++i )
    {
        int totalScore;
        cin >> totalScore;

        // example:
        // bestResultTarget = 8 and totalScore = 19
        // If one score is 8, the other two must sum to 11.
        // However, they can be no more than 2 away from 8
        // according to the problem description.
        // Therefore they can be no lower than 6, but 6 + 6 > 11,
        // which is a contradiction, so the bestResult < 8.
        // However if totalScore = 20, the 8, 6, 6 is possible
        // (but surprising).
        if( totalScore < bestResultTarget ||
           totalScore < numJudges * bestResultTarget - ((numJudges - 1 ) * surpriseRange ) )
        {
            continue;
        }

        // The best result can be above the target
        // without being surprising.
        if( totalScore >= numJudges * bestResultTarget - (( numJudges - 1) * (surpriseRange - 1)) )
        {
            ++bestResultAboveTargetCount;
        }
        // The best result can be above the target
        // if it's surprising.
        else if( surprisesUsed < numSurprises &&
                totalScore >= surpriseRange &&
                totalScore <= (numJudges * maxScore) - surpriseRange )
        {
            ++surprisesUsed;
            ++bestResultAboveTargetCount;
        }
    }

    cin.ignore( 1000, '\n');

    return bestResultAboveTargetCount;
}
