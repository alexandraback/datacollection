#pragma comment(linker, "/STACK:255000000")
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <stack>
#include <memory.h>
#include <algorithm>
#include <math.h>
#include <valarray>
#include <complex>
#include <bitset>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef complex<double> comp;

long double eps = 1e-7;
const int BASE = (int) 1e9;
const long double PI = 3.1415926535897932384626433832795;
const int MOD = (int) 1e9 + 7;
const int HMOD = (1 << 18) - 1;
const int INF = 1 << 30;
const LL LLINF = 1ll << 60;

char buf[1000];

int t;
int n, m;
vector< set<int> > g;
string s[10];
int a[9] = {0, 1, 2, 3, 4, 5, 6, 7};
bool used[9];

bool operator < (string a, string b)
{
	if (a.size() < b.size())
		return true;
	if (a.size() > b.size())
		return false;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] < b[i])
			return true;
		if (a[i] > b[i])
			return false;
	}
	return false;
}

string Dfs(int v, int & pos)
{
	string res = "";
	used[v] = true;
	while (pos < n)
	{
		if (g[v].find(a[pos]) != g[v].end() && !used[a[pos]])
		{
			pos++;
			res += Dfs(a[pos - 1], pos);
		}
		else
			break;
	}
	return s[v] + res;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for (int k = 0; k < t; k++)
	{
		scanf("%d%d", &n, &m);
		g.clear();
		g.resize(n);
		getchar();
		for (int i = 0; i < n; i++)
			cin >> s[i];
		for (int i = 0; i < m; i++)
		{
			int from, to;
			scanf("%d%d", &from, &to);
			from--; to--;
			g[from].insert(to);
			g[to].insert(from);
		}
		string res = "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
		do
		{
			memset(used, 0, sizeof(used));
			int pos = 1;
			string cur = Dfs(a[0], pos);
			bool flag = false;
			for (int i = 0; i < n; i++)
				if (!used[i])
					flag = true;
			if (flag)
				continue;
			if (cur < res)
				res = cur;

		} while (next_permutation(a, a + n));
		cout << "Case #" << k + 1 << ": " << res << "\n";
	}
	return 0;
}