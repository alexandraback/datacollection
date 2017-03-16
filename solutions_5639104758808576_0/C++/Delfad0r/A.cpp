#include <bits/stdc++.h>

using namespace std;

char S0[1010];
int S[1010];
void solve(int t) {
	int N;
	scanf("%d %s", &N, S0);
	++N;
	for(int n = 0; n < N; ++n)
		S[n] = S0[n] - '0';
	int ans = 0;
	for(int n = 1; n < N; ++n) {
		ans += max(0, n - S[n - 1]);
		S[n] += max(S[n - 1], n);
	}
	printf("Case #%d: %d\n", t, ans);
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
		solve(t);
}
