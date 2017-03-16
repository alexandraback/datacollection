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

vector <vector <int> > g;
vector <char> used;
int N;
vector <int> p;
int pos = 0;
bool dfs(int v)
{
	if (pos == N)
	{
		return true;
	}
	used[v] = 1;
	for (int i = 0; i < g[v].size() && pos != N; i++)
	{
		int to = g[v][i];
		if (!used[to] && to == p[pos])
		{
			pos++;
			dfs(to);
			i = -1;
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
			g[x].pb(y);
			g[y].pb(x);
		}
		p.resize(n);
		for (int i = 0; i < n; i++)
			p[i] = i;
		string res = string(5 * n, '9');
		do
		{
		   pos = 1;
		   used.assign(n, 0);
		   dfs(p[0]);
		   if (pos == N)
		   {
			   string tmp = "";
			   for (int i = 0; i < n; i++)
			   {
				   tmp += ZIP[p[i]];
			   }
			   res = min(res, tmp);
		   }
		}while (next_permutation(p.begin(), p.end()));

		cout << "Case #" << q + 1 << ": ";
		cout << res << endl;
	}
    return 0;
}
#endif