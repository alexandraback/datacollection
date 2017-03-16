#include <algorithm>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define SIZE(v) ((int)(v).size())

#define BEGIN(v) ((v).begin())
#define END(v) ((v).end())
#define ALL(v) BEGIN(v),END(v)
#define SORT(v) sort(ALL(v))
#define UNIQUE(v) SORT(v);(v).erase(unique(ALL(v)),END(v))

#define FOR(i,l,r) for(int i=(l);i<(r);i++)
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)

const int MAXN = 128;
const int INF = 1012345678;

int A, B, n, mote[MAXN], dp[2][MAXN];

int calc() {
	int t = 0;
	FOR(i, 0, MAXN) dp[t][i] = -INF;
	dp[t][0] = min(A, B);
	FOR(i, 0, n) {
		t ^= 1;
		FOR(j, 0, MAXN) dp[t][j] = -INF;
		FOR(j, 0, MAXN - 1) if (dp[t ^ 1][j] != -INF) {
			dp[t ^ 1][j + 1] = max(dp[t ^ 1][j + 1], min((dp[t ^ 1][j] << 1) - 1, B));
		}
		FOR(j, 0, MAXN - 1) if (dp[t ^ 1][j] != -INF) {
			if (dp[t ^ 1][j] > mote[i]) dp[t][j] = max(dp[t][j], dp[t ^ 1][j] + mote[i]);
			dp[t][j + 1] = max(dp[t][j + 1], dp[t ^ 1][j]);
		}
	}
	FOR(j, 0, MAXN) if (dp[t][j] != -INF) return j;
	return -1;
}

int main() {
	int taskNumber;
	scanf("%d", &taskNumber);
	for (int taskIdx = 1; taskIdx <= taskNumber; taskIdx++) {
		scanf("%d%d", &A, &n);
		FOR(i, 0, n) scanf("%d", &mote[i]);
		sort(mote, mote + n);
		B = mote[n - 1] + 1;
		printf("Case #%d: %d\n", taskIdx, calc());
	}
	return 0;
}
