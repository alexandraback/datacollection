#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct recycled
{
	int numPair;
	int pair[8];

	recycled() { numPair = 0; }
};

recycled recycle[2000001];

struct data
{
	int index;
	char number[8];

	data(int _index) { index = _index; number[0] = NULL; }
};

void getRecycled(int number)
{
	int i, j, length;

	char checkDigit, sNumber[8];
	itoa(number, sNumber, 10);

	// check if all digits are same
	bool allSame = true;
	checkDigit = sNumber[0];
	for(i = 1; sNumber[i]; i++)
	{
		if(checkDigit != sNumber[i])
			allSame = false;
	}
	length = i;

	if(allSame) // all digits are same
		return;
	else
	{
		char buffer[8];
		int index, intValue;

		for(i = 1; i < length; i++)
		{
			j = i;
			index = 0;
			do
			{
				buffer[index++] = sNumber[j];
				j = (j + 1) % length;
			} while(j != i);
			buffer[index] = NULL;

			intValue = atoi(buffer);
			if(intValue > number)
			{
				for(j = 0; j < recycle[number].numPair; j++)
				{
					if(recycle[number].pair[j] == intValue)
						break;
				}

				if(j == recycle[number].numPair)
				{
					recycle[number].pair[j] = intValue;
					recycle[number].numPair++;
				}
			}
		}

		sort(recycle[number].pair, recycle[number].pair + recycle[number].numPair);
	}
}

int main()
{
	int numCase, cases, i, start, finish, answer, j;	

	// precalc
	for(i = 12; i <= 1999999; i++)
		getRecycled(i);	

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%i", &cases);
	for(numCase = 1; numCase <= cases; numCase++)
	{
		scanf("%i %i", &start, &finish);
		answer = 0;
		for(i = start; i <= finish; i++)
		{
			for(j = 0; j < recycle[i].numPair; j++)
			{
				if(recycle[i].pair[j] <= finish)
					answer++;
				else
					break;
			}
		}

		printf("Case #%i: %i\n", numCase, answer);
	}
}