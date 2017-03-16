//#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>
#include<string>

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORI(i, a, n) for(int i = (int)(a); i < (int)(n); i++)



int main()
{
	//freopen("D-small-attempt0.in", "r", stdin);
	//freopen("D-small-attempt0.out", "wb", stdout);

	int numOfTestcases;
	std::cin >> numOfTestcases;

	FOR(i, numOfTestcases)
	{
		std::cout << "Case #" << (i + 1) << ":";

		int baseLength, levels, guesses;
		std::cin >> baseLength >> levels >> guesses;

		if (guesses * levels < baseLength) std::cout << " IMPOSSIBLE";
		else
		{
			int current = 0;
			while (current < baseLength)
			{
				long long tt = 0;
				long long currMultiplier = 1;

				int remainingLevels = levels;
				if (baseLength - current < levels) levels = baseLength - current;

				FORI(i, 1, levels + 1)
				{
					if (current + i <= baseLength)
					{
						tt += (current + levels + 1 - i - 1) * currMultiplier;
						currMultiplier *= baseLength;
					}
				}

				std::cout << " " << (tt + 1);

				current += levels;
			}
		}

		std::cout << std::endl;
	}

	return 0;
}