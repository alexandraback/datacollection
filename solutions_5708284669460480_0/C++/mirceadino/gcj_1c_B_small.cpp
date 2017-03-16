#include<bits/stdc++.h>

using namespace std;

#define dbg(x) (cout<<#x<<" = "<<(x)<<'\n')

typedef long long int lld;
const int INF = (1LL << 30) - 1;
const lld LINF = (1LL << 62) - 1;

int numberOfTests;
int total;
int K, L, S;
char letters[105];
char word[105];
double sol;
int allcases;
char str[105];

void clean() {
	total = 0;
	sol = 0.0;
	allcases = 0;
	memset(str, 0, sizeof(str));
	memset(word, 0, sizeof(word));
}

void back(int top) {
	if (top > S) {
		int nr = 0;

		for (int i = 1; i <= S; i++) {
			swap(str[i + L], str[S + 1]);

			if (strcmp(str + i, word + 1) == 0)
				nr++;

			swap(str[i + L], str[S + 1]);
		}

		total = max(total, nr);
		sol += nr;
		allcases++;

		return;
	}

	for (int i = 1; i <= K; i++) {
		str[top] = letters[i];

		back(top + 1);
	}
}

int main() {
	cin.sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	scanf("%d", &numberOfTests);

	for (int testcase = 1; testcase <= numberOfTests; testcase++) {
		scanf("%d%d%d", &K, &L, &S);
		scanf("%s", letters + 1);
		scanf("%s", word + 1);

		back(1);

		sol /= allcases;

		printf("Case #%d: %.10f\n", testcase, total - sol);

		clean();
	}

	return 0;
}