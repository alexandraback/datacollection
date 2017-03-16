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
	//freopen("B-small-attempt1.in", "r", stdin);
	//freopen("B-small-attempt1.out", "wb", stdout);

	int numOfTestcases;
	std::cin >> numOfTestcases;

	FOR(i, numOfTestcases)
	{
		std::cout << "Case #" << (i + 1) << ": ";

		std::string str;
		std::cin >> str;

		int totalFlips = 0;

		FORI(i, 1, (int)(str.size()))
		{
			if (str[i - 1] != str[i])
			{
				totalFlips ++;
			}
		}

		if (str[(int)(str.size()) - 1] == '-') totalFlips++;

		std::cout << totalFlips << std::endl;

	}

	return 0;
}