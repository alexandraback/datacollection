#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

char arr[1001];

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out","w", stdout);
	int m, n, i, j;
	int t, ti;
	scanf("%d", &t);
	for (ti = 0; ti < t; ti++) {
		printf("Case #%d: ", ti + 1);
		scanf("%s", arr);
		n = strlen(arr);
		char c = arr[0];
		int count = 0;
		for (i = 0; i < n; i++) {
			if (c != arr[i]) {
				count++;
				c = arr[i];
			}
		}
		if (c == '-') count++;
		printf("%d\n", count);
	}
	return 0;

}