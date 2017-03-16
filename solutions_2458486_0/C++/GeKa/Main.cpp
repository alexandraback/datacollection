#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <math.h>
#include <memory.h>


using namespace std;

#define MAX 200

struct Chest
{
	int T;
	vector<int> Keys;
};

int startKeys[MAX];
int nxt[1 << 20];
int N, NN;
Chest cs[20];

bool f(int mask)
{
	if (mask+1 == NN)
		return true;
	if (nxt[mask] != -1)
		return nxt[mask] != N;
	int mas[MAX];
	for (int i = 0; i < MAX; i++)
		mas[i] = startKeys[i];
	for (int i = 0; i < N; i++)
		if (mask & (1<<i))
		{
			mas[cs[i].T]--;
			for (int j = 0; j < cs[i].Keys.size(); j++)
				mas[cs[i].Keys[j]]++;
		}
	for (int i = 0; i < N; i++)
		if ((mask & (1<<i))==0 && mas[cs[i].T] > 0)
		{
			bool p = f(mask + (1<<i));
			if (p)
			{
				nxt[mask] = i;
				return true;
			}
		}
	nxt[mask] = N;
	return false;
}

int main()
{
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int K;
		scanf("%d%d", &K, &N);
		NN = 1 << N;
		for (int i = 0; i < MAX; i++)
			startKeys[i] = 0;
		for (int i = 0; i < K; i++)
		{
			int a;
			scanf("%d", &a);
			a--;
			startKeys[a]++;
		}
		for (int i = 0; i < N; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			cs[i].T = a - 1;
			cs[i].Keys.clear();
			for (int j = 0; j < b; j++)
			{
				int c;
				scanf("%d", &c);
				cs[i].Keys.push_back(c-1);
			}
		}
		for (int i = 0; i < NN; i++)
			nxt[i] = -1;
		if (f(0))
		{
			printf("Case #%d:", t+1);
			int m = 0;
			while (m != (NN - 1))
			{
				printf(" %d", nxt[m]+1);
				m += (1<<nxt[m]);
			}
			printf("\n");
		}
		else
			printf("Case #%d: IMPOSSIBLE\n", t+1);
	}
	return 0;
}