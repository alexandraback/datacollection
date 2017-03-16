/*
* File:   main.cpp
* Author: Sreekanth
*
* Created on Apr 12, 2014
*/

#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;


void AppendDigits(int recentNo, std::vector<int>& passed)
{
	for (; recentNo > 0; recentNo /= 10)
	{
		if (std::find(passed.begin(), passed.end(), recentNo % 10) == passed.end())
		{
			passed.push_back(recentNo % 10);
		}

	}
	return;
}


/*
*
*/

int main()
{
	freopen("I.in", "r", stdin);
	freopen("O.op", "w", stdout);

	int cases;
	scanf("%d", &cases);
	int caserunning = 0;
	while (cases--)
	{
		int noofsol;
		scanf("%d", &noofsol);
		int totalreads = noofsol * ((2 * noofsol) - 1);
		std::vector<int> results;
		while (totalreads--)
		{
			int currentno;
			scanf("%d", &currentno);

			if (std::find(results.begin(), results.end(), currentno) == results.end())
			{
				results.push_back(currentno);
			}
			else
			{
				results.erase(std::find(results.begin(), results.end(), currentno));
			}			

		}

		std::sort(results.begin(), results.end());

		printf("Case #%d: ", ++caserunning);

		for (vector<int>::iterator it = results.begin(); it != results.end(); ++it) {
			printf(" %d", *it);
		}

		printf("\n");

	}


	return 0;
}

