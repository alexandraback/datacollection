// Round 1C

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>      // For greater<int>()

using namespace std;

static void HandleCase(const int cse)
{
	int N;
	cin >> N;

	vector<int> F(N+1);
	//vector<int> B(N+1);
	for (int i = 1; i <= N; ++i)
	{
		int BFF;
		cin >> BFF;
		F[i] = BFF;
		//B[BFF] = i;
	}

	vector<bool> LC(N+1, false); // go to a large cycle
	vector<int> C(N + 1); // count
	vector<int> ML(N + 1); // max path len to the 2-cycle
	int maxCycle = 0;

	for (int i = 1; i <= N; ++i)
	{
		if (C[i] != 0)
			continue;

		int current = i;
		int c = 1;
		vector<int> CC(N + 1); // count of this loop
		vector<int> visitedList;
		while (true)
		{
			if (C[current] == 0) // first time
			{
				visitedList.push_back(current);
				CC[current] = c;

				C[current] = c;
				if (F[F[current]] == current) // 2-cycle
				{
					ML[current] = c;
					break;
				}
				current = F[current];
			}
			else // already visited
			{
				if (LC[current]) // go to large cycle
				{
					for (int j = 0; j < visitedList.size(); ++j)
						LC[visitedList[j]] = true;
				}
				else
				{
					if (CC[current] != 0) // new large cycle
					{
						for (int j = 0; j < visitedList.size(); ++j)
							LC[visitedList[j]] = true;

						int lenCycle = c - C[current];
						if (maxCycle < lenCycle)
							maxCycle = lenCycle;
					}
					else if (C[current] < c)
					{
						do
						{
							C[current] = c++;
							current = F[current];
						} while (ML[current] == 0);
						C[current] = c;
						ML[current] = c;
					}
				}
				break;
			}
			++c;
		}
	}

	int sum = 0;
	for (int i = 1; i <= N; ++i)
		sum += ML[i];

	int m = (sum > maxCycle) ? sum : maxCycle;

	cout << "Case #" << cse << ": " << m << endl;
}


int main()
{
	int T;
	cin >> T;

	string str;
	getline(cin, str, '\n');

	for (int i = 0; i < T; ++i)
		HandleCase(i + 1);

	return 0;
}


