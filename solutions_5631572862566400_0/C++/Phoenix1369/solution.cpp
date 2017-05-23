#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
#define MEM(x, y) memset((x), (y), sizeof(x))
typedef std::vector<int> vin;

const int MAXN = 1005;
bool adjac[MAXN][MAXN]{ };
int bondu[MAXN]{ }; // Upper Bonds
int bonds[MAXN]{ };
int dfsid[MAXN]{ };
int dfslo[MAXN]{ };
int final[MAXN]{ };
int graph[MAXN]{ };
int maxnm[MAXN]{ };
vin upper[MAXN]{ };
bool visit[MAXN]{ };
vin numbr[MAXN]{ };
int A, dfsIter, M, N, T;
vin stackCC;
int numP;

void dfs(int cur)
{
	int tempo;
	stackCC.push_back(cur);
	dfsid[cur] = dfslo[cur] = tempo = dfsIter++;
	visit[cur] = true;
	if(bonds[graph[cur]] || bondu[graph[cur]])
		bondu[cur] = true;
	if(!dfsid[graph[cur]])
		dfs(graph[cur]);
	if(visit[graph[cur]])
		tempo = std::min(dfslo[graph[cur]], tempo);
	dfslo[cur] = std::min(tempo, dfslo[cur]);
	if(dfsid[cur] == dfslo[cur])
	{
                int I = stackCC.size()-1;
                while(cur != stackCC[I]) --I;
                M = stackCC.size() - I;
		//printf("[%d]: %d\n", cur, M);
		do {
			int nxt = stackCC.back();
			visit[nxt] = false;
			stackCC.pop_back();
			final[nxt] = M;
			if(cur == nxt)
				break;
		} while(true);
		A = std::max(M, A);
		if(M == 1)
			final[cur] = std::max(final[graph[cur]] + 1, final[cur]);
	}
	else
		final[cur] = std::max(final[graph[cur]] + 1, final[cur]);
	//if(bonds[graph[cur]]) // Direct Connection
	//	numbr[bonds[graph[cur]]].push_back(final[cur]);
}

void dfs2(int cur)
{
	visit[cur] = true;
	for(auto& nxt: upper[cur])
	{
		dfs2(nxt); // Indirect Connection
		//printf("[%d]: %d->%d\n", cur, nxt, final[nxt]);
		maxnm[cur] = std::max(std::max(final[nxt], maxnm[nxt]), maxnm[cur]);
	}
	if(bonds[cur])
	{
		if(upper[cur].empty())
			maxnm[cur] = 2;
		//printf("[%d]: %d\n", cur, maxnm[cur]);
		numbr[bonds[cur]].push_back(maxnm[cur]);
	}
}

int main()
{
	scanf(" %d", &T);
	for(int _T = 1; _T <= T; ++_T)
	{
		A = 0;
		dfsIter = 1;
		MEM(bonds, 0);
		MEM(dfsid, 0);
		MEM(dfslo, 0);
		MEM(final, 0);
		MEM(graph, 0);
		MEM(maxnm, 0);
		numbr[0].clear();
		MEM(adjac, false);
		MEM(bondu, false);
		MEM(visit, false);
		scanf("%d", &N);
		for(int i = 1; i <= N; ++i)
		{
			scanf("%d", &graph[i]);
			adjac[i][graph[i]] = true;
			if(adjac[graph[i]][i]) // Lower of Two
			{
				//printf("(%d %d)\n", graph[i], i);
				bonds[i] = bonds[graph[i]] = graph[i];
				bondu[i] = bondu[graph[i]] = true;
			}
			numbr[i].clear();
			upper[i].clear();
		}
		for(int i = 1; i <= N; ++i) if(!bondu[i])
			upper[graph[i]].push_back(i);
		for(int i = 1; i <= N; ++i) if(!dfsid[i] && upper[i].empty())
		{
			M = 0;
			stackCC.clear();
			dfs(i);
			A = std::max(M, A);
		}
		for(int i = 1; i <= N; ++i) if(!dfsid[i])
		{
			M = 0;
			stackCC.clear();
			dfs(i);
			A = std::max(M, A);
		} //*/
		MEM(visit, false);
		for(int i = 1; i <= N; ++i) if(bonds[i] && !visit[i])
			dfs2(i);
		numP = 0;
		for(int i = 1; i <= N; ++i) if(!numbr[i].empty())
		{
			std::sort(ALL(numbr[i]), std::greater<int>());
			A = std::max(numbr[i][0]+numbr[i][1]-2, A);
			++numP;
		}
		if(numP > 1)
		{
			numP -= 2; numP <<= 1;
			for(int i = 1; i <= N; ++i) if(!numbr[i].empty())
			{
				for(int j = 1; j <= N; ++j) if((i != j) && !numbr[j].empty())
					A = std::max(numbr[i][0] + numbr[j][0] + numP, A);
			}
		}
		printf("Case #%d: %d\n", _T, A);
	}
	return 0;
}

/*
2
10
10 9 2 5 7 10 10 2 6 2
>> 4
10
3 5 1 8 2 9 10 4 6 7
>> 10
*/