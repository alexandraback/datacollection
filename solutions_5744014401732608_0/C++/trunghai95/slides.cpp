#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int test;
int b, m;
bool edge[51][51];
vector<int> vc;

int countPath(int p)
{
	if (p >= b)
	{
		for (int i = 1; i < vc.size(); ++i)
		if (!edge[vc[i-1]][vc[i]])
			return 0;
		if (!edge[vc.back()][b])
			return 0;
		return 1;
	}

	vc.push_back(p);
	int res = countPath(p+1);
	vc.pop_back();
	res += countPath(p+1);
	return res;
}

bool tryEdge(int u, int v)
{
	// printf("-- %d %d\n", u, v);
	if (u == b)
	{
		vc.clear();
		vc.push_back(1);
		if (countPath(2) == m)
			return true;
		return false;
	}

	int uu = u, vv = v + 1;
	if (vv > b)
		++uu, vv = uu + 1;
	edge[u][v] = true;
	if (tryEdge(uu, vv))
		return true;
	edge[u][v] = false;
	if (tryEdge(uu, vv))
		return true;

	return false;
}

int main()
{
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt)
	{
		scanf("%d %d", &b, &m);

		memset(edge, 0, sizeof(edge));

		if (tryEdge(1, 2))
		{
			printf("Case #%d: POSSIBLE\n", tt);
			for (int i = 1; i <= b; ++i)
			{
				for (int j = 1; j <= b; ++j)
					printf("%d", edge[i][j]?1:0);
				printf("\n");
			}
		}
		else
			printf("Case #%d: IMPOSSIBLE\n", tt);
	}
	return 0;
}