#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

#define N 64

bool map[N][N];
int n;
bool flag[N];
vector<int> s;
vector<int> e;
int vcnt;
bool result = false;

void step(int c, int e, bool visited[])
{
	int v;
	if(c == e)
	{
		vcnt++;
		if(vcnt > 1) result = true;
		return;
	}
	for(v = 1; v <= n && !result; v++)
	{
		if(map[c][v] && !visited[v])
		{
			visited[v] = true;
			step(v, e, visited);
			visited[v] = false;
		}
	}
}

bool _solve(int s, int e)
{
	bool visited[N];
	int v;
	memset(visited, 0, sizeof(visited));
	visited[s] = true;
	step(s, e, visited);
	return result;
}

bool solve()
{
	int ss = s.size();
	int se = e.size();
	int i, j;
	for(i = 0; i < ss; i++)
		for(j = 0; j < se; j++)
		{
			vcnt = 0;
			result = false;
			if(_solve(s[i], e[j]))
				return true;
		}
	return false;
}

int main()
{
	int T, i, j, k, m, v;
	scanf("%d", &T);
	for(i = 0; i < T; i++)
	{
		scanf("%d", &n);
		memset(map, 0, sizeof(map));
		memset(flag, 0, sizeof(flag));
		s.clear();
		e.clear();
		for(j = 1; j <= n; j++)
		{
			scanf("%d", &m);
			if(m == 0) e.push_back(j);
			for(k = 0; k < m; k++)
			{
				scanf("%d", &v);
				map[j][v] = true;
				flag[v] = true;
			}
		}
		for(j = 1; j <= n; j++)
		{
			if(!flag[j]) s.push_back(j);
		}
		printf("Case #%d: %s\n", i + 1, solve() ? "Yes" : "No");
	}

	return 0;
}