#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#define N 4000
#define mod 1000000007

long long total, sum;
std::vector<int> a;
long long val[440000];

long long cal(long long l, int r) {
	return (l + r) * (r - l + 1) / 2 % mod;
}

int main() {
	total = 3;
	sum = 3;
	a.push_back(1);
	a.push_back(2);
	a.push_back(2);
	while (sum < 1000000000) {
		int t = a[total - 1];
		if (total < 4000) {
			for (int i = 0; i < t; i += 1) {
				a.push_back(total);
			}
		}
		total += 1;
		sum += t;
	}
	int ncas, n;
	scanf("%d", &ncas);
	sum = 0;
	int t = 1;
	int l = 1, r;
	while (t <= total) {
		r = l + a[t - 1] - 1;
		val[t] = (val[t - 1] + t * cal(l, r) % mod) % mod;
		l = r + 1;
		t += 1;
	}
	while (ncas--) {
		scanf("%d", &n);
		int l = 1, r;
		long long ans = 0;
		total = 1;
		while (l <= n) {
			l = l + a[total - 1];
			total += 1;
		}
		total --;
		l -= a[total - 1];
		ans = (val[total - 1] + cal(l, n) * total % mod) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}