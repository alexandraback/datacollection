//#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>
#include <string>

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORI(i, a, n) for(int i = (int)(a); i < (int)(n); i++)


int main()
{
	//freopen("B-large.in", "r", stdin);
	//freopen("B-large.out", "wb", stdout);

	int numOfTestcases;
	std::cin >> numOfTestcases;

	FOR(i, numOfTestcases)
	{
		std::cout << "Case #" << (i + 1) << ":";

		int n;
		std::cin >> n;

		int heights[2510];
		FOR(i, 2510) heights[i] = 0;

		FOR(i, 2 * n - 1)
		{
			FOR(j, n)
			{
				int a;
				std::cin >> a;
				heights[a]++;
			}
		}

		FOR(i, 2510)
		{
			if (heights[i] % 2 == 1) std::cout << " " << i;
		}

		std::cout << std::endl;
	}

	return 0;
}