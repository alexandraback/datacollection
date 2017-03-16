/*
 * main.cpp
 *
 *  Created on: May 5, 2012
 *      Author: sercan
 */

#include <iostream>
#include <vector>
#include <set>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_ANSWER_LENGTH 50000

using namespace std;

int numberOfNumbers;
long long numbers[500];

bool notIn(short i, std::vector<short>v)
{
	for (int j=0; j<v.size(); j++)
		if (v[j] == i)
			return false;
	return true;
}

bool tryRec(std::vector<short>& set1, std::vector<short>& set2, long long& total1, long long& total2, const long long& limit)
{

	/*if (set1.size() <= 3 && set2.size() <= 3)
	{
	printf("\nset1: ");
	for (unsigned int i=0; i<set1.size(); i++)
		printf("%s%lld", i==0 ? "" : " ", set1[i]);
	printf("\nset2: ");
	for (unsigned int i=0; i<set2.size(); i++)
		printf("%s%lld",  i==0 ? "" : " ", set2[i]);
	printf("\n");
	}*/



	int i=0;
	if (!set1.empty())
		i = set1[set1.size()-1]+1;

	if (total1 > limit || total2 > limit)
		return false;


		if ((total1 == 0 && total2 == 0) || total1 < total2)
		{
			for (; i<numberOfNumbers; i++)
			{
				if (!notIn(i, set1) || !notIn(i, set2))
					continue;
				set1.push_back(i);
				total1 += numbers[i];
				if (total1 == total2) return true;
				if (tryRec(set1, set2, total1, total2, limit))
					return true;
				set1.erase(set1.begin() + (set1.size()-1));
				total1 -= numbers[i];
			}
		}
		else if (total2 < total1)
		{
			for (; i<numberOfNumbers; i++)
			{
				if (!notIn(i, set1) || !notIn(i, set2))
					continue;
				set2.push_back(i);
				total2 += numbers[i];
				if (total1 == total2) return true;
				if (tryRec(set1, set2, total1, total2, limit))
					return true;
				set2.erase(set2.begin() + (set2.size()-1));
				total2 -= numbers[i];
			}
		}
		else
		{
			return true;
		}

	return false;
}

void solve(char* result)
{
    cin >> numberOfNumbers;

    long long total = 0;
    for (int i=0; i<numberOfNumbers; i++)
    {
    	cin >> numbers[i];
    	total += numbers[i];
    }

    std::vector<short> set1;
    std::vector<short> set2;

    long long total1 = 0;
    long long total2 = 0;

    long long limit = total / 2;

	if (tryRec(set1, set2, total1, total2, limit / 8) || tryRec(set1, set2, total1, total2, limit / 4) || tryRec(set1, set2, total1, total2, limit / 2) || tryRec(set1, set2, total1, total2, limit))
	{
		sprintf(result, "%s\n", result);
		for (unsigned int i=0; i<set1.size(); i++)
			sprintf(result, "%s%s%lld", result, i==0 ? "" : " ", numbers[set1[i]]);
		sprintf(result, "%s\n", result);
		for (unsigned int i=0; i<set2.size(); i++)
			sprintf(result, "%s%s%lld", result, i==0 ? "" : " ", numbers[set2[i]]);
	}
	else
		sprintf(result, "\nImpossible");

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
        cout << "Case #" << i << ":" << answer << endl;
    }

    free(answer);

    return 0;
}
