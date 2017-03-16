#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define BIG 1000000000
#define LL long long
#define MAXN 110
using namespace std;

int ntest;
int n, m, t;
int num[MAXN], low[MAXN];
bool inSet[MAXN], visit[MAXN];
vector<int> e[MAXN];
string s[MAXN];
set<pair<int, int> > bridge;
set<pair<string, int> > city;

void dfs(int u, int p) {
	num[u] = low[u] = ++t;
	for (int k = 0; k < e[u].size(); k++) {
		int v = e[u][k];
		if (v == p) continue;
		if (num[v] == 0) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			//cout << u << ' ' << v << ' ' << low[v] << ' ' << num[u] << endl;
			if (low[v] > num[u]) {
				//cout << u << ' ' << v << endl;
				bridge.insert(make_pair(u, v));
				bridge.insert(make_pair(v, u));
			}
		}
		else 
			low[u] = min(low[u], num[v]);
	}
}

void findBridges() {
	bridge.clear();
	memset(num, 0, sizeof(num));
	memset(low, 0, sizeof(low));
	t = 0;
	for (int i = 1; i <= n; i++)
		if (num[i] == 0) dfs(i, -1);
}

string solve(int u) {
	memset(inSet, false, sizeof(inSet));
	memset(visit, false, sizeof(visit));
	city.clear();
	city.insert(make_pair(s[u], u));
	inSet[u] = true;
	visit[u] = true;
	bool onBridge = false;
	string ans = s[u];
	for (int i = 0; i < n - 1; i++) {
		int best = -1;
		for (int k = 0; k < e[u].size(); k++) {
			int v = e[u][k];
			if (!inSet[v]) {
				inSet[v] = true;
				city.insert(make_pair(s[v], v));
			}
			if (!visit[v])
				if (best == -1 || s[v] < s[best]) best = v;
		}
		city.erase(make_pair(s[u], u));
		int v;
		if (!onBridge || best == -1) v = city.begin() -> second;
		else v = best;
		onBridge = bridge.find(make_pair(u, v)) != bridge.end() ||
				   bridge.find(make_pair(v, u)) != bridge.end();
		u = v;
		visit[u] = true;
		ans += s[u];
	}
	return ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> ntest;
	for (int test = 1; test <= ntest; test++) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> s[i];
		for (int i = 1; i <= n; i++) e[i].clear();
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		findBridges();
		int best = 1;
		for (int i = 2; i <= n; i++)
			if (s[i] < s[best]) best = i;
		cout << "Case #" << test << ": " << solve(best) << endl;
	}
}

