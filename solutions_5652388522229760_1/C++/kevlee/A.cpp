#include <bits/stdc++.h>
using namespace std;
long long n, T, f[20];
int main () {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%lld", &T);
	for (int test=1; test<=T; test++) {
		scanf("%lld", &n);
		long long sum=0;
		memset(f, 0, sizeof f);
		for (int i=1; i<=1000000; i++) {
			long long m=n*i;
			while (m) {
				if (f[m%10]==0) sum+=1LL<<(m%10);
				f[m%10]++;
				m/=10;
			}
			if (sum==1023) {
				printf("Case #%d: %lld\n", test, 1LL*n*i);
				break;
			}
		}
		if (sum!=1023) printf("Case #%d: INSOMNIA\n");
	}
	return 0;
}
