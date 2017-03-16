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

const int MAXK = 13;
const int MAXN = 13;


int r, n, m, k;

long long need[MAXK];
bool have[MAXK];
int place[MAXN];
bool acc[MAXN];

bool check() {
	int maxmask = 1<<n;
	int bad = k;

	memset(have, 0, sizeof(have));
	for (int mask = 0; mask < maxmask; mask++) {
		long long cur = 1;
		for (int i = 0; i < n; i++)
			if ((mask >> i) & 1)
				cur *= place[i];
		for (int i = 0; i < k; i++)
			if (need[i] == cur && have[i] == false)
			{
				have[i] = true;
				bad--;
			}

		if (!bad)
			break;
	}

	if (bad)
		return false;
	return true;
}

inline bool isDivider(int x) {
	for (int i = 0; i < k; i++)
		if (need[i] % x == 0)
			return true;
	return false;
}

bool rec(int pos, int minplace) {
	if (pos == n) {
		return check();
	}

	for (place[pos] = minplace; place[pos] <= m; place[pos]++) {
		if (!acc[place[pos]])
			continue;
		if (rec(pos + 1, place[pos]))
			return true;
	}
	return false;
}

void solve() {
	cin >> r >> n >> m >> k;
	printf("\n");
	for (int i = 0; i < r; i++) {
		if (i > 1130) {
			for (int j = 0; j < n; j++)
				printf("1");
			printf("\n");
			continue;
		}

		for (int j = 0; j < k; j++)
			cin >> need[j];

		memset(acc, 0, sizeof(acc));
		for (int j = 2; j <= m; j++)
			if (isDivider(j))
				acc[j] = true;

		int curpos = 0;
		for (int j = 0; j < k; j++)
			if (need[j] % 5 == 0)
			{
				place[curpos++] = 5;
				break;
			}
		for (int j = 0; j < k; j++)
			if (need[j] % 7 == 0)
			{
				place[curpos++] = 7;
				break;
			}

		for (int j = 0; j < k; j++)
			if (need[j] % 2 == 0 && need[j] % 4 != 0 && need[j] % 6 != 0)
			{
				place[curpos++] = 2;
				break;
			}

		for (int j = 0; j < k; j++)
			if (need[j] % 3 == 0 && need[j] % 6 != 0)
			{
				place[curpos++] = 3;
				break;
			}

		rec(curpos, 2);

		for (int j = 0; j < n; j++)
			printf("%d", place[j]);
		printf("\n");
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("C_input3.txt","r", stdin);
	freopen("C_output3.txt","w", stdout);
#endif
	int testnum;
	scanf("%d\n", &testnum);
	for (int i = 0; i < testnum; i++)
	{
		printf("Case #%d: ", i + 1 + 1000);
		solve();
	}
}
