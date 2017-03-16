#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

#define FOR(i,n) for (int i = 0; i < n; i++)
#define abs(x) ((x)<0?(-(x)):(x))
#define REP(i,v) for (unsigned i = 0; i < v.size(); i++)
#define RL(i,v) for (unsigned i = 0; i < v.length(); i++)
typedef long long ll;

const int OFFSET = 2200000;

unsigned char dp[20][4][OFFSET * 2];

enum {
	INITA,
	INITB,
	ADDA,
	ADDB,
	NOP
};

int n, a[25], found;
int Loga[25], la, Logb[25], lb;

void f(int pos, int mask, int sum, int lastact)
{
	if (found) {
// 		printf("Found!\n");
		return;
	}
	if (mask == 3 && sum == 0) {
		found = true;
		printf("\n");
		FOR(i, la) {
			if (i) printf(" ");
			printf("%d", Loga[i]);
		}
		printf("\n");
		FOR(i, lb) {
			if (i) printf(" ");
			printf("%d", Logb[i]);
		}
		printf("\n");
// 		printf("%d %d\n", pos, n);
		return;
	}
	if (pos == n) {
// 		printf("%d %d\n", pos, n);
		return;
	}
	if (dp[pos][mask][sum + OFFSET]) return;
	dp[pos][mask][sum + OFFSET] = 1;
	Loga[la++] = a[pos];
	f(pos + 1, mask | 1, sum + a[pos], (mask & 1) ? ADDA : INITA);
	la--;
	Logb[lb++] = a[pos];
	f(pos + 1, mask | 2, sum - a[pos], (mask & 2) ? ADDB : INITB);
	lb--;
	f(pos + 1, mask, sum, NOP);
}

void solve(void)
{
	found = false;
	la = lb = 0;
	memset(dp, 0, sizeof(dp));
	scanf("%d", &n);
	FOR(i, n) scanf("%d", &a[i]);
	f(0, 0, 0, NOP);
	if (!found) printf("\nImpossible\n");
}

int main(void)
{
// 	freopen("/home/vesko/gcj/c.in", "rt", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		printf("Case #%d:", tc);
		solve();
	}
	return 0;
}
