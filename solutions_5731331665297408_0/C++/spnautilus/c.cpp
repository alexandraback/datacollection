#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAXN (52)

typedef long long ll;
typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <PII> VP;

int T;
int N, M;
int zip[MAXN];

VI edge[MAXN];

int V[MAXN];
int recid[MAXN];
VP cafe[MAXN];

int V2[MAXN];
int banned;

void dfs2(int id)
{
	V2[id] = 1;

	int i, sz;
	sz = edge[id].size();
	for(i = 0; i < sz; ++i)
	{
		int a = edge[id][i];
		if(a != banned && V[a] < 2 && V2[a] == 0)
			dfs2(a);
	}
}

int check(int id, int depth, int a)
{
	if(depth == 0)
		return 1;

	for(int i = 0; i < N; ++i)
		V2[i] = 0;

	banned = id;
	dfs2(recid[depth - 1]);

	return !V2[a]; // must iff not reached
}

void rec(int id, int depth)
{
	printf("%d", zip[id]);
	V[id] = 1;
	recid[depth] = id;
	cafe[depth].clear();

	int i, j, sz;
	sz = edge[id].size();
	for(i = 0; i < sz; ++i)
	{
		int a = edge[id][i];
		if(V[a] == 0)
		{
			int c = check(id, depth, a);
			cafe[depth].push_back(PII(a, c));

//			printf("\n[[%d: %d %d]]\n", zip[id], zip[a], c);
		}
	}

	while(1)
	{
		int bestd = 0;
		int best = N;
		for(i = depth; i >= 0; --i)
		{
			int must = 0;

			int n = cafe[i].size();
			for(j = 0; j < n; ++j)
			{
				PII p = cafe[i][j];
				int a = p.first;

				if(V[a] == 0)
				{
					must = (must || p.second);
					if(zip[best] > zip[a])
					{
						best = a;
						bestd = i;
					}
				}
			}

			if(must)
				break;
		}

		if(best == N || bestd != depth) // backtrack
			break;

//		printf("(%d ->) ", zip[id]);
		rec(best, depth + 1);
	}

//	printf("(<- %d) ", zip[id]);

	V[id] = 2;
}

int main()
{
	scanf("%d", &T);
	for(int TT = 1; TT <= T; ++TT)
	{
		int i;
		int mini = 0;

		scanf("%d %d", &N, &M);
		for(i = 0; i < N; ++i)
		{
			scanf("%d", zip + i);

			if(zip[mini] > zip[i])
				mini = i;
		}

		for(i = 0; i < M; ++i)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			--a;
			--b;

			edge[a].push_back(b);
			edge[b].push_back(a);
		}

		printf("Case #%d: ", TT);

		zip[N] = 100000;
		rec(mini, 0);

		printf("\n");

		for(i = 0; i < N; ++i)
		{
			V[i] = 0;
			edge[i].clear();
		}
	}

	return 0;
}
