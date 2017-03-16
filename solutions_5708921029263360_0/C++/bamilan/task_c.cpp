#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>
#include <string>

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORI(i, a, n) for(int i = (int)(a); i < (int)(n); i++)


int JP[10][10];
int JS[10][10];
int PS[10][10];






int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "wb", stdout);

	int numOfTestcases;
	std::cin >> numOfTestcases;

	FOR(i, numOfTestcases)
	{
		std::cout << "Case #" << (i + 1) << ": ";

		int J, P, S, K;
		std::cin >> J >> P >> S >> K;


		FOR(i, 10)
		{
			FOR(j, 10)
			{
				JP[i][j] = 0;
				JS[i][j] = 0;
				PS[i][j] = 0;
			}
		}

		std::vector<int> solution;

		FOR(i, J)
		{
			FOR(j, P)
			{
				FOR(k, S)
				{
					if (JP[i][j] < K && JS[i][k] < K && PS[j][k] < K)
					{
						solution.push_back(i + 1);
						solution.push_back(j + 1);
						solution.push_back(k + 1);

						JP[i][j]++;
						JS[i][k]++;
						PS[j][k]++;
					}
				}
			}
		}

		std::cout << (solution.size() / 3) << std::endl;
		FOR(i, (int)(solution.size() / 3))
		{
			std::cout << solution[i * 3] << " " << solution[i * 3 + 1] << " " << solution[i * 3 + 2] << std::endl;
		}
	}

	return 0;
}