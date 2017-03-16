#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

const int N = 50 + 5;

int zip[N];
vector<int> a[N];
int father[N];
int col[N], vis[N];
int testCases, n, m;
string ans;

void paint(int u)
{
	vis[u] = 1;
	for (int i = 0; i < a[u].size(); ++i)
		if (col[a[u][i]] < 2 && ! vis[a[u][i]]) paint(a[u][i]);
}

int check()
{
	int cnt = 0;
	memset(vis, 0, sizeof vis);
	for (int i = 0; i < n; ++i)
		if (col[i] < 2 && ! vis[i]) {
			++cnt;
			paint(i);
		}
	return cnt < 2;
}

string convert(int x)
{
	string ret("00000");
	for (int i = 4; i >= 0; --i, x /= 10) ret[i] = x % 10 + '0';
	return ret;
}

void dfs(int u)
{
	col[u] = 1;
	ans += convert(zip[u]);
	int w = -1, vv = -1;
	int s = 100000;
	for (int v = u; v != -1; v = father[v]) {
		if (check()) {
			int ww = -1;
			int ss = 100000;
			for (int i = 0; i < a[v].size(); ++i) {
				if (col[a[v][i]]) continue;
				if (zip[a[v][i]] < ss) {
					ww = a[v][i];
					ss = zip[a[v][i]];
				}
			}
			if (ss < s) {
				w = ww;
				vv = v;
				s = ss;
			}
		}
		col[v] = 2;
	}
	if (w == -1) return;
	for (int v = vv; v != -1; v = father[v]) col[v] = 1;
	father[w] = vv;
	dfs(w);
}

int main()
{
	scanf("%d", &testCases);
	for (int index = 1; index <= testCases; ++index) {
		for (int i = 0; i < N; ++i) a[i].clear();
		ans.clear();
		
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) scanf("%d", &zip[i]);
		while (m--) {
			static int u, v;
			scanf("%d%d", &u, &v);
			--u;
			--v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		
		int s = 100000;
		int t = -1;
		for (int i = 0; i < n; ++i)
			if (zip[i] < s) {
				s = zip[i];
				t = i;
			}
		father[t] = -1;
		memset(col, 0, sizeof col);
		dfs(t);

		printf("Case #%d: %s\n", index, ans.c_str());
	}
	return 0;
}