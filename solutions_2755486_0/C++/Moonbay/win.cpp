/*
 * C/win.cpp
 * Created on: 2013-5-12
 * Author    : ben
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
using namespace std;

const int MAXN = 15;
const int MAXM = 10005;
const int delta = 5000;
const int INF = 0x7fffffff;

typedef struct Tribe {
	int day, tot, w, e;
	int strength, delta_day;
	int move, cnt;
	int delta_strength;
}Tribe;

typedef struct Strengthen {
	int w, e, s;
	Strengthen(int ww, int ee, int ss) :
		w(ww), e(ee), s(ss) {
	}
	Strengthen() {
		w = e = s =0;
	}
}Strengthen;

Tribe tribe[MAXN];
Strengthen stk[MAXN];

int n, ans, top;
int wall[MAXM];

void init() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &tribe[i].day, &tribe[i].tot, &tribe[i].w,
				&tribe[i].e);
		tribe[i].cnt = 0;
		scanf("%d", &tribe[i].strength);
		scanf("%d%d%d", &tribe[i].delta_day, &tribe[i].move,
				&tribe[i].delta_strength);
	}
	memset(wall, 0, sizeof(wall));
}

bool check() {
	for (int i = 0; i < n; i++) {
		if (tribe[i].cnt < tribe[i].tot) {
			return true;
		}
	}
	return false;
}

int min_day() {
	int ret = INF;
	for (int i = 0; i < n; i++) {
		if (tribe[i].cnt < tribe[i].tot) {
			ret = min(ret, tribe[i].day);
		}
	}
	return ret;
}

void do_next(Tribe &a) {
	a.strength += a.delta_strength;
	a.day += a.delta_day;
	a.w += a.move;
	a.e += a.move;
	a.cnt++;
}

void make(Strengthen a) {
	for (int i = a.w; i < a.e; i++) {
		wall[i + delta] = max(a.s, wall[i + delta]);
	}
}

bool attack(Strengthen a) {
	bool ret = false;
	for (int i = a.w; i < a.e; i++) {
		if (wall[i + delta] < a.s) {
			ret = true;
		}
	}
	return ret;
}

void work() {
	ans = 0;
	top = 0;
	while (check()) {
		int day = min_day();
		for (int i = 0; i < n; i++) {
			if (tribe[i].cnt < tribe[i].tot && day == tribe[i].day) {
				stk[top++] = Strengthen(tribe[i].w, tribe[i].e,
						tribe[i].strength);
				if (attack(stk[top - 1])) {
					ans++;
				}
				do_next(tribe[i]);
			}
		}
		while (top > 0) {
			make(stk[--top]);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("C-small-attempt0.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		init();
		work();
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
