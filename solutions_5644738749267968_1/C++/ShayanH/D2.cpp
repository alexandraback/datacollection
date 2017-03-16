#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <ctime>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define VAL(x) #x << " = " << (x) << "   "
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define CLR(x, a) memset(x, a, sizeof x)
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define FOR(i, n) for (int i = 0; i < (n); i ++)
#define X first
#define Y second
#define EPS (1e-8)

//#define cin fin
//#define cout fout

//ifstream fin("problem.in");
//ofstream fout("problem.out");

const int MAXN = 1 * 1000 + 10;

vector<int> adj[MAXN];
bool mark[MAXN];
int match[3][MAXN], n;

bool dfs(int x)
{
	if (mark[x]) return false;

	mark[x] = true;
	for (int i = 0; i < SZ(adj[x]); i ++)
	{
		int v = adj[x][i];
		if (match[1][v] == -1 || dfs(match[1][v]))
		{
			match[0][x] = v;
			match[1][v] = x;
			return true;
		}
	}
	return false;
}

void biMatch()
{
	CLR(match, -1);
	for (int i = 0; i < n; i ++)
	{
		CLR(mark, 0);
		dfs(i);
	}
}

double a[MAXN], b[MAXN];

int main ()
{
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	
	for (int o = 1; o <= tc; o ++)
	{
		cin >> n;

		for (int i = 0; i < n; i ++) cin >> a[i];
		for (int i = 0; i < n; i ++) cin >> b[i];

		for (int i = 0; i < n; i ++) adj[i].clear();

		for (int i = 0; i < n; i ++)
			for (int j = 0; j < n; j ++)
				if (a[i] > b[j])
					adj[i].pb(j);
		biMatch();
		int ans1 = 0;
		for (int i = 0; i < n; i ++) ans1 += (match[0][i] != -1);

		for (int i = 0; i < n; i ++) adj[i].clear();

		for (int i = 0; i < n; i ++)
			for (int j = 0; j < n; j ++)
				if (a[i] < b[j])
					adj[i].pb(j);
		biMatch();
		int ans2 = 0;
		for (int i = 0; i < n; i ++) ans2 += (match[0][i] != -1);

		cout << "Case #" << o << ": ";
		cout << ans1 << ' ' << n - ans2 << endl;
	}
	return 0;
}

