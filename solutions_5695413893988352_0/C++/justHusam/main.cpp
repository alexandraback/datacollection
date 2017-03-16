#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <bitset>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
using namespace std;

typedef long long ll;

struct state {
	int diff, a, b;
	state(int diff, int a, int b) :diff(diff), a(a), b(b) {}
	bool operator<(const state&e)const {
		if (e.diff != diff)
			return diff < e.diff;
		if (e.a != a)
			return a < e.a;
		return b < e.b;
	}
};

char a[20], b[20];
int n;
vector<int> v[2];
vector<state> sol;

void calc(int at, int msk, char *a, int p) {
	if (at == n) {
		v[p].push_back(msk);
		return;
	}
	if (a[at] != '?')
		calc(at + 1, msk * 10 + (a[at] - '0'), a, p);
	else {
		for (int i = 0; i < 10; ++i) {
			calc(at + 1, msk * 10 + i, a, p);
		}
	}
}

int main(int argc, char **argv) {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t, cas = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%s%s", a, b);
		n = strlen(a);
		v[0].clear();
		v[1].clear();
		calc(0, 0, a, 0);
		calc(0, 0, b, 1);
		sol.clear();
		for (int i = 0; i < v[0].size(); ++i)
			for (int j = 0; j < v[1].size(); ++j)
				sol.push_back(state(abs(v[0][i] - v[1][j]), v[0][i], v[1][j]));
		sort(sol.begin(), sol.end());
		int x = sol[0].a, y = sol[0].b;
		printf("Case #%d: ", cas++);
		if (n == 2 && x < 10)
			printf("0");
		else if (n == 3 && x < 10)
			printf("00");
		else if (n == 3 && x >= 10 && x < 100)
			printf("0");
		printf("%d ", x);
		if (n == 2 && y < 10)
			printf("0");
		else if (n == 3 && y < 10)
			printf("00");
		else if (n == 3 && y >= 10 && y < 100)
			printf("0");
		printf("%d\n", y);
	}
	return 0;
}