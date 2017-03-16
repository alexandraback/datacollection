#include <stdio.h>
#include <algorithm>
double d1[1050];
double d2[1050];
int main() {
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test_no, T, N, i, a, b, ans1, ans2, cnt;
	scanf("%d", &T);
	for(test_no = 1; test_no <= T; test_no++) {
		for(i = 1; i <= 1000; i++) d1[i] = d2[i] = 0.0;
		ans1 = ans2 = 0;
		scanf("%d", &N);
		for(i = 1; i <= N; i++) scanf("%lf", &d1[i]);
		for(i = 1; i <= N; i++) scanf("%lf", &d2[i]);
		std::sort(d1+1, d1+N+1);
		std::sort(d2+1, d2+N+1);
		a = 2, b = 1;
		while(1) {
			if(d2[b] > d1[1] || b == N+1) break;
			ans2++;
			b++;
		}
		cnt = 0;
		while(a <= N) {
			cnt--;
			while(1) {
				if(d2[b] > d1[a] || b == N+1) break;
				cnt++;
				b++;
			}
			if(cnt > 0) {
				ans2 += cnt;
				cnt = 0;
			}
			a++;
		}
		a = 1, b = N;
		for(i = 1; i <= N; i++) {
			if(d1[i] > d2[a]) {
				ans1++;
				a++;
			}
		}
		printf("Case #%d: %d %d\n", test_no, ans1, ans2);
	}
	return 0;
}