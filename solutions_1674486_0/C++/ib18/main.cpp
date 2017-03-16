#pragma comment(linker, "/STACK:25600000")
#define _CRT_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <set>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(ll i=0; i<n; i++)
#define FOR(i, x, y) for(ll i=x; i<=y; i++)
#define RFOR(i, x, y) for(ll i=x; i>=y; i--)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define PII pair<ll, ll>
const double pi=acos(-1.0);
const double eps = 1e-9;
const double INF = 1000000000000000;

vector< vector<int> > g, gr;
bool u[1024];
bool p;

void dfs(int v)
{
	u[v] = true;
	REP(i, g[v].size())
	{
		int next = g[v][i];
		if (u[next])
			p = true;
		else
			dfs(next);
	}
}	

int main()
{	
	freopen("input.txt", "r", stdin);
	freopen("a-small.txt", "w", stdout);

	int tests;
	cin >> tests;
	REP(TEST, tests)
	{
		g.clear();
		gr.clear();
		memset(u, 0, sizeof u);
		p = false;

		int n, m;
		cin >> n;
		g.resize(n);
		gr.resize(n);

		REP(i, n)
		{
			int m;
			cin >> m;
			REP(j, m)
			{
				int x, y;
				x = i;
				cin >> y;
				--y;
				g[x].pb(y);
				gr[y].pb(x);
			}
		}

		REP(i, n)
			if (gr[i].empty())
			{
				memset(u, 0, sizeof u);
				dfs(i);
			}

		printf("Case #%d: ", TEST + 1);
		if (p)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}