#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cassert>

using namespace std;

#define FNAME "1"
#define FILE 1

#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define LD long double

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

const int turn[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int T, N, M, K, s, ANS, ans, cnt, a[25][25], used[25][25], good[25][25], boo;

void dfs (int k, int l)
{
	//cerr << k << " " << l << endl;
	used[k][l] = 1;
	if (a[k][l] == 1)
		return;
	if (k == 0 || l == 0 || k == N - 1 || l == M - 1)
		boo = 1;
	for (int g = 0; g < 4; g++)
	{
		int dx = turn[g][0], dy = turn[g][1];
		if (k + dx >= 0 && k + dx < N && l + dy >= 0 && l + dy < M && used[k + dx][l + dy] == 0)
			dfs(k + dx, l + dy);		
	}
}


void dfs2 (int k, int l, int dlt)
{
	used[k][l] = 1;
	if (a[k][l] == 1)
		return;
	good[k][l] = dlt;
	for (int g = 0; g < 4; g++)
	{
		int dx = turn[g][0], dy = turn[g][1];
		if (k + dx >= 0 && k + dx < N && l + dy >= 0 && l + dy < M && used[k + dx][l + dy] == 0)
			dfs2(k + dx, l + dy, dlt);		
	}
}


int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &T);
	cerr << T << endl;
	for (int g = 0; g < T; g++)
	{
		scanf("%d%d%d", &N, &M, &K);
		s = N * M;
		ANS = K;
		for (int i = 0; i < (1 << s); i++)
		{
			ans = 0, cnt = 0;
			for (int x = 0; x < N; x++)
				for (int y = 0; y < M; y++)
					used[x][y] = 0, good[x][y] = 0, a[x][y] = 0;
			for (int j = 0; j < s; j++)
				if (i & (1 << j))
				{
					a[j / M][j % M] = 1; 
					cnt++;
				}
			for (int x = 0; x < N; x++)
				for (int y = 0; y < M; y++)
				if (used[x][y] == 0)
				{
				    boo = 0;
					dfs(x, y);
					good[x][y] = boo;
				}
			for (int x = 0; x < N; x++)
				for (int y = 0; y < M; y++)
					used[x][y] = 0;
			for (int x = 0; x < N; x++)
				for (int y = 0; y < M; y++)
				if (used[x][y] == 0)
				{
				    dfs2(x, y, good[x][y]);
				}
			for (int x = 0; x < N; x++)
				for (int y = 0; y < M; y++)
					if (good[x][y] == 0)
						ans++;
			if (ans >= K)
				ANS = min(ANS, cnt);
		}
		printf("Case #%d: %d\n", g + 1, ANS);
	}
	return 0;
}