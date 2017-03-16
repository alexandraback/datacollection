#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10000;
int E, R, N;
int v[MAXN];

int ans;
void DFS(int aNow, int Enow, int gain)
{
	if (aNow == N)
	{
		ans = max(ans, gain);
		return;
	}
	for (int i = 0; i <= Enow; i++)
		DFS(aNow + 1, min(E, Enow - i + R), gain + v[aNow] * i);
}

int main()
{
	int totCase;
	scanf("%d", &totCase);
	for (int cas = 1; cas <= totCase; cas++)
	{
		scanf("%d%d%d", &E, &R, &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &v[i]);
		ans = 0;
		DFS(0, E, 0);
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}

