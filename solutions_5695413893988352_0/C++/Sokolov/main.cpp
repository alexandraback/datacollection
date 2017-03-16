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

char a[20], b[20];
int n;

int minDiff = INF;
int ans1 = -1;
int ans2 = -1;

void f(int pos, int val1, int val2) {
	if (pos == n) {
		if (abs(val1 - val2) < minDiff
			|| (abs(val1 - val2) == minDiff && val1 < ans1)
			|| (abs(val1 - val2) == minDiff && val1 == ans1 && val2 < ans2)) {
			minDiff = abs(val1 - val2);
			ans1 = val1;
			ans2 = val2;
		}
		return;
	}
	if (a[pos] == '?' && b[pos] == '?') {
		for (int i = 0; i <= 9; ++i) {
			for (int j = 0; j <= 9; ++j) {
				f(pos + 1, val1 * 10 + i, val2 * 10 + j);
			}
		}
	} else if (a[pos] == '?' && b[pos] != '?') {
		for (int i = 0; i <= 9; ++i) {
			f(pos + 1, val1 * 10 + i, val2 * 10 + (int) (b[pos] - '0'));
		}
	} else if (a[pos] != '?' && b[pos] == '?') {
		for (int j = 0; j <= 9; ++j) {
			f(pos + 1, val1 * 10 + (int) (a[pos] - '0'), val2 * 10 + j);
		}
	} else {
		f(pos + 1, val1 * 10 + (int) (a[pos] - '0'), val2 * 10 + (int) (b[pos] - '0'));
	}
}

int main() {
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("out.txt", "wt", stdout);
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt) {
		scanf("%s %s", a, b);
		n = strlen(a);
		minDiff = INF;
		ans1 = -1;
		ans2 = -1;
		f(0, 0, 0);
		printf("Case #%d: ", tt);
		if (n == 1) {
			printf("%01d %01d\n", ans1, ans2);
		} else if (n == 2) {
			printf("%02d %02d\n", ans1, ans2);
		} else {
			printf("%03d %03d\n", ans1, ans2);
		}
	}
	return 0;
}