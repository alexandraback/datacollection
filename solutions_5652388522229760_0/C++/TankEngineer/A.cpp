#include<vector>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		static int id = 0;
		printf("Case #%d: ", ++id);
		long long n;
		int vis = 0;
		scanf("%lld", &n);
		if (n == 0) {
			puts("INSOMNIA");
		} else {
			long long cur;
			for (cur = n; ; cur += n) {
				long long tmp = cur;
				while (tmp) {
					vis |= 1 << (tmp % 10);
					tmp /= 10;
				}
				if (vis == 1023) {
					break;
				}
			}
			printf("%lld\n", cur);
		}
	}
	return 0;
}
