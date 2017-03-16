#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <assert.h>
#include <cmath>
#include <set>
using namespace std;

#define FOR(i,n) for (int i = 0; i < n; i++)
#define abs(x) ((x)<0?(-(x)):(x))
#define REP(i,v) for (unsigned i = 0; i < v.size(); i++)
#define RL(i,v) for (unsigned i = 0; i < v.length(); i++)
typedef long long ll;

void solve(void)
{
	int n, s, p;
	int a[128];
	scanf("%d%d%d", &n, &s, &p);
	FOR(i, n) scanf("%d", &a[i]);
	//
	int res = 0;
	FOR(i, n) {
		int x = a[i];
		int y = x/3;
		bool canWithout = false, canWith = false;
		switch (x%3) {
			case 0:
				canWithout = (y >= p);
				canWith    = (y + 1 >= p && (y - 1) >= 0 && (y + 1) <= 10);
				break;
			case 1:
				canWithout = (y + 1 >= p);
				canWith    = (y + 1 >= p && (y - 1) >= 0 && (y + 1) <= 10);
				break;
			case 2:
				canWithout = (y + 1 >= p);
				canWith    = (y + 2 >= p && (y + 2) <= 10);
				break;
		}
		if (canWithout) res++;
		else if (canWith && s > 0) {
			s--;
			res++;
		}
	}
	printf("%d\n", res);
}

int main(void)
{
	//freopen("/home/vesko/gcj/b.in", "rt", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}
