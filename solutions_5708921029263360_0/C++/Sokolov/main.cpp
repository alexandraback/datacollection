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

struct T {
	int x, y, z;

	T() {}

	T(int _x, int _y, int _z) {
		x = _x;
		y = _y;
		z = _z;
	}
};

int K, n;
T a[39];
int used1[9][9];
int used2[9][9];
int used3[9][9];

int ansSize;
T ans[39];

bool mask[39];

void f(int x, int count) {
	if (x == n) {
		if (count > ansSize) {
			ansSize = 0;
			for (int i = 0; i < n; ++i) {
				if (mask[i]) {
					ans[ansSize++] = a[i];
				}
			}
		}
		return;
	}
	mask[x] = 0;
	f(x + 1, count);
	if (used1[a[x].x][a[x].y] + 1 <= K
		&& used2[a[x].x][a[x].z] + 1 <= K
		&& used3[a[x].y][a[x].z] + 1 <= K) {
		++used1[a[x].x][a[x].y];
		++used2[a[x].x][a[x].z];
		++used3[a[x].y][a[x].z];
		mask[x] = 1;
		f(x + 1, count + 1);
		--used1[a[x].x][a[x].y];
		--used2[a[x].x][a[x].z];
		--used3[a[x].y][a[x].z];
	}
}

int main() {
	freopen("C-small-attempt0.in", "rt", stdin);
	freopen("out.txt", "wt", stdout);
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt) {
		int J, P, S;
		scanf("%d %d %d %d", &J, &P, &S, &K);
		n = 0;
		for (int i = 1; i <= J; ++i) {
			for (int j = 1; j <= P; ++j) {
				for (int k = 1; k <= S; ++k) {
					a[n++] = T(i, j, k);
				}
			}
		}
		for (int i = 1; i <= 3; ++i) {
			for (int j = 1; j <= 3; ++j) {
				used1[i][j] = 0;
				used2[i][j] = 0;
				used3[i][j] = 0;
			}
		}
		ansSize = 0;
		f(0, 0);
		printf("Case #%d: %d\n", tt, ansSize);
		for (int i = 0; i < ansSize; ++i) {
			printf("%d %d %d\n", ans[i].x, ans[i].y, ans[i].z);
		}
	}
	return 0;
}