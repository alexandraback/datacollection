#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <complex>
#include <random>
#include <time.h>
#include <tuple>
#include <functional>
#include <list>
#include <limits.h>
#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d",&(x),&(y))
#define mul(x,y) ((ll)(x)*(y)%mod)
#define mtp make_tuple
#define add(x,y) ((ll)(x)+(y))%mod
#define F(i,n) for(int i = 0; i < n; i++)
#define FF(i,n) for(int i = 1; i <= n; i++)
#define println(x) printf("%d\n", x)
#define print(x) printf("%d ", x)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//
	
const int N = 1000;

int adj[N];
vector<int> rev[N];

int dfs(int i, int ban) {
	int _M = 0;
	for (auto &x : rev[i]) {
		if (x == ban) continue;
		_M = max(_M, dfs(x, ban));
	}
	return _M + 1;
}

int maxc[N];
int chk[N];
int dfsn;

int aa;
int ans2 = -1;

int dfs2(int i) {
	int a = adj[i];
	chk[i] = dfsn;
	if (chk[a]) {
		if (chk[a] == dfsn) {
			aa = a;
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		int d = dfs2(a);
		if (d) {
			if (i == aa) ans2 = max(ans2, d + 1);
			else return d + 1;
		}
		else {
			return 0;
		}
	}
	return 0;
}


int main() {
#ifndef __GNUG__
	freopen("C-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T; ni(T);
	FF(tt, T) {
		printf("Case #%d: ", tt);
		int n; ni(n);
		F(i, n) {
			int s; ni(s); s--;
			adj[i] = s;
			rev[s].push_back(i);
		}
		vector<pii> good;
		F(i, n) {
			if (adj[adj[i]] == i) {
				good.push_back(mp(i, adj[i]));
			}
		}
		vector<int> vals;
		for (auto &p : good) {
			int val = dfs(p.first, p.second);
			vals.push_back(val);
		}
		int ans1 = 0;
		for (auto &k : vals) ans1 += k;
		aa = 0;
		ans2 = -1;
		dfsn = 1;
		memset(chk, 0, sizeof(chk));
		F(i, n) {
			if (chk[i]) continue;
			dfs2(i);
			dfsn++;
		}
		println(max(ans1, ans2));
		F(i, n)rev[i].clear();
	}
	return 0;
}
