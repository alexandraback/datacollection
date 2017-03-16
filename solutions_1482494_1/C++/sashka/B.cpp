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

const int nmax = 1010;

int n;

int a[nmax], b[nmax];
bool used[nmax][2];

struct S {

	int level;
	int star;
	int mv;

	S() {
		level = 0;
		star = 0;
		mv = -1;
	}


	S(int _level, int _star) {
		level = _level;
		star = _star;
		if (star == 1) {
			mv = a[level];
		} else {
			mv = b[level];
		}
	}

	int gain() {

		if (used[level][0]) {
			return 1;
		}

		return star;

	}

	bool operator<(const S& other) const {

		if (mv != other.mv) {
			return mv > other.mv;
		}

		if (star == 1) {
			return b[level] < b[other.level];
		}
		return star < other.star;
	}
};

void solveTest() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
	}

	priority_queue< S > pq1;
	priority_queue< S > pq2;

	for(int j = 0; j < n; ++j) {
		pq1.push(S(j, 1));
		pq2.push(S(j, 2));
	}

	int ans = 0;

	bool good = true;

	int s = 0;

	memset(used, 0, sizeof(used));

	while(!pq1.empty() || !pq2.empty()) {

		S t;

		if (!pq2.empty() && pq2.top().mv <= s) {
			t = pq2.top();
			pq2.pop();
		} else {
			if (pq1.empty()) {
				good = false;
				break;
			}
			t = pq1.top();
			pq1.pop();
		}

		if (used[t.level][t.star - 1]) {
			continue;
		}

		if (t.mv > s) {
			good = false;
			break;
		}

		s += t.gain();
		++ans;

		if (t.star == 2) {
			used[t.level][0] = used[t.level][1] = true;
		} else {
			used[t.level][0] = true;
		}

	}

	while(!pq1.empty()) {
		pq1.pop();
	}

	while(!pq2.empty()) {
		pq2.pop();
	}

	if (good) {
		printf("%d", ans);
	} else {
		printf("Too Bad");
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("BL.in", "rt", stdin);
	freopen("BL.out", "wt", stdout);
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