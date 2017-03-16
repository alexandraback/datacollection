#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int d[2000];

int main()
{
	int t;
	scanf("%d", &t);
	for (int k = 0; k < t; k++)
	{
		int n;
		scanf("%d", &n);
		priority_queue<int> pq;
		for (int i = 0; i < n; i++)
		{
			int w;
			scanf("%d", &w);
			d[i] = w;
		}
		int m = (1 << 25);
		for (int i = 1; i < 2000; i++)
		{
			int all = 0;
			for (int j = 0; j < n; j++)
			{
				if (d[j] > i)
				{
					all += (d[j] - 1) / i;
				}
			}
			m = min(m, all + i);
		}
		printf("Case #%d: %d\n", k + 1, m);
	}
}