#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

typedef long long LL;

int T, n, m;

char buf[1 << 6];

int used[1 << 6];
int u[1 << 6];

int G[1 << 6][1 << 6];

int s[1 << 6];

int N;

void dfs(int x)
{
	u[x] = 1;
	for(int to = 0; to < n; ++to)
		if (G[x][to] && !used[to] && !u[to])
			dfs(to);
}

vector<int> p;

pair<string, int> cities[1 << 6];


int go(int x, int & pos)
{
	pos++;
	used[x] = 1;
	while (pos < n && G[x][cities[p[pos]].second])
	{
		if (!go(cities[p[pos]].second, pos))
			return 0;
	}
	for(int i = 0; i < n; ++i)
		if (G[x][i] && !used[i])
			return 0;
	return 1;
}

bool check(int top)
{
	memset(u, 0, sizeof(u));
	for(int k = 0; k < top; ++k)
		dfs(s[k]);
	bool bad = 0;
	for(int k = 0; k < n; ++k)
		bad |= !u[k] && !used[k];
	return bad;
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for(int I = 0; I < T; ++I)
	{
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i)
		{
			scanf("%s", buf);
			cities[i] = make_pair(string(buf), i);
		}
		memset(G, 0, sizeof(G));
		sort(cities, cities + n);
		for(int i = 0; i < m; ++i)
		{
			int from, to;
			scanf("%d%d", &from, &to);
			from--, to--;
			G[from][to] = 1;
			G[to][from] = 1;
		}
		memset(used, 0, sizeof(used));
		N = 0;
		string res = cities[0].first;
		used[cities[0].second] = 1;
		s[N++] = cities[0].second;
		int start = 0;
		for(int i = 1; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				int v = cities[j].second;
				if (used[v])
					continue;
				int top = -1;
				for(int k = N - 1; k >= 0; --k)
				{
					if (G[s[k]][v])
					{
						top = k + 1;
						break;
					}
				}
				if (top != -1)
				{
					if (!check(top))
					{
						N = top;
						s[N++] = v;
						res += cities[j].first;
						used[v] = 1;
						break;
					}
					else
						top = -1;
				}
				//memset(u, 0, sizeof(u));
				//if (G[cities[0].second][v] && !start)
				//{
				//	for(int k = N - 1; k >= 0; --k)
				//	{
				//		if (G[s[k]][cities[0].second])
				//		{
				//			top = k + 1;
				//			break;
				//		}
				//	}
				//	if (top != -1 && !check(top))
				//	{
				//		start = 1;
				//		N = top;
				//		s[N++] = cities[0].second;
				//		s[N++] = v;
				//		res += cities[j].first;
				//		used[v] = 1;
				//		break;
				//	}
				//}
			}
		}
		//p.clear();
		//for(int i = 0; i < n; ++i)
		//	p.push_back(i);
		//string rr = "";
		//do
		//{
		//	memset(used, 0, sizeof(used));
		//	int pos = 0;
		//	if (go(cities[p[0]].second, pos))
		//	{
		//		string cur = "";
		//		for(int i = 0; i < n; ++i)
		//			cur += cities[p[i]].first;
		//		if (rr == "" || rr > cur)
		//			rr = cur;
		//	}
		//}
		//while (next_permutation(p.begin(), p.end()));
		//if (rr != res)
		//	printf("%d\n", I + 1);
		printf("Case #%d: %s\n", I + 1, res.c_str());
	}
	return 0;
}