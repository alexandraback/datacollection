#pragma comment(linker, "/STACK:500000000")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

#define y0 y0ChloeGraceMoretz
#define y1 y1ChloeGraceMoretz
#define ll long long
int nextInt() { int n; scanf("%d", &n); return n; }
ll nextLong() { ll n; scanf("%lld", &n); return n; }
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int INF = (int)1e9;
const int MOD = (int)1e9 + 7;

bool a[9][9];
bool ans[9][9];
int b, m;
bool found;
int cnt;
bool used[9];
int color[9];

void dfs(int x) {
	if (cnt > m) {
		return;
	}
	if (x == b - 1) {
		++cnt;
		return;
	}
	for (int i = 0; i < b; ++i) {
		if (a[x][i]) {
			dfs(i);
		}
	}
}

bool isCyclic(int x) {
	color[x] = 1;
	for (int i = 0; i < b; ++i) {
		if (a[x][i]) {
			if (color[i] == 0) {
				if (isCyclic(i)) {
					return true;
				}
			} else if (color[i] == 1) {
				return true;
			}
		}
	}
	color[x] = 2;
	return false;
}

void f(int x) {
	if (found) {
		return;
	}
	if (x == b - 1) {
		cnt = 0;
		for (int i = 0; i < b; ++i) {
			color[i] = false;
		}
		if (!isCyclic(0)) {
			dfs(0);
			if (cnt == m) {
				for (int i = 0; i < b; ++i) {
					for (int j = 0; j < b; ++j) {
						ans[i][j] = a[i][j];
					}
				}
				found = true;
			}
		}
		return;
	}
	used[x] = true;
	for (int mask = 1; mask < (1 << b); ++mask) {
		bool isCorrect = (mask & (1 << x)) == 0;
		if (isCorrect) {
			for (int i = 0; i < b; ++i) {
				if (mask & (1 << i)) {
					a[x][i] = true;
					if (a[i][x]) {
						isCorrect = false;
						break;
					}
				}
			}
		}
		if (isCorrect) {
			for (int i = 0; i < b; ++i) {
				if ((mask & (1 << i)) && !used[i]) {
					f(i);
				}
			}
		}
		for (int i = 0; i < b; ++i) {
			if (mask & (1 << i)) {
				a[x][i] = false;
			}
		}
	}
	used[x] = false;
}

int main() {
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("out.txt", "wt", stdout);
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt) {
		scanf("%d %d", &b, &m);
		for (int i = 0; i < b; ++i) {
			used[i] = false;
			for (int j = 0; j < b; ++j) {
				a[i][j] = 0;
			}
		}
		found = false;
		f(0);
		printf("Case #%d: ", tt);
		if (found) {
			printf("POSSIBLE\n");
			for (int i = 0; i < b; ++i) {
				for (int j = 0; j < b; ++j) {
					printf(ans[i][j] ? "1" : "0");
				}
				printf("\n");
			}
		} else {
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}