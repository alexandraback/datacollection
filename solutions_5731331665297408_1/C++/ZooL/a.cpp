#if 1
#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <string>
#include <numeric>
#include <cstring>
#include <ctime>
#include <unordered_map>

using namespace std;
#define mp make_pair
#define X first
#define Y second
#define pb push_back

typedef pair<int, int> pii ;
typedef long long LL;
typedef long double LD;
typedef vector<int> vi;

const LL inf = 1e9;
const LD eps = 1e-9;

vector <vector <pair<string, int> > > g;
vector <char> used;
int N;
string res;
void dfs(int v)
{
	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].Y;
		if (!used[to])
		{
			res += g[v][i].X;
			dfs(to);
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int q = 0; q < T; q++)
	{
		int n, m;
		scanf("%d %d\n", &n, &m);
		N = n;
		g.clear();
		g.resize(n);
		
		vector <string> ZIP(n);
		char ss[6] = {};
		for (int i = 0; i < n; i++)
			gets(ss), ZIP[i] = ss;
		for (int i = 0; i < m; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			x--;y--;
			g[x].pb(mp(ZIP[y], y));
			g[y].pb(mp(ZIP[x], x));
		}
		for (int i = 0; i < n; i++)
		{
			sort(g[i].begin(), g[i].end());
		}
		
		int p = min_element(ZIP.begin(), ZIP.end()) - ZIP.begin(); 
		res = ZIP[p];
		used.assign(n, 0);
		dfs(p);

		cout << "Case #" << q + 1 << ": ";
		cout << res << endl;
	}
    return 0;
}
#endif