#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>

#define MST(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define REPP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 1005;
int a[N], n;

int go(int x) {
	priority_queue<int> q;
	REPP(i, 1, n) q.push(a[i]);
	int cnt = 0;
	while (q.top() > x) {
		int y = q.top(); q.pop();
		q.push(x), q.push(y - x);
		cnt++;
	}
	return x + cnt;
}

int main() {
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int t, ca = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REPP(i, 1, n) scanf("%d", a + i);
		int ans = int(1e9);
		REPP(i, 1, 1000) {
			ans = min(ans, go(i));
		}
		printf("Case #%d: %d\n", ca++, ans);
	}

	return 0;
}

