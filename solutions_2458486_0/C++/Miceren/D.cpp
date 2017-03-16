#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
using namespace std;

const int MAXN = 410;

int N, K;
int now[MAXN];
int box[MAXN][MAXN], bhash[MAXN][MAXN], key[MAXN], num[MAXN];
set<long long> M;

void init()
{
	memset(now, 0, sizeof(now));
	int x;
	scanf("%d %d", &K, &N);
	for(int i = 1; i <= K; i++)
	{
		scanf("%d", &x);
		now[x]++;
	}
	memset(bhash, 0, sizeof(bhash));
	for(int i = 1; i <= N; i++)
	{
		scanf("%d %d", &key[i], &num[i]);
		for(int j = 1; j <= num[i]; j++)
		{
			scanf("%d", &x);
			box[i][j] = x;
			bhash[i][x]++;
		}
	}
}

int path[MAXN], visit[MAXN], solved;

void dfs(int dep)
{
	if (solved)
		return;
	if (dep > N)
	{
		for(int i = 1; i <= N; i++)
			printf(" %d", path[i]);
		printf("\n");
		solved = 1;
		return ;
	}
	long long h = 0;
	for(int i = 1; i <= N; i++)
		h = h * 3 + visit[i];
	if (M.find(h) != M.end())
		return ;
	M.insert(h);
	for(int i = 1; i <= N; i++)
		if (!visit[i] && now[key[i]])
		{
			visit[i] = 1;
			path[dep] = i;
			
			now[key[i]]--;
			for(int j = 1; j <= num[i]; j++)
				now[box[i][j]]++;
			
			dfs(dep + 1);
			
			now[key[i]]++;
			for(int j = 1; j <= num[i]; j++)
				now[box[i][j]]--;
			
			visit[i] = 0;
			
			if (bhash[i][key[i]])
				break;
		}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		printf("Case #%d:", t);
		init();
		memset(visit, 0, sizeof(visit));
		solved = 0;
		M.clear();
		dfs(1);
		if (!solved)
			printf(" IMPOSSIBLE\n");
	}
	return 0;
}
