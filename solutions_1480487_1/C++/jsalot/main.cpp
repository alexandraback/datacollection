/*
 * main.cpp
 *
 *  Created on: May 5, 2012
 *      Author: sercan
 */

#include <iostream>
#include <sstream>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_ANSWER_LENGTH 50000

using namespace std;

void solve(char* result)
{
	int noOfContestants;
	cin >> noOfContestants;

	int judgePoints[200];
	int judGeTotal = 0;
	for (int i=0; i<noOfContestants; i++)
	{
		cin >> judgePoints[i];
		judGeTotal += judgePoints[i];
	}

	int realTotal = 0;
	int realContestants = 0;
	for (int i=0; i<noOfContestants; i++)
	{
		double missing = ((2*judGeTotal) / (double) noOfContestants) - judgePoints[i];
		if (missing > 0)
		{
			realTotal += judgePoints[i];
			realContestants++;
		}
	}

	for (int i=0; i<noOfContestants; i++)
	{
		double missing = ((realTotal + judGeTotal) / (double) realContestants) - judgePoints[i];
		double req = missing > 0 ? ((100*missing) / judGeTotal) : 0;
		sprintf(result, "%s%s%f", result, (i ==0 ? "" : " "), req);
	}

	// TODO

	//sprintf(result, "%d", 5);
	//sprintf(result, "%f", 5.0);
	//sprintf(result, "%s", "result");

	//assert(true);
}

int main(int argc, char* argv[])
{
    int numberOfCases;
    cin >> numberOfCases;

    // read till the end of line just to be sure "gets" will work
    char line[1024];
	cin.getline(line, 1024);

	size_t size = sizeof(char) * MAX_ANSWER_LENGTH;
	char* answer = (char*) malloc(size);

	for (int i = 1; i <= numberOfCases; i++)
    {
    	memset(answer, 0, size);
    	solve(answer);
        cout << "Case #" << i << ": " << answer << endl;
    }

    free(answer);

    return 0;
}
