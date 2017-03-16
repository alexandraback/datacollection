/*
 * main.cpp
 *
 *  Created on: May 6, 2012
 *      Author: sercan
 */

#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

using namespace std;

struct product
{
	long long count;
	long long type;
};

long long N;
long long M;

product boxes[100];
product toys[100];

long long calculate(long long boxed, long long boxIndex, long long toyIndex)
{
	if (boxIndex < N && toyIndex < M)
	{
		if (boxes[boxIndex].type == toys[toyIndex].type)
		{
			long long count = boxes[boxIndex].count < toys[toyIndex].count ? boxes[boxIndex].count : toys[toyIndex].count;
			boxed += count;

			boxes[boxIndex].count -= count;
			long long bi = (boxes[boxIndex].count <= 0) ? boxIndex+1 : boxIndex;

			toys[toyIndex].count -= count;
			long long ti = (toys[toyIndex].count <= 0) ? toyIndex+1 : toyIndex;

			long long result = calculate(boxed, bi, ti);

			boxes[boxIndex].count += count;
			toys[toyIndex].count += count;

			return result;
		}
		else
		{
			// throw boxes
			long long s1 = calculate(boxed, boxIndex+1, toyIndex);

			// throw toys
			long long s2 = calculate(boxed, boxIndex, toyIndex+1);

			return s1 > s2 ? s1 : s2;
		}
	}
	else
	{
		return boxed;
	}
}

void solve(long long i)
{
    cout << "Case #" << i << ": ";

	cin >> N;
	cin >> M;

	for (long long i=0; i<N; i++)
	{
		cin >> boxes[i].count;
		cin >> boxes[i].type;
	}
	for (long long i=0; i<M; i++)
	{
		cin >> toys[i].count;
		cin >> toys[i].type;
	}

	cout << calculate(0, 0, 0) << endl;
}

int main(int argc, char* argv[])
{
    long long numberOfCases;
    cin >> numberOfCases;

    // read till the end of line just to be sure "gets" will work
	char line[1024];
	cin.getline(line, 1024);

	for (long long i = 1; i <= numberOfCases; i++)
    	solve(i);

    return 0;
}

