
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (i = 0; i < (int)(n); ++i)
#define sz(v) ((v).size())
#define all(v) (v).begin(), (v).end()
#define sqr(x) ((x)*(x))
#define updMax(a, b) ((a) = max((a), (b)))
#define updMin(a, b) ((a) = min((a), (b)))

vector <vi> g;

const int maxn = 1000 + 10;

bool was[maxn];
int degIn[maxn];

bool dfs(int v)
{
	was[v] = true;
	int i, to;
	forn(i, sz(g[v])) {
		to = g[v][i];
		if (was[to] || dfs(to))
			return true;
	}
	return false;
}

void solve()
{
	g.clear();
	memset(degIn, 0, sizeof(degIn));
	int n, m, i, j, to;
	cin >> n;
	g.resize(n);
	forn(i, n) {
		cin >> m;
		forn(j, m) {
			cin >> to;
			--to;
			g[i].pb(to);
			++degIn[to];
		}
	}
	/*int start = -1;
	forn(i, n) {
		if (degIn[i] == 0) {
			start = i;
			break;
		}
	}
	if (start == -1) {
		cout << "No start vertex";
		return;
	}*/
	forn(i, n) {
		//if (degIn[i] == 0) {
			memset(was, false, sizeof(was));
			if (dfs(i)) {
				cout << "Yes";
				return;
			}
		//}
	}
	cout << "No";
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(false);

	int t, test;
	cin >> t;
	forn(test, t) {
		cout << "Case #" << test + 1 << ": ";
		solve();
		cout << "\n";
	}

	return 0;
}