#include<stdlib.h>
#include<time.h>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<set>
#include<queue>
#include<bitset>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long UL;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define sz(x) ((int)(x.size()))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int N = 1e3 + 7;
const int P = 1e7 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e7;
const double EPS = 1e-10;
int n, m, ans, f[N], p[N];
bool v[N];
bool chk(int t) {
	if (!(p[t - 1] == f[p[0]] || p[1] == f[p[0]]))
		return false;
	p[t] = p[0];
	for (int i = 1; i < t; ++i)
		if (!(p[i - 1] == f[p[i]] || p[i + 1] == f[p[i]]))
			return false;
	return true;
}
void dfs(int t) {
	if (t >= m) {
		if (chk(m))
			ans = m;
		return;
	}
	for (int i = 1; i <= n; ++i)
		if (!v[i]) {
			v[i] = true, p[t] = i;
			dfs(t + 1);
			v[i] = false;
		}
}
int main() {
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int _c = 1; _c <= T; ++_c) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			v[i] = false;
			scanf("%d", &f[i]);
		}
		ans = 0;
		for (m = n; m > 0 && !ans; --m) {
			dfs(0);
		}
		printf("Case #%d: %d\n", _c, ans);
	}
	return 0;
}
