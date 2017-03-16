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

const int nmax = 1 << 16;

int v[nmax];
int n, r, e;

#define INF (2000000000)

void readTest() {
	scanf("%d%d%d", &e, &r, &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
	}
}

const int emax = 10;

int gain[emax][2];

void solveTest() {

	int prev = 0;
	int next = 1;

	memset(gain, 0, sizeof(gain));

	for(int i = 0; i < n; ++i) {

		for(int j = 0; j <= e; ++j) {
			for(int k = 0; k <= j; ++k) {
				int q = min(k + r, e);
				gain[q][next] = max(gain[q][next], (j - k) * v[i] + gain[j][prev]);
			}
		}

		swap(prev, next);
	}
	
	int mx = 0;
	for(int i = 0; i <= e; ++i) {
		mx = max(mx, gain[i][prev]);
	}

	printf("%d\n", mx);

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