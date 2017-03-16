#include<bits/stdc++.h>

using namespace std;

#define dbg(x) (cout<<#x<<" = "<<(x)<<'\n')

typedef long long int lld;
const int INF = (1LL << 30) - 1;
const lld LINF = (1LL << 62) - 1;

int numberOfTests;
int R, C, W;

int solve1(int c, int w) {
	return c / w + (c % w != 0) + w - 1;
}

int solveall() {
	return -1;
}

int main() {
	cin.sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	scanf("%d", &numberOfTests);

	for (int testcase = 1; testcase <= numberOfTests; testcase++) {
		scanf("%d%d%d", &R, &C, &W);

		int sol;

		if (R == 1)
			sol = solve1(C, W);
		else
			sol = solveall();

		printf("Case #%d: %d\n", testcase, sol);
	}

	return 0;
}