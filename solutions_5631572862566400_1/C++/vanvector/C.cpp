#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <stdio.h>
#include <limits.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <functional>
#include <cassert>
#include <map>
#include <set>
#include <list>
#include <iostream>

using namespace std;
typedef long long lli;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const lli LINF = 0x3f3f3f3f3f3f3f3f;

//#define _LOCAL_DEBUG_
#ifdef _LOCAL_DEBUG_
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...) 
#endif

const int MAX = 1010;
int n;

void clear() {
}

void solve(int t) {
	scanf("%d", &n);
	int b[MAX];
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	for (int i = 0; i < n; i++) b[i]--;
	int ml[MAX] = { 0 }, hasEdge[MAX] = { 0 }, l[MAX] = { 0 };
	memset(l, -1, sizeof(l));
	for (int i = 0; i < n; i++) hasEdge[b[i]] = 1;

	int mc = 0;
	for (int i = 0; i < n; i++) {
		int t = i;
		int c = 0;
		int u[MAX] = { 0 };
		do {
			if (u[t]) {
				c = 0;
				break;
			}
			u[t] = 1;
			ml[i]++, c++, l[i] = t;
			t = b[t];
		} while (t != i);
		mc = max(mc, c);
	}

	int dp[MAX][MAX] = { 0 };
	for (int i = 0; i < n; i++) 
		for (int j = i + 1; j < n; j++)
			if (b[l[i]] == l[j] && b[l[j]] == l[i]) {
				dp[l[i]][l[j]] = max(dp[l[i]][l[j]], ml[i] + ml[j] - 2);
				dp[l[j]][l[i]] = max(dp[l[j]][l[i]], ml[i] + ml[j] - 2);
			}

	int mc2 = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			mc2 += dp[i][j];

	mc = max(mc, mc2);
	printf("Case #%d: %d\n", t, mc);
}

int main() {
#ifdef _LOCAL_VAN
	//freopen("in.txt", "r", stdin);
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		clear();
		solve(i + 1);
	}
	return 0;
}