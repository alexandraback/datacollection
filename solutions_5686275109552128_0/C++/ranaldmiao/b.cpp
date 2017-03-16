#include <bits/stdc++.h>
using namespace std;
int N, T, a[1005];
priority_queue<int> pq;
int main () {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) scanf("%d", &a[i]);
		int ans = 1000;
		sort(a, a+N);
		for (int k = 1; k <= 1000; ++k) {
			int cnt = 0;
			for (int i = 0; i < N; ++i)
				cnt += (a[i]-1)/k;
			ans = min(ans, cnt+k);
		}
		printf("Case #%d: %d\n", t, ans);
		
	}
}
