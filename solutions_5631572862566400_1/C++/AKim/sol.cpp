#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 1010;

vector<int> rb[maxn], rrb[maxn];
set<pair<int, int> > st;
vector<pair<int, int> > check;
bool pm[maxn], now[maxn];
int tin[maxn], tima = 0;

int dfs(int u, int p) {
	pm[u] = 1;
	now[u] = 1;
	int mx = 0;
	for(int i = 0; i < (int)rb[u].size(); i++) {
		int v = rb[u][i];
		if(pm[v] || v == p) continue;
		mx = max(mx, dfs(v, u));
	}

	now[u] = 0;
	return(mx + 1);
}

void get(int u, int &lines) {
	pm[u] = 1;
	now[u] = 1;
	tin[u] = tima++;
	for(int i = 0; i < (int)rrb[u].size(); i++) {
		int v = rrb[u][i];

		if(now[v]) {
			lines = max(lines, tin[u] - tin[v] + 1);
		}

		if(pm[v]) continue;
		get(v, lines);
	}

	now[u] = 0;
	return;
}

int main() {

	#ifdef SOL
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	int t;
	scanf("%d", &t);
	for(int q = 1; q <= t; q++) {

		for(int i = 0; i < maxn; i++) {
			rb[i].clear();
			rrb[i].clear();
			pm[i] = 0;
			now[i] = 0;
		}
		st.clear();
		check.clear();

		printf("Case #%d: ", q);

		int n;
		scanf("%d", &n);
		int lines = 0;
		for(int i = 0; i < n; i++) {
			int v;
			scanf("%d", &v);
			v--;
			rb[v].pb(i);
			rrb[i].pb(v);
			if(st.count(mp(v, i))) {
				check.pb(mp(v, i));
			}
			st.insert(mp(i, v));
		}
		for(int i = 0; i < (int)check.size(); i++) {
			lines += dfs(check[i].fs, check[i].sc) + dfs(check[i].sc, check[i].fs);
		}
		for(int i = 0; i < n; i++) {
			if(!pm[i]) {
				get(i, lines);
			}
		}

		printf("%d\n", lines);
	}

	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
	#endif
	return(0);
}

// by Andrey Kim
