#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 500;

int visit[MAXN], key[MAXN], init[MAXN], need[MAXN], box[MAXN][MAXN], num[MAXN], tot[MAXN]; 
int K, N, hash[MAXN], list[MAXN][MAXN], ans[MAXN];
struct eglist
{
	int other[MAXN * MAXN], succ[MAXN * MAXN], last[MAXN], sum;
	void clear()
	{
		sum = 0;
		memset(last, 0, sizeof(last));
	}
	void AddEdge(int a, int b)
	{
		other[++sum] = b, succ[sum] = last[a], last[a] = sum;
	}
}e;

void dfs(int x)
{
	for(int i = 1; i <= num[x]; i++)
		init[list[x][i]]++;
	hash[x] = 1;
	for(int i = e.last[x]; i; i = e.succ[i])
	{
		int y = e.other[i];
		if (hash[y])
			continue;
		if (!init[key[y]])
			continue;
		init[key[y]]--;
		dfs(y);
		init[key[y]]++;
	}
	for(int i = 1; i <= num[x]; i++)
		init[list[x][i]]--;
}

int ok()
{
	for(int i = 1; i <= N; i++)
		hash[i] = visit[i];
	for(int i = 1; i <= N; i++)
		if (!hash[i] && init[key[i]])
		{
			init[key[i]]--;
			dfs(i);
			init[key[i]]++;
		}
	int cnt = 0;
	for(int i = 1; i <= N; i++)
		cnt += hash[i];
	return cnt == N;
}

int Main()
{
	scanf("%d %d", &K, &N);
	memset(need, 0, sizeof(need));
	memset(init, 0, sizeof(init));
	memset(box, 0, sizeof(box));
	memset(tot, 0, sizeof(tot));
	e.clear();
	
	for(int i = 1; i <= K; i++)
	{
		int x;
		scanf("%d", &x);
		init[x]++;
		tot[x]++;
	}
	for(int i = 1; i <= N; i++)
	{
		scanf("%d %d", &key[i], &num[i]);
		need[key[i]]++;
		for(int j = 1; j <= num[i]; j++)
		{
			int x;
			scanf("%d", &x);
			box[i][x]++;
			tot[x]++;
			list[i][j] = x;
		}
	}
	for(int i = 1; i <= 400; i++)
		if (tot[i] < need[i])
			return 0;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			if (i != j)
				if (box[i][key[j]])
					e.AddEdge(i, j);
	
	memset(visit, 0, sizeof(visit));
	for(int i = 1; i <= N; i++)
	{
		int flag = 0;
		for(int j = 1; j <= N; j++)
			if (!visit[j] && init[key[j]])
			{
				init[key[j]]--;
				for(int k = 1; k <= num[j]; k++)
					init[list[j][k]]++;
				visit[j] = 1;
				if (ok())
				{
					flag = 1;
					ans[i] = j;
					break;
				}
				visit[j] = 0;
				for(int k = 1; k <= num[j]; k++)
					init[list[j][k]]--;
				init[key[j]]++;
			}
		if (!flag)
			return 0;
	}
	for(int i = 1; i <= N; i++)
		printf(" %d", ans[i]);
	printf("\n");
	return 1;
}

int main()
{
	freopen("D.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d\n", &T);
	for(int t = 1; t <= T; t++)
	{
		printf("Case #%d:", t);
		if (!Main())
			printf(" IMPOSSIBLE\n");
	}
	return 0;
}
