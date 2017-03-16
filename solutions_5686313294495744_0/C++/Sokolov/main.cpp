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

char a[1009][29], b[1009][29];

int main() {
	freopen("C-small-attempt0.in", "rt", stdin);
	freopen("out.txt", "wt", stdout);
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%s %s", a[i], b[i]);
		}
		int res = 0;
		for (int mask = 0; mask < (1 << n); ++mask) {
			set<string> originalA, originalB;
			for (int i = 0; i < n; ++i) {
				if (mask & (1 << i)) {
					originalA.insert(a[i]);
					originalB.insert(b[i]);
				}
			}
			bool isOK = true;
			int cnt = 0;
			for (int i = 0; i < n; ++i) {
				if ((mask & (1 << i)) == 0) {
					++cnt;
					if (originalA.find(a[i]) == originalA.end() || originalB.find(b[i]) == originalB.end()) {
						isOK = false;
						break;
					}
				}
			}
			if (isOK) {
				res = max(cnt, res);
			}
		}
		printf("Case #%d: %d\n", tt, res);
	}
	return 0;
}