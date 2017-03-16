//============================================================================
// Name        : cj_20130427_B.cpp
// Author      : huangxs139
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n;
long long e, r, v[10010];
long long op[10010];
long long ans;

int getMaxInd(int l, int r) {
	int tmp = v[l];
	int ret = l;
	for (int i = l+1; i <= r; i++)
		if (v[i] > tmp) {
			ret = i;
			tmp = v[ret];
		}
	return ret;
}

void solve(int st, int ed, int a, int b) {
	if (st > ed)
		return;
	if (st == ed) {
			op[st] = a - b + r;
	} else {
		int id = getMaxInd(st, ed);
		int lb, rb;
		lb = min(a+(id-st)*r, e);
		rb = max(b-(ed-id)*r, r);
		solve(st, id-1, a, lb);
		solve(id, id, lb, rb);
		solve(id+1, ed, rb, b);
	}
}

int main() {
	int T;
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("data1.out", "w", stdout);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		scanf("%I64d %I64d %d", &e, &r, &n);
		for (int i = 1; i <= n; i++) {
			scanf("%I64d", &v[i]);
		}
		memset(op, 0, sizeof(op));
		ans = 0;
		if (r >= e) {
			for (int i = 1; i <= n; i++)
				ans += v[i] * e;
			printf("Case #%d: %I64d\n", cas, ans);
		} else {
			solve(1, n, e, r);
			for (int i = 1; i <= n; i++)
				ans += v[i] * op[i];
			printf("Case #%d: %I64d\n", cas, ans);
		}
		//for (int i = 1; i <= n; i++)
		//	printf("%I64d ", op[i]);
		//cout << endl;
	}
	return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
*/

/*
100
5 1 3
1 2 3
5 1 3
1 3 2
5 1 3
2 1 3
5 1 3
2 3 1
5 1 3
3 1 2
5 1 3
3 2 1
2 1 3
3 1 3
3 1 5
1 2 3 2 1
3 1 5
3 2 1 2 3
5 1 1
2
5 5 10
10 10 10 10 10 10 10 10 10 10
5 1 10
10 1 10 1 10 1 10 1 10 1
5 1 10
1 10 1 10 1 10 1 10 1 10
5 1 10
1 2 3 4 5 6 7 8 9 10
5 1 10
10 9 8 7 6 5 4 3 2 1
5 1 10
1 10 2 9 3 8 4 7 5 6
5 1 10
10 1 9 2 8 3 7 4 6 5
2 1 1
3
5 1 1
9
3 1 1
7
4 4 1
5
1 1 1
9
2 1 1
5
4 4 1
3
3 1 1
6
3 3 1
10
2 2 1
2
2 1 1
8
5 1 1
8
1 1 1
4
2 2 1
4
1 1 1
7
4 3 1
2
3 2 1
4
2 2 1
10
2 2 1
6
3 1 1
9
1 1 1
7
1 1 1
10
4 1 1
3
4 1 1
6
1 1 1
8
3 3 1
9
5 2 1
9
1 1 1
3
2 1 1
1
2 1 1
6
5 5 1
3
1 1 1
7
2 1 1
6
3 2 1
2
4 4 1
9
5 1 1
5
3 2 1
7
1 1 1
1
4 3 1
6
1 1 1
7
2 2 1
10
3 1 1
3
5 2 1
6
2 2 1
7
2 1 1
2
1 1 1
1
4 4 1
2
1 1 1
8
3 2 1
6
5 5 1
3
1 1 1
6
3 2 1
4
1 1 1
10
3 2 1
10
1 1 1
10
3 2 1
9
3 3 1
1
5 3 1
8
3 3 1
1
1 1 1
6
1 1 1
7
1 1 1
9
5 5 1
10
5 3 1
4
2 1 1
2
3 1 1
9
3 1 1
6
5 1 1
6
1 1 1
2
3 3 1
8
2 1 1
10
3 3 1
9
2 5 1
3
5 5 1
10
5 3 2
1 10
5 1 2
4 10
5 1 2
10 3
5 1 3
10 10 3
5 1 4
2 5 8 10
5 1 5
10 8 6 6 7
5 4 6
1 2 6 5 10 9
5 1 7
6 3 10 7 5 1 10
5 2 10
6 5 10 6 8 7 7 5 6 10
*/
