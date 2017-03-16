#include <bits/stdc++.h>

using namespace std;

int T, N;

int cal(int x) {
	int a, mask = 0;
	while(x) {
		a = x % 10;
		mask |= 1 << a;
		x /= 10;
	}
	return mask;
}

int main() {
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas ++) {
		scanf("%d", &N);
		printf("Case #%d: ", cas);
		if(N == 0) {
			printf("INSOMNIA\n");
			continue;
		}
		int mask = 0, res;
		for(res = N; ; res += N) {
			mask |= cal(res);
			if(mask == 1023) break;
		}
		printf("%d\n", res);
	}
	return 0;
}
