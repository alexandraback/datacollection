#include <cstdio>
#include <cstring>
int dp[1<<20], go[1<<20][2], n, k, now[20], add[20][20], need[20], cnt[20];

int solve(int m, int a)
{
	if (a == 0) return 1;
	int& res = dp[m];
	if (res != -1) return res;
	res = 0;
	
	int got[20] = {0};
	for (int i = 0; i < k; ++i)
		got[now[i]]++;
		
	for (int i = 0; i < n; ++i) if (!(m&1<<i))
	{
		got[need[i]]--;
		for (int j = 0; j < cnt[i]; ++j)
			got[add[i][j]]++;
	}
	
	for (int i = 0; i < n; ++i) if ((m&1<<i) && got[need[i]])
	{
		int z = solve(m^1<<i, a-1);
		if (z && !res) go[m][0] = m^1<<i, go[m][1] = i;
		res |= z;
	}
	
	return res;
}

void print(int m, int a)
{
	if (a == 0)
	{
		printf("\n");
		return;
	}
	printf(" %d", go[m][1]+1);
	print(go[m][0], a-1);
}

int main()
{
	int t;
	scanf("%d", &t);
	
	for (int q = 1; q <= t; ++q)
	{
		printf("Case #%d:", q);
		scanf("%d%d", &k, &n);
		for (int i = 0; i < k; ++i)
			scanf("%d", &now[i]), --now[i];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &need[i]);
			--need[i];
			scanf("%d", &cnt[i]);
			for (int j = 0; j < cnt[i]; ++j)
				scanf("%d", &add[i][j]), add[i][j]--;
		}
		for (int i = 0; i < 1<<n; ++i)
			dp[i] = -1;
		if (!solve((1<<n)-1, n)) printf(" IMPOSSIBLE\n");
		else print((1<<n)-1, n);
	}
}

