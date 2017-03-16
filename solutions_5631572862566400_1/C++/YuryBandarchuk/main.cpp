#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <utility>
#include <memory.h>
#include <cassert>
#include <iterator>
#include <bitset>
#include <iomanip>
#include <complex>
#include <queue>
#include <ctime>
#include <deque>
#include <stack>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second

const int N = 55555;

int n;
int result;
int timer = 0;
int p[N];
int tin[N];
bool used[N];
int pp[N];
vector<int> g[N];

int color[N];

int good = 0;

int own[N];
int len[N];

int sz = 0;

vector<int> v;

multiset<int> have[N];

void dfs(int ver) {
	v.pb(ver);
	color[ver] = 1;
	++good;
	for (int i = 0; i < (int)g[ver].size(); i++) {
		int to = g[ver][i];
		int kol = 0;
		if (color[to] == 1) {
			sz++;
			for (int j = (int)v.size() - 1; j >= 0; --j) {
				kol++;
				own[v[j]] = sz;
				if (v[j] == to) break;
			}
			len[sz] = kol;
		}
		if (color[to] == 0) {
			dfs(to);
		}
	}
	color[ver] = 2;
	v.pop_back();
}

int from;

int went[N], dist[N];

int f[N];

int last = -1;

void go(int v, int d) {
	if (own[v] != -1) {
		last = v;
		if (d > f[last]) {
			multiset<int> :: iterator it;
			it = have[own[v]].find(f[last]);
			if (it != have[own[v]].end()) have[own[v]].erase(it);
			//have[own[v]].erase(have[own[v]].find(f[last]));
		have[own[v]].insert(d);
		f[last] = d;
		}
		//cout << own[v] << " " << d << "!" << endl;
		return;
	}
	last = v;
	go(pp[v], d + 1);
}

void solve(int test) {
	scanf("%d", &n);
	sz = 0;
	for (int i = 1; i <= n; i++) g[i].clear();
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		have[i].clear();
		scanf("%d", &pp[i]);
		g[i].pb(pp[i]);
		own[i] = -1;
		len[i] = 0;
		color[i] = 0;
	}
	v.clear();
	for (int i = 1; i <= n; i++) {
		f[i] = -1;
		if (color[i] == 0) {
			dfs(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (own[i] == -1) {
			//cout << i << "?" << endl;
			go(i, 0);
		}
	}
	int ans = 0;
	/*for (int i = 1; i <= n; i++) {
		if (own[i] != -1) {
			ans = max(ans, len[own[i]]);
		}
		for (int j = i + 1; j <= n; j++) {
			if (own[j] == -1) {
				if (went[j] == went[i] && )
			}
		}
	}*/
		int out = 0;
	for (int i = 1; i <= sz; i++) {
		int iter = 1000;
		int ret = len[i];
		ans = max(ans, ret);
		if (len[i] > 2) {
			continue;
		}
		while (iter--) {
			if ((int)have[i].size() == 0) break;
			multiset<int> :: iterator it = have[i].end(); --it;
			int val = *it;
			ret += *it;
			have[i].erase(it);
		}
		ans = max(ans, ret);
		out += ret;
		have[i].clear();
	}
	ans = max(ans, out);
	printf("Case #%d: %d\n", test, ans);
	//return;
	result = 0;
	do {
		for (int i = 2; i <= n; i++) {
			int head = p[1];
			int tail = p[i];
			bool cor = true;
			for (int j = 1; j <= i; j++) {
				int id = p[j];
				id = pp[id];
				int nxt = p[j + 1];
				if (j + 1 > i) nxt = head;
				int pr = p[j - 1];
				if (j == 1) {
					pr = tail;
				}
				if (id == nxt || id == pr) {
					continue;
				} else {
					cor = false;
					break;
				}
			}
			if (cor) result = max(result, i);
		}
	} while (next_permutation(p + 1, p + 1 + n));
	if (result != ans) puts("FUCK"), cout << result - ans << endl; else 
	cout <<"OK"<<endl;
}

int main() {
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int tc;
	scanf("%d", &tc);
	tc = 5;
	for (int i = 1; i <= tc; i++) {
		solve(i);
	}
	return 0;
}