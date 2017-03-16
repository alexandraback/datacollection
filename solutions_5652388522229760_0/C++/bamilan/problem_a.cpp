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
	//freopen("A-small-attempt0.in", "r", stdin);
	//freopen("A-small-attempt0.out", "wb", stdout);

	int numOfTestcases;
	std::cin >> numOfTestcases;

	FOR(i, numOfTestcases)
	{
		std::cout << "Case #" << (i + 1) << ": ";

		bool visited[10];
		FOR(i, 10) visited[i] = false;
		int visitedTotal = 0;

		int num = 0;
		std::cin >> num;

		if (num == 0)
		{
			std::cout << "INSOMNIA" << std::endl;
		}
		else
		{
			int temp = num;
			while (visitedTotal < 10)
			{
				int tempNum = temp;
				while (tempNum > 0)
				{
					if (!visited[tempNum % 10])
					{
						visited[tempNum % 10] = true;
						visitedTotal++;
					}
					tempNum /= 10;
				}

				temp += num;
			}

			std::cout << (temp - num) << std::endl;
		}

	}

	return 0;
}