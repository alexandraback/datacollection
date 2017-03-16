/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>
#include<vector>

int tests,
    verts,
    count,
    visited[1024],
    flag = 0;
std::vector<int> graph[1024];

inline static const bool check(void);
inline static const bool dfs(const int &v, const int &F);

int main(void)
{
	scanf("%d", &tests);
	for(int t = 1; t <= tests; ++ t)
	{
		printf("Case #%d: ", t);
		scanf("%d\n", &verts);
		for(int v = 0; v < verts; ++ v)
		{
			scanf("%d", &count);
			graph[v].resize(count);
			for(int c = 0; c < count; ++ c)
			{
				scanf("%d", &graph[v][c]);
				-- graph[v][c];
			}
		}

		puts(check()?"Yes":"No"); 
	}

	return 0;
}

inline static const bool check(void)
{
	for(int v = 0; v < verts; ++ v)
		if(dfs(v, ++flag))
			return true;

	return false;
}

inline static const bool dfs(const int &v, const int &F)
{
	visited[v] = F;
	for(int n = 0; n < graph[v].size(); ++ n)
	{
		if(visited[graph[v][n]] == F)
			return true;

		if(dfs(graph[v][n], F))
			return true;
	}

	return false;
}
