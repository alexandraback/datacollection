#include<bits/stdc++.h>

using namespace std;

#define dbg(x) (cout<<#x<<" = "<<(x)<<'\n')

typedef long long int lld;
const int INF = (1LL << 30) - 1;
const lld LINF = (1LL << 62) - 1;

char A[20];
char B[20];
int N;
pair<int, pair<int, int>> sol;

bool match(char c, int d) {
	if (c == '?') return true;
	return c == d + '0';
}

bool match(char* A, int val) {
	int p = 1;
	for (int i = N - 1; i >= 0; i--, p *= 10)
		if (!match(A[i], (val / p) % (10)))
			return false;
	return true;
}

void scrie(int val) {
	int cnt = 0;
	int aux = val;
	while (aux) {
		cnt++;
		aux /= 10;
	}
	if (val == 0) cnt++;
	assert(cnt <= 3);
	for (int i = 0; i < N - cnt; i++)
		printf("0");
	printf("%d", val);
}

int nrdigits(int val) {
	if (val == 0) return 1;
	int cnt = 0;
	while (val) {
		cnt++;
		val /= 10;
	}
	return cnt;
}

void solve() {
	scanf("%s", A);
	scanf("%s", B);
	N = strlen(A);

	sol = {INF, {INF, INF}};

	for (int i = 0; i <= 999 && nrdigits(i) <= N; i++)
		for (int j = 0; j <= 999 && nrdigits(j) <= N; j++) {
			if (match(A, i) && match(B, j))
				sol = min(sol, {abs(i - j), {i, j}});
			if (0 && match(A, i) && match(B, j))
				printf("%d %d | %d\n", i, j, abs(i - j));
		}

	scrie(sol.second.first);
	printf(" ");
	scrie(sol.second.second);
}

int main() {
	cin.sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int nrtests;

	scanf("%d", &nrtests);

	for (int testnr = 1; testnr <= nrtests; testnr++) {
		printf("Case #%d: ", testnr);
		solve();
		printf("\n");
	}

	return 0;
}