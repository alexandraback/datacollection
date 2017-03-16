#include<bits/stdc++.h>

using namespace std;

#define dbg(x) (cout<<#x<<" = "<<(x)<<'\n')

typedef long long int lld;
const int INF = (1LL << 30) - 1;
const lld LINF = (1LL << 62) - 1;

int numberOfTests;
int sol;
int st[104];
int D, V, C;
int mark[104];
int value[104];
int used[104];

void back(int top) {
	if (top > D) {
		int val = 0;

		for (int i = 1; i <= D; i++)
			val += st[i] * value[i];

		mark[val] = 1;

		return;
	}

	for (int i = 0; i <= 1; i++) {
		st[top] = i;
		back(top + 1);
	}
}

int solve1() {
	back(1);

	int nr = 0;

	for (int i = 1; i <= V; i++)
		if (!mark[i]) {
			for (int j = i - 1; j >= 0; j--)
				if ((!used[i - j]) && mark[j]) {
					for (int k = V; k >= 0; k--)
						if (mark[k])
							mark[k + i - j] = 1;

					mark[i] = 1;
					used[i - j] = 1;
					nr++;
					break;
				}
		}

	return nr;
}

int solveall() {
	return -1;
}

void clean() {
	memset(mark, 0, sizeof(mark));
	memset(used, 0, sizeof(used));
	mark[0] = 1;
}

int main() {
	cin.sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	scanf("%d", &numberOfTests);

	for (int testcase = 1; testcase <= numberOfTests; testcase++) {
		scanf("%d%d%d", &C, &D, &V);

		for (int i = 1; i <= D; i++) {
			scanf("%d ", &value[i]);
			used[value[i]] = 1;
		}

		if (C == 1 && D <= 5 && V <= 30)
			sol = solve1();
		else
			sol = solveall();

		printf("Case #%d: %d\n", testcase, sol);

		clean();
	}

	return 0;
}