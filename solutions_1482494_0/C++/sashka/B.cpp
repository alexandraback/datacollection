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

const int nmax = 10;

int n;

int a[nmax], b[nmax];

int bcans(int x) {
	int ans = 0;
	while(x) {
		if (x & 1) {
			++ans;
		}
		x >>= 1;
	}
	return ans;
}

struct S {

	int level;
	int star;
	int mv;
	bool was;

	S(int _level, int _star) {
		level = _level;
		star = _star;
		if (star == 1) {
			mv = a[level];
		} else {
			mv = b[level];
		}
		was = false;
	}

	bool hasNext() {
		return star == 1;
	}

	S getNext() {
		S t(level, star + 1);
		t.was = true;
		return t;
	}

	int gain() {

		if (was) {
			return 1;
		}

		return star;

	}

	bool operator<(const S& other) const {
		return mv > other.mv;
	}
};

void solveTest() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
	}

	int lim = (1 << n) - 1;

	int ans = -1;

	for(int i = lim; i >= 0; --i) {

		priority_queue< S > pq;

		for(int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				pq.push(S(j, 1));
			} else {
				pq.push(S(j, 2));
			}
		}

		bool good = true;

		int s = 0;

		while(!pq.empty()) {

			S t = pq.top();
			pq.pop();

			if (t.mv > s) {
				good = false;
				break;
			}

			s += t.gain();

			if (t.hasNext()) {
				pq.push(t.getNext());
			}

		}

		while(!pq.empty()) {
			pq.pop();
		}


		if (good) {
			if (ans == -1) {
				ans = bcans(i) + n;
			} else {
				ans = min(ans, bcans(i) + n);
			}
		}

	}

	if (ans == -1) {
		printf("Too Bad");
	} else {
		printf("%d", ans);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("B.in", "rt", stdin);
	freopen("B.out", "wt", stdout);
#endif
	int t;
	scanf("%d", &t);
	for(int tt = 0; tt < t; ++tt) {
		printf("Case #%d: ", tt + 1);
		solveTest();
		puts("");
		cerr << "Case " << tt + 1 << " done\n";
	}
	return 0;
}