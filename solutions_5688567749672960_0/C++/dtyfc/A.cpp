#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int f[maxn];
int rev(int x) {
	int ret = 0;
	while(x) {
		ret = ret * 10 + (x % 10);
		x /= 10;
	}
	return ret;
}
int main() {
#ifdef youmu
	freopen("A.in", "r", stdin);
	freopen("A.ou", "w", stdout);
#endif
	f[1] = 1;
	for(int i = 2; i <= 1000000; i++) {
		f[i] = f[i - 1] + 1;
		int u = rev(i);
		if(i % 10 != 0 && u < i) f[i] = min(f[i], f[u] + 1);
	}
	int T, x, cases = 0;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &x);
		printf("Case #%d: %d\n", ++cases, f[x]);
	}
	return 0;
}
