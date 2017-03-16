#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int BufferSize = 10000;

int a[BufferSize];
int b[BufferSize];
int flag_a[BufferSize];
int flag_b[BufferSize];
int n;
int stars;

int Select()
{
	for (int i = 0; i < n; ++i)
	{
		if (flag_b[i] == 0 && stars >= b[i])
			return i;
	}

	int k = -1;
	for (int i = 0; i < n; ++i)
	{
		if (flag_a[i] == 0 && stars >= a[i])
		{
			if (k == -1 || b[i] > b[k])
				k = i;
		}
	}

	return k;
}

int main(int argc, char *argv[])
{
	int t;
	scanf("%d", &t);

	for (int index = 1; index <= t; ++index)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d %d", &a[i], &b[i]);

		fill_n(flag_a, n, 0);
		fill_n(flag_b, n, 0);

		stars = 0;
		int steps = 0;
		while (true)
		{
			int k = Select();
			if (k == -1)
				break;
			else
			{
				int gain = 0;
				if (flag_a[k] == 0 && stars >= a[k])
				{
					++gain;
					flag_a[k] = 1;
				}

				if (flag_b[k] == 0 && stars >= b[k])
				{
					++gain;
					flag_b[k] = 1;
				}

				stars += gain;
				++steps;
			}
		}

		bool win = 1;
		for (int i = 0; i < n; ++i)
		{
			if (!flag_a[i] || !flag_b[i])
				win = false;
		}

		if (win)
			printf("Case #%d: %d\n", index, steps);
		else
			printf("Case #%d: Too Bad\n", index);
	}

	return 0;
}

