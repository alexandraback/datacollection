#include<stdio.h>
#include<string.h>

int contain(int a[], int n, int len) {
	int i;
	for (i = 0; i < len; i++) {
		if (a[i] == n)
			return 1;
	}
	return 0;
}

int main() {
	int i, j, k;
	int t, n;
	int num, track, max;
	int circle[10];
	int bff[1001];
	int count[1001];
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d", &n);
		bff[0] = 0;
		max = 0;
		for (j = 0; j < n; j++) {
			scanf("%d", &bff[j + 1]);
		}
		for (j = 0; j < n; j++) {
			num = 1;
			for (k = 0; k < 10; k++) {
				circle[k] = 0;
			}
			circle[0] = j + 1;
			track = j + 1;
			while (contain(circle, bff[track], num) == 0) {
				circle[num] = bff[track];
				track = bff[track];
				num++;
			}
			for (k = 0; k < n; k++) {
				if (bff[k + 1] == circle[num - 1] && contain(circle, k + 1, num) == 0) {
					num++;
					break;
				}
			}
			if (max < num)
				max = num;
		}
		printf("Case #%d: %d\n", i + 1, max);
	}
}