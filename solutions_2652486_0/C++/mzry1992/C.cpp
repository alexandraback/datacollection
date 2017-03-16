#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int X = 50;
const int MAXN = 12;
const int MAXK = 12;

int R, N, M, K;
int a[MAXK];
vector<int> b;
vector<vector<int> > ans;

bool check(int now, int num)
{
	if (now == N)
		return num == 1;
	if (check(now + 1, num))	return true;
	if (num % b[now] == 0)
		if (check(now + 1, num / b[now]))	return true;
	return false;
}

bool findAns;

void DFS(int now, int last)
{
	if (findAns)
		return;
	if (now == N)
	{
		bool flag = true;
		for (int i = 0; i < K && flag; i++)
			if (!check(0, a[i]))
				flag = false;
		if (flag)
		{
			ans.push_back(b);
			findAns = true;
		}
		return;
	}
	for (b[now] = last; b[now] <= M; b[now]++)
		DFS(now + 1, b[now]);
}

int main()
{
	int totCase;
	scanf("%d", &totCase);
	for (int cas = 1; cas <= totCase; cas++)
	{
		scanf("%d%d%d%d", &R, &N, &M, &K);
		printf("Case #%d:\n", cas);
		for (int r = 0; r < R; r++)
		{
			for (int i = 0; i < K; i++)
				scanf("%d", &a[i]);
			b.resize(N);
			ans.clear();
			findAns = false;
			DFS(0, 2);
			if (!findAns)
			{
				for (int i = 0; i < N; i++)
					b[i] = 2;
				ans.push_back(b);
				puts("FUCK");
			}
			for (int j = 0; j < N; j++)
				printf("%d", ans[0][j]);
			printf("\n");
			/*
			printf("tot = %d\n", (int)ans.size());
			for (int i = 0; i < (int)ans.size(); i++)
			{
				printf("    ");
				for (int j = 0; j < N; j++)
					printf("%d", ans[i][j]);
				printf("\n");
			}
			*/
		}
	}
	return 0;
}

