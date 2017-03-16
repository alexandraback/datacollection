#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		static int id = 0;
		printf("Case #%d: ", ++id);
		long long p, q;
		scanf("%lld/%lld", &p, &q);
		long long g = __gcd(p, q);
		p /= g, q /= g;
		int first = -1;
		for (int i = 1; i <= 40; ++i) {
			p <<= 1;
			long long g = __gcd(p, q);
			p /= g, q /= g;
			if (p >= q) {
				if (first == -1) {
					first = i;
				}
				p -= q;
				long long g = __gcd(p, q);
				p /= g, q /= g;
			}
		}
		if (q != 1) {
			printf("impossible\n");
		} else {
			printf("%d\n", first);
		}
	}
	return 0;
}
