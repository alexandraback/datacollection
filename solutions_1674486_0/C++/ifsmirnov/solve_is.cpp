#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1050;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int n;
vector<int> e[maxn];
int b[maxn];
int reach[maxn][maxn];

void dfs(int v)
{
	b[v] = 1;
	forn(i, e[v].size()) if (!b[e[v][i]]) dfs(e[v][i]);
}

void fillReach()
{
	forn(i, n)
	{
		memset(b, 0, sizeof b);
		dfs(i);
		memcpy(reach[i], b, sizeof b);
	}
}

bool intersect(int i, int j)
{
	forn(k, n) if (reach[i][k] && reach[j][k])
		return true;
	return false;
}

void scan()
{
	cin >> n;
	forn(i, n)
	{
		int m, x;
		cin >> m;
		forn(j, m)
		{
			cin >> x;
			e[x-1].push_back(i);
		}
	}
}

bool solve()
{
	forn(i, maxn) e[i].clear();
	scan();
	fillReach();
	forn(v, n) forn(i, e[v].size()) forn(j, i) if (intersect(e[v][i], e[v][j])) return true;
	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	forn(i, t)
	{
		cout << "Case #" << i+1 << ": " << (solve() ? "Yes" : "No") << endl;
	}
	
	return 0;
}
