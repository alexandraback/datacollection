#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 1000;
double a[N], b[N];
bool vx[N], vy[N];
int my[N], n;

bool dfs(int u) {
	if(u == -1) return true;
	if(vx[u]) return false;
	vx[u] = true;
	for(int v = 0; v < n; ++v) if(a[u] < b[v])
		if(!vy[v]) {
			vy[v] = true;
			if(dfs(my[v])) return my[v] = u, true;
		}
	return false;
}

int maxMatch() {
	int res = 0;
	memset(my, -1, sizeof my);
	for(int i = 0; i < n; ++i) {
		memset(vx, 0, sizeof vx);
		memset(vy, 0, sizeof vy);
		if(dfs(i)) ++res;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	int nTest; cin >> nTest;
	for(int test = 0; test < nTest; ++test) {
		cin >> n;
		for(int i = 0; i < n; ++i) cin >> a[i];
		for(int i = 0; i < n; ++i) cin >> b[i];
		int res2 = n - maxMatch();
		transform(a, a + n, a, negate<double>());
		transform(b, b + n, b, negate<double>());
		int res1 = maxMatch();
		printf("Case #%d: %d %d\n", test + 1, res1, res2);
	}
	return 0;
}
