#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long LL;

int len(LL x) {
	return x ? len(x / 10) + 1 : 0;
}

char s[100];
int a[100];

LL calc(LL n, int pos) {
	sprintf(s + 1, "%lld", n);
	LL res1 = 0, res2 = 0;
	for (int i = pos; i; --i) {
		res1 = res1 * 10 + s[i] - '0';
	}
	for (int i = pos + 1; s[i]; ++i) {
		res2 = res2 * 10 + s[i] - '0';
	}
	//printf("%lld %lld\n", res1, res2);
	return res1 + res2;
}

LL n, l, ans, pow;
int test_case;

int main() {
	scanf("%d", &test_case);
	for (int i = 1; i <= 14; ++i) {
		a[i] = a[i - 1] * 10 + 9;
	}
	for (int case_cnt = 1; case_cnt <= test_case; ++case_cnt) {
		scanf("%lld", &n);
		l = len(n), ans = 0, pow = 1ll;
		for (int i = 2; i <= l; ++i) {
			ans += a[(i - 1) >> 1] + a[i >> 1] + 1;
			pow *= 10;
		}
		LL tmp = n - pow;
		//printf("%lld\n", l);
		if (n - pow) {
			if (!(n % 10)) {
				++ans;
				--tmp;
				--n;
			}
			for (int i = 1; i < l; ++i) {
				tmp = min(tmp, calc(n, i));
			}
		}
		ans += n < 10;
		printf("Case #%d: %lld\n", case_cnt, ans + tmp);
	}
	return 0;
}
