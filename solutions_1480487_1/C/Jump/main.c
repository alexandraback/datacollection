#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int minn(int n, int*data) {
	int ans = data[0];
	int i;
	for (i = 0; i < n; i++) {
		if (data[i] < ans)
			ans = data[i];
	}
	return ans;
}
int minnumm(int n, int*data, int min) {
	int ans = 0;
	int i;
	for (i = 0; i < n; i++) {
		if (data[i] == min)
			ans++;
	}
	return ans;
}
int main() {
	int testcase, test;
	scanf("%d", &testcase);
	for (test = 1; test <= testcase; test++) {
		int n;
		scanf("%d", &n);
		int i;
		int sum = 0;
		int* data = (int*) malloc(sizeof(int) * n);
		int* ans = (int*) malloc(sizeof(int) * n);
		for (i = 0; i < n; i++) {
			scanf("%d", &data[i]);
			ans[i]=data[i];
			sum += data[i];
		}
		int credit = sum;
		printf("Case #%d:", test);
		while (1) {
			int min = minn(n, ans);
			int minnum = minnumm(n, ans, min);
			if (minnum <= credit) {
				int j;
				for (j = 0; j < n; j++)
					if (ans[j] == min)
						ans[j]++;
				credit -= minnum;
			} else {
				double rest = ((double) credit) / minnum;
				int j;
				for (j = 0; j < n; j++) {
					if (ans[j] == min)
						printf(" %f", (((ans[j] + rest) - data[j]) / sum) * 100);
					else
						printf(" %f", ((ans[j] - data[j]) * 100.0) / sum);
				}
				break;
			}
		}

		printf("\n");
	}
	return 0;
}
