/***********************************************
* Author - LUONG VAN DO                        *
* Problem
* Algorithm
* Time Limit
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.141592653589793
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define M 1011

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, dem[M];
vi adj[M];
bool vis[M];

void dfs(int u) {
	vis[u] = true;
	REP(i, adj[u].size()) {
		int v = adj[u][i];
		dem[v]++;
		if (!vis[v]) dfs(v);
	}
}

bool check() {
	FOR (i, 1, n) {
		FOR (j, 1, n) {
			dem[j] = 0;
			vis[j] = false;
		}
		dfs(i);
		FOR (j, 1, n)
			if (dem[j] > 1) return true;
	}
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	//FileIn("exam"); FileOut("exam");
	#endif
	int test, m;
	scanf("%d", &test);
	FOR(tt, 1, test) {
		scanf("%d", &n);
		FOR (i, 1, n) {
			scanf("%d", &m);
			adj[i].resize(m);
			REP(j, m) scanf("%d", &adj[i][j]);
		}
		printf("Case #%d: ", tt);
		if (check()) puts("Yes");
		else puts("No");
	}
}