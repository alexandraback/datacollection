#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <numeric>

using namespace std;

#define INF (2000000000)

const int nmax = 1 << 7;

int a[nmax][nmax];
int r[nmax], c[nmax];
int n, m;

void readTest() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
}

void solveTest() {

	for(int i = 0; i < n; ++i) {
		r[i] = 0;
		for(int j = 0; j < m; ++j) {
			r[i] = max(r[i], a[i][j]);
		}
	}

	for(int j = 0; j < m; ++j) {
		c[j] = 0;
		for(int i = 0; i < n; ++i) {
			c[j] = max(c[j], a[i][j]);
		}
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if (a[i][j] < r[i] && a[i][j] < c[j]) {
				puts("NO");
				return;
			}
		}
	}

	puts("YES");
}

int main()
{
	freopen("B.in", "rt", stdin);

	bool submit = true;

	if (submit) {
		freopen("B.out", "wt", stdout);
	}

	int t;
	scanf("%d", &t);
	for(int tt = 0; tt < t; ++tt) {
		readTest();
		printf("Case #%d: ", tt + 1);
		solveTest();
		if (submit) {
			cerr << "Case " << tt + 1 << " done\n";
		}
	}
	return 0;
}