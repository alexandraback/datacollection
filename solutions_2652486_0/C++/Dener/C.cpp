#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

const int MAXK = 10;
const int MAXN = 10;


int r, n, m, k;

int need[MAXK];
bool have[MAXK];
int place[MAXN];

bool check() {
	int maxmask = 1<<n;

	memset(have, 0, sizeof(have));
	for (int mask = 0; mask < maxmask; mask++) {
		int cur = 1;
		for (int i = 0; i < n; i++)
			if ((mask >> i) & 1)
				cur *= place[i];
		for (int i = 0; i < k; i++)
			if (need[i] == cur)
				have[i] = true;
	}

	for (int i = 0; i < k; i++)
		if (!have[i])
			return false;
	return true;
}

bool rec(int pos) {
	if (pos == n) {
		return check();
	}

	for (place[pos] = 2; place[pos] <= m; place[pos]++) {
		if (rec(pos + 1))
			return true;
	}
	return false;
}

void solve() {
	cin >> r >> n >> m >> k;
	printf("\n");
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < k; j++)
			scanf("%d", &need[j]);

		rec(0);

		for (int j = 0; j < n; j++)
			printf("%d", place[j]);
		printf("\n");
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("C_input.txt","r", stdin);
	freopen("C_output.txt","w", stdout);
#endif
	int testnum;
	scanf("%d\n", &testnum);
	for (int i = 0; i < testnum; i++)
	{
		printf("Case #%d: ", i + 1);
		solve();
	}
}
