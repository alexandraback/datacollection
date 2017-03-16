#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <valarray>
#include <memory.h>
#include <climits>

using namespace std;

int e, r, n;
int v[11];
int dp[11][5];

int solve(int idx, int ce) {
	if(idx == n)
		return 0;
	int &res = dp[idx][ce];
	if(res != -1)
		return res;
	res = 0;
	for(int a = 0; a <= ce; ++a) {
		res = max(res, solve(idx + 1, min(e, ce - a + r)) + (a * v[idx]));
	}
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);
#endif
	
	int T;
	scanf("%d", &T);

	for(int tst = 1; tst <= T; ++tst) {
		scanf("%d %d %d", &e, &r, &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		memset(dp, -1, sizeof dp);
		printf("Case #%d: %d\n", tst, solve(0, e));
	}

	return 0;
}
