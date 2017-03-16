#include <bits/stdc++.h>

using namespace std;

int P[1010];
void solve(int t) {
	int N;
	scanf("%d", &N);
	for(int n = 0; n < N; ++n)
		scanf("%d", P + n);
	int ans = 1 << 20;
	for(int m = 1; m <= 1000; ++m) {
		int C = 0;
		for(int n = 0; n < N; ++n)
			C += P[n] / m - int((P[n] % m) == 0);
		if(C + m < ans) ans = C + m;
	}
	printf("Case #%d: %d\n", t, ans);
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
		solve(t);
}
