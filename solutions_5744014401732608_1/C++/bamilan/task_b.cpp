#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>
#include <string>

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORI(i, a, n) for(int i = (int)(a); i < (int)(n); i++)


unsigned long long powerOf2s[52];
int solution[52][52];



void stuff()
{
	powerOf2s[0] = 1;
	powerOf2s[1] = 1;
	FORI(i, 2, 52)
	{
		powerOf2s[i] = powerOf2s[i - 1] * 2;
	}
}



int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "wb", stdout);

	stuff();

	int numOfTestcases;
	std::cin >> numOfTestcases;

	FOR(i, numOfTestcases)
	{
		std::cout << "Case #" << (i + 1) << ": ";

		int B;
		unsigned long long M;

		std::cin >> B >> M;

		FOR(i, B) FOR(j, B) solution[i][j] = 0;

		bool jo = true;
		FOR(i, B - 1)
		{
			FORI(j, i + 1, B - 1)
			{
				solution[i][j] = 1;
			}
		}



		if (M > powerOf2s[B - 1])
		{
			std::cout << "IMPOSSIBLE" << std::endl;
			continue;
		}

		
		std::cout << "POSSIBLE" << std::endl;

		for (int i = B - 2; i >= 0; i--)
		{
			if (M >= powerOf2s[i])
			{
				solution[i][B - 1] = 1;
				M -= powerOf2s[i];
			}
		}


		if (jo)
		{
			FOR(i, B)
			{
				FOR(j, B)
				{
					std::cout << solution[i][j];
				}
				std::cout << std::endl;
			}
		}
	}

	return 0;
}