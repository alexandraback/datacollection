#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>
#include <unordered_map>

using namespace std;

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.14159265358979
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

int was[55];
int dfswas[55];
pair<string,int> val[55];
int a[55][55];
vector<int> st1, st2;
int n;
vector<vector<int> > g;
void dfs(int v)
{
	if (dfswas[v])
		return;
	dfswas[v] = 1;
	FOR(i, 0, g[v].size())
	{
		if (was[g[v][i]])
			continue;
		dfs(g[v][i]);
	}
}
string res;
int main()
{
#ifdef Fcdkbear
	freopen("in.txt", "r", stdin);
	freopen("out.txt","w",stdout);
	double beg = clock();
#else
	freopen("in.txt", "r", stdin);
	freopen("out.txt","w",stdout);
#endif

	int t;
	scanf("%d", &t);
	FOR(it, 1, t + 1)
	{
		res = "";
		int m;
		scanf("%d%d", &n, &m);
		FOR(i, 0, n)
		{
			cin >> val[i].first;
			val[i].second = i;
		}
		g.clear();
		g.resize(n);
		MEMS(a, 0);
		FOR(i, 0, m)
		{
			int v1, v2;
			scanf("%d%d", &v1, &v2);
			v1--;
			v2--;
			a[v1][v2] = a[v2][v1] = 1;
			g[v1].push_back(v2);
			g[v2].push_back(v1);
		}
		st1.clear();
		st2.clear();
		sort(val, val + n);
		MEMS(was, 0);
		FOR(k, 0, n)
		{
			FOR(i, 0, n)
			{
				int v = val[i].second;
				if (was[v])
					continue;
				bool f = false;
				if (st1.size() == 0)
				{
					f = true;
				}
				else
				{
					st2 = st1;
					while (st2.size())
					{
						int p = (int)st2.size() - 1;
						if (a[st2[p]][v])
						{
							f = true;
							break;
						}
						st2.pop_back();
					}
				}
				if (!f)
					continue;
				st2.push_back(v);
				MEMS(dfswas, 0);
				FOR(j, 0, st2.size())
					dfs(st2[j]);
				f = true;
				FOR(j, 0, n)
				{
					if ((was[j] == 0) && (dfswas[j] == 0))
					{
						f = false;
						break;
					}
				}
				if (f)
				{
					st1 = st2;
					was[v] = 1;
					res += val[i].first;
					break;
				}
			}
		}
		printf("Case #%d: %s\n", it, res.c_str());
	}

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
}