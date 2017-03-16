#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define min(a,b) a<b?a:b

int mote[111111];

int addnum(int a, int m) {
//	printf("a = %d, m = %d\n", a, m);
	int  r = ((int) floor(log2((double) (m - 1) / (a - 1)))) + 1;
	return r > 0 ? r : 0;
}

int main() {
	int T, a, n, i, r, add, num;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("Case #%d: ", t);
		scanf("%d%d", &a, &n);
		for (i = 0; i < n; i++) {
			scanf("%d", mote + i);
		}
		sort(mote, mote + n);
/*		printf("A = %d\nmote: ", a);
		for (i = 0; i < n; i++) {
			printf("%d ", mote[i]);
		}
		puts("");*/
		r = n;
		if (a == 1) {
			printf("%d\n", r);
			continue;
		}
		add = 0;
		for (i = 0; i < n; i++) {
			num = mote[i] <= 1 ? 0 : addnum(a, mote[i]);
//			printf("add: %d\n", num);
			add += num;
			a = (1 << num) * (a - 1) + 1;
			a += mote[i];
			r = min(r, add + (n - i - 1));
		}
		printf("%d\n", r);
	}	
	return 0;
}
