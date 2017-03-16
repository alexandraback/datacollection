#include <cstdio>
#include <cstring>

const int maxn = 10000000;

int casei, cases, open, closed, n;
int ans[maxn];
int q[maxn];

inline void update(int t, int now) {
	if (t < maxn && ans[t] == 0) {
		ans[t] = ans[now] + 1;
		//printf("%d: %d\n", t, ans[t]);
		q[++closed] = t;
	}
}

inline int reverse(int now) {
	int res = 0;
	while (now > 0) {
		int tmp = now % 10;
		res = res * 10 + tmp;
		now /= 10;
	}
	return res;
}

void prepare() {
	open = 0;
	closed = 0;
	memset(ans, 0, sizeof(ans));
	ans[1] = 1;
	q[0] = 1;

	while (open <= closed) {
		int now = q[open++];
		update(now + 1, now);
		update(reverse(now), now);
	}
}


int main() {
	prepare();
	
	
	scanf("%d", &cases);
	for (casei = 1; casei <= cases; ++casei) {
		scanf("%d", &n);
		printf("Case #%d: %d\n", casei, ans[n]);
	}
	
	return 0;
}

