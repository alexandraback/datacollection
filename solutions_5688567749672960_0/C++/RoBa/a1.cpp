#include <cstdio>

const int MAXN = 1000010;
int ans[MAXN], q[MAXN];

int rev(int k) {
	int s = 0;
	while (k) {
		int tmp = k % 10;
		s = s * 10 + tmp;
		k /= 10;
	}
	return s;
}

void solve() {
	q[0] = 1;
	ans[1] = 1;
	int qh, qt;
	for (qh = 0, qt = 1 ; qh < qt ; ++qh) {
		for (int tp = 0 ; tp < 2 ; ++tp) {
			int next;
			if (tp == 0) {
				next = q[qh] + 1;
			} else {
				next = rev(q[qh]);
			}
			if (next < MAXN && !ans[next]) {
				ans[next] = ans[q[qh]] + 1;
				q[qt++] = next;
			}
		}
	}
}

int main() {
	int T;
	scanf("%d",&T);
	solve();
	for (int ca = 1 ; ca <= T ; ++ca) {
		int N;
		scanf("%d",&N);
		printf("Case #%d: %d\n", ca, ans[N]);
	}
	return 0;
}