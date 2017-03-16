#include<cstdio>
#include<cstring>

int a[2000];

int cal(int max, int s) {
	int ret = 0;
	for (int i = s + 1;i <= max;i++) {
		if (i % s == 0) {
			ret += (i / s - 1) * a[i];
		} else {
			ret += (i / s) * a[i];
		}
	}
	return ret;
}

int main() {

	int t;
	scanf("%d", &t);
	for (int ii = 1;ii <= t;ii++) {
		int n;
		scanf("%d", &n);
		memset(a, 0, sizeof(a));

		int max = 0;
		for (int i = 0;i < n;i++) {
			int x;
			scanf("%d", &x);
			a[x]++;
			max = max < x ? x : max;
		}
		int ret = max;
		
		for (int i = 1;i < max;i++) {
			int temp = cal(max, i) + i;
			ret = ret > temp ? temp : ret;
		}

		printf("Case #%d: %d\n", ii, ret);
	}

	return 0;
}