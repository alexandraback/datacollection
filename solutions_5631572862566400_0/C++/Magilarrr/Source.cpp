#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cstring>
#include <bitset>
using namespace std;

int n;
int temp;
int bff[1010];
int ending[1010];
int length[1010];
bool used[1010];
bool paired[1010];
int paired_max[1010];
int answer;
int main()
{
	int test;
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d\n", &test);
	for (int t = 1; t <= test; t++)
	{
		answer = 0;
		scanf("%d\n", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &bff[i]);
			bff[i]--;
			used[i] = false;
		}
		//complete cycle scenario
		for (int i = 0; i < n; i++)
		{
			length[i] = 0;
			for (int j = 0; j < n; j++)
				used[j] = false;
			int current = i;
			int cycle = 1;
			int last = -1;
			while (!used[bff[current]])
			{
				used[current] = true;
				last = current;
				current = bff[current];
				cycle++;
			}
			if (bff[current] == i)
			{
				if (cycle > answer)
					answer = cycle;
			}
			else
			{
				if (bff[current] == last)
				{
					ending[i] = last;
					length[i] = cycle - 2;
				}
			}
		}
		//pairs with pals scenario
		int paired_count = 0;
		for (int i = 0; i < n; i++)
			paired[i] = false;
		for (int i = 0; i < n; i++)
		{
			if (!paired[i] && (bff[bff[i]] == i))
			{
				paired[i] = paired[bff[i]] = true;
				paired_count += 2;
			}
		}
		for (int i = 0; i < n; i++)
		{
			paired_max[i] = 0;
			if (paired[i])
			{
				for (int j = 0; j < n; j++)
				{
					if ((length[j] > 0) && (ending[j] == i))
						paired_max[i] = max(paired_max[i], length[j]);
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			paired_count += paired_max[i];
		}
		printf("Case #%d: %d\n", t, max(paired_count, answer));
		//case output goes here
	}

	return 0;
}