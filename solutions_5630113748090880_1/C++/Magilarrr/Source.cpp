#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cstring>
#include <bitset>
using namespace std;

int vals[3000];
int n;
int temp;

int main()
{
	int test;
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d\n", &test);
	for (int t = 1; t <= test; t++)
	{
		for (int i = 1; i <= 2500; i++)
			vals[i] = 0;
		scanf("%d\n", &n);
		for (int i = 0; i < 2*n - 1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &temp);
				vals[temp]++;
			}
		}
		printf("Case #%d:", t);
		for (int i = 1; i <= 2500; i++)
		{
			if (vals[i] % 2)
				printf(" %d", i);
		}
		printf("\n");
	}

	return 0;
}