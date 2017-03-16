#include <stdio.h>

int main()
{
	int i, j, k, firstNum, secondNum, thirdNum, numCase, cases, googler, surprising, bound, score;
	int maxSurprising[31], maxNonSurprising[31], total, answer;

	// precalc
	for(i = 0; i <= 30; i++)
	{
		maxSurprising[i] = -1;
		maxNonSurprising[i] = -1;
	}
	for(firstNum = 0; firstNum <= 10; firstNum++)
	{
		for(secondNum = firstNum; secondNum <= firstNum + 2; secondNum++)
		{
			if(secondNum > 10)
				break;

			for(thirdNum = secondNum; thirdNum <= firstNum + 2; thirdNum++)
			{
				if(thirdNum > 10)
					break;

				total = firstNum + secondNum + thirdNum;
				if(thirdNum - firstNum < 2) // non surprising
				{					
					if(maxNonSurprising[total] < thirdNum)
						maxNonSurprising[total] = thirdNum;
				}
				else
				{
					if(maxSurprising[total] < thirdNum)
						maxSurprising[total] = thirdNum;
				}
			}
		}
	}

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%i", &cases);
	for(numCase = 1; numCase <= cases; numCase++)
	{
		scanf("%i %i %i", &googler, &surprising, &bound);

		answer = 0;
		for(i = 0; i < googler; i++)
		{
			scanf("%i", &score);
			if(maxNonSurprising[score] >= bound)
				answer++;
			else
			{
				if(surprising > 0 && maxSurprising[score] >= bound)
				{
					answer++;
					surprising--;
				}
			}
		}

		printf("Case #%i: %i\n", numCase, answer);
	}

	return 0;
}