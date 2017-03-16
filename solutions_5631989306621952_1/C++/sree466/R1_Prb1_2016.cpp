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


/*
*
*/

int main()
{
	freopen("I.in", "r", stdin);
	freopen("O.op", "w", stdout);

	int cases;
	scanf("%d", &cases);

	char dummy;
	scanf("%c", &dummy);
	
	int caserunning = 0;
	while (cases--)
	{
		char firstchar;
		char currentchar;
		string outstr = "";
		scanf("%c", &currentchar);
		firstchar = currentchar;
		while (currentchar != '\n')
		{
			if (firstchar <= currentchar)
			{
				outstr = currentchar + outstr;
				firstchar = currentchar;
			}
			else
			{
				outstr += currentchar;
			}
			scanf("%c", &currentchar);
		}


		printf("Case #%d: %s\n", ++caserunning, outstr.c_str());


	}


	return 0;
}

