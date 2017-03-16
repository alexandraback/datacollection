#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
using namespace std;

int N;

class Level
{
public:
	int i;
	int a;
	int b;
};

Level levels[2000];

int solve()
{
	set<int> level1;
	set<int> level2;

	for (int i = 0; i < N; i++)
	{
		level1.insert(i);
		level2.insert(i);
	}

	int currentStar = 0;
	int times = 0;

	while (true)
	{
		bool find = false;

		for (set<int>::iterator it = level2.begin(); it != level2.end(); it++)
		{
			if (levels[*it].b <= currentStar && level1.find(*it) != level1.end())
			{
				currentStar += 2;
				level1.erase(*it);
				// cout << "Take " << *it << " Level 2" << endl;
				find = true;
				times++;
				level2.erase(it);
				break;
			}
		}

		if (find)
			continue;

		for (set<int>::iterator it = level2.begin(); it != level2.end(); it++)
		{
			if (levels[*it].b <= currentStar)
			{
				currentStar ++;
				// cout << "Take " << *it << " Level 2" << endl;
				find = true;
				times++;
				level2.erase(it);
				break;
			}
		}

		if (find)
			continue;

		for (set<int>::iterator it = level1.begin(); it != level1.end(); it++)
		{
			if (levels[*it].a <= currentStar)
			{
				currentStar ++;
				times++;
				find = true;
				// cout << "Take " << *it << " Level 1" << endl;
				level1.erase(it);

				break;
			}
		}

		if (currentStar == 2 * N)
		{
			return times;
		}

		if (!find)
		{
			return -1;
		}
	}

	return times;
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
		{
			scanf("%d%d", &levels[j].a, &levels[j].b);
		}

		int ret = solve();

		if (ret == -1)
		{
			printf("Case #%d: Too Bad\n", i + 1);
		}
		else
		{
			printf("Case #%d: %d\n", i + 1, ret);
		}
	}
}