//============================================================================
// Name        : 2016_gcj_1b_b.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cctype>
using namespace std;

#define RUN

struct node {
	long long sc, sj, sabs;

	node& add(long long x, long long y) {
		node *ret = new node;
		ret->clear();
		if (x < 0 || x > 9 || y < 0 || y > 9)
			return *ret;
		ret->sc = sc*10+x;
		ret->sj = sj*10+y;
		ret->sabs = max(ret->sc,ret->sj) - min(ret->sc,ret->sj);
		return *ret;
	}
	bool islegal() {
		return sabs >= 0;
	}
	void set0() {
		sc = sj = sabs = 0;
	}
	void clear() {
		sc = sj = sabs = -1;
	}
	bool operator < (const node &b) const {
		if (b.sabs < 0)
			return 0<1;
		if (sabs < 0)
			return 1<0;
		if (sabs != b.sabs)
			return sabs < b.sabs;
		if (sc != b.sc)
			return sc < b.sc;
		return sj < b.sj;
	}
	node& operator = (const node &b) {
		this->sc = b.sc;
		this->sj = b.sj;
		this->sabs = b.sabs;
		return *this;
	}
} dp[2][3], ans;
int p, c;

char s[2][20];

int main() {

#ifdef RUN
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
#endif

	int t;
	int x, y;
	int len;
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		scanf("%s%s", s[0], s[1]);
		p = 1;
		c = 0;
		for (int i = 0; i < 3; i++) {
			dp[p][i].clear();
			dp[c][i].clear();
		}
		dp[c][0].set0();
		for (int i = 0; s[0][i]; i++) {
			swap(p, c);
			x = y = -1;
			if (isdigit(s[0][i]))
				x = s[0][i]-'0';
			if (isdigit(s[1][i]))
				y = s[1][i]-'0';
			if (x == -1 && y == -1) {
				if (dp[p][0].islegal()) {
					dp[c][0] = min(dp[c][0], dp[p][0].add(0,0));
					dp[c][1] = min(dp[c][1], dp[p][0].add(1,0));
					dp[c][2] = min(dp[c][2], dp[p][0].add(0,1));
				}
				if (dp[p][1].islegal()) {
					dp[c][1] = min(dp[c][1], dp[p][1].add(0,9));
				}
				if (dp[p][2].islegal()) {
					dp[c][2] = min(dp[c][2], dp[p][2].add(9,0));
				}
			} else if (y == -1) {
				if (dp[p][0].islegal()) {
					dp[c][0] = min(dp[c][0], dp[p][0].add(x,x));
					dp[c][1] = min(dp[c][1], dp[p][0].add(x,x-1));
					dp[c][2] = min(dp[c][2], dp[p][0].add(x,x+1));
				}
				if (dp[p][1].islegal()) {
					dp[c][1] = min(dp[c][1], dp[p][1].add(x,9));
				}
				if (dp[p][2].islegal()) {
					dp[c][2] = min(dp[c][2], dp[p][2].add(x,0));
				}
			} else if (x == -1) {
				if (dp[p][0].islegal()) {
					dp[c][0] = min(dp[c][0], dp[p][0].add(y,y));
					dp[c][1] = min(dp[c][1], dp[p][0].add(y+1,y));
					dp[c][2] = min(dp[c][2], dp[p][0].add(y-1,y));
				}
				if (dp[p][1].islegal()) {
					dp[c][1] = min(dp[c][1], dp[p][1].add(0,y));
				}
				if (dp[p][2].islegal()) {
					dp[c][2] = min(dp[c][2], dp[p][2].add(9,y));
				}
			} else {
				if (x < y) {
					if (dp[p][0].islegal()) {
						dp[c][2] = min(dp[c][2], dp[p][0].add(x,y));
					}
					if (dp[p][1].islegal()) {
						dp[c][1] = min(dp[c][1], dp[p][1].add(x,y));
					}
					if (dp[p][2].islegal()) {
						dp[c][2] = min(dp[c][2], dp[p][2].add(x,y));
					}
				} else if (x > y) {
					if (dp[p][0].islegal()) {
						dp[c][1] = min(dp[c][1], dp[p][0].add(x,y));
					}
					if (dp[p][1].islegal()) {
						dp[c][1] = min(dp[c][1], dp[p][1].add(x,y));
					}
					if (dp[p][2].islegal()) {
						dp[c][2] = min(dp[c][2], dp[p][2].add(x,y));
					}
				} else {
					if (dp[p][0].islegal()) {
						dp[c][0] = min(dp[c][0], dp[p][0].add(x,y));
					}
					if (dp[p][1].islegal()) {
						dp[c][1] = min(dp[c][1], dp[p][1].add(x,y));
					}
					if (dp[p][2].islegal()) {
						dp[c][2] = min(dp[c][2], dp[p][2].add(x,y));
					}
				}
			}
			for (int j = 0; j < 3; j++) {
				dp[p][j].clear();
			}
		}
		ans.clear();
		ans = min(min(dp[c][0], dp[c][1]), dp[c][2]);
		len = strlen(s[0]);
		printf("Case #%d: %0*I64d %0*I64d\n", cas, len, ans.sc, len, ans.sj);
	}
	return 0;
}
