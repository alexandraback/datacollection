#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long LL;

int n;
bool a[1500][1500] = {};
bool used[2000] = {};
bool nya = false;

void Dfs(int x)
{
	used[x] = true;
	for (int i = 0; i < n; i++)
		if (a[x][i])
			if (used[i])
			{
				nya = true;
				return;
			}
			else
				Dfs(i);
}

void Clear1()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			a[i][j] = false;
	}
	nya = false;
}

void Clear2()
{
	for (int i = 0; i < n; i++)
		used[i] = false;;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		Clear1();
		int k = 0, x;
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &k);
			for (int q = 0; q < k; q++)
			{
				scanf("%d", &x);
				a[x-1][j] = true;
			}
		}
		printf("Case #%d: ", i+1);
		for (int j = 0; j < n; j++)
		{
			Clear2();
			Dfs(j);
			if (nya) 
			{
				printf("Yes\n");
				break;
			}
		}
		if (!nya)
			printf("No\n");
	}
	return 0;
}