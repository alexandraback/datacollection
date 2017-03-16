#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	
	int T;
	double tmp;
	int n, a[1005], b[1005];
	scanf("%d", &T);
	for (int T0=1; T0 <= T; T0++) {
		printf("Case #%d: ", T0);
		scanf("%d", &n);
		for (int i=0; i<n; i++) {
			scanf("%lf", &tmp);
			a[i] = (int) (tmp*10000000);
		}
		sort(a, a+n);
		for (int i=0; i<n; i++) {
			scanf("%lf", &tmp);
			b[i] = (int) (tmp*10000000);
		}
		sort(b, b+n);
		
		int ans0 = 0;
		int i = n-1;
		for (int j=n-1; j>=0; j--) {
			while (b[i] > a[j] && i>=0) i -= 1;
			if (i < 0) break;
			i -= 1;
			ans0 += 1;
		}
		int ans = 0;
		i = n-1;
		for (int j=n-1; j>=0; j--) {
			while (a[i] > b[j] && i>=0) i -= 1;
			if (i < 0) break;
			i -= 1;
			ans += 1;
		}
		printf("%d %d\n", ans0, n - ans);
	}
	return 0;
}

