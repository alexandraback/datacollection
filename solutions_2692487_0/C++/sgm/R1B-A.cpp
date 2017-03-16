#include <stdio.h>
#include <algorithm>

#define INT long long
#define min(a, b) ((a) < (b) ? (a) : (b))

int T;
INT A;
int N;
INT m[105];

int go(int i, INT me) {
	if(i == N) return 0;
	if(me > m[i]) {
		return go(i + 1, me + m[i]);
	}else {
		if(me > 1) {
			return min(go(i + 1, me), go(i, me + me - 1)) + 1;
		}else {
			return go(i + 1, me) + 1;
		}
	}
}

int main(void) {
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		scanf("%lld%d", &A, &N);
		for(int i = 0; i < N; i++) {
			scanf("%lld", &m[i]);
		}
		std::sort(m, m + N);
		printf("Case #%d: %d\n", t, go(0, A));
	}
	return 0;
}
