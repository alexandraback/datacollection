#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"algorithm"
using namespace std;
typedef long long LL;
int T, t, len;
LL N, k, ans, Arr[20];
char s[20];
LL rev(LL X) {
	LL Y = 0;
	while (X > 0) {
		Y = Y * 10 + (X % 10);
		X /= 10;
	}
	return Y;
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.txt", "w", stdout);
	Arr[0] = 1;
	for (int i = 1; i < 16; i++) Arr[i] = Arr[i-1] * 10;
	scanf("%d", &T);
	while (t < T) {
		ans = 0;
		scanf("%lld", &N);
		k = len = 0;
		for (LL M = N; M > 0; M /= 10, len++);
		//printf("len = %d\n", len);
		for (int i = 1; i <= len; i++) {
			LL target = 0;
			if (i == len) {
				target = N;
				if (target != Arr[len-1]) {
					if (target % 10 == 0) target--;
					LL x = Arr[(len + 1) / 2];
					target = target / x * x + 1;
					target = rev(target);
				}
			}
			else {
				target = Arr[i] - 1;
				LL x = Arr[(i + 1) / 2];
				target = target / x * x + 1;
				//printf("..%lld\n", target);
				target = rev(target);
				//printf("...%lld\n", target);
			}
			ans += target - k;
			k = target;
			if (k < rev(k)) {
				k = rev(k);
				ans++;
			}
			//printf("ans-> %lld,, target = %lld\n", ans, target);
			if (i == len) {
				ans += N - k;
				break;
			}
		}
		printf("Case #%d: %d\n", ++t, ans);
	}
}
/*
3
1
19
23
*/
