#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

long long v[1000100];
long long A;
int N;

int main() {
	freopen("A-large (5).in", "r", stdin); freopen("w.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int re = 1; re <= T; re++) {
		scanf("%lld%d", &A, &N);
		for (int i = 0; i < N; i++) {
			scanf("%lld", v + i);
		}
		sort(v, v + N);
		int ans = 1000;
		for (int i = 0; i <= N; i++) {
			int cnt = 0, flag = 0;
			int p = A;
			for (int j = 0; j < N - i; j++) {
				while (p <= v[j] && cnt <= N) {
					p += p - 1;
					cnt++;
				}
				if (p <= v[j]) {
					flag = 1;
					break;
				}
				p += v[j];
			}
			if (!flag) {
				if (cnt + i < ans) {
					ans = cnt + i;
				}
			}
		}
		printf("Case #%d: %d\n", re, ans);
	}
}
