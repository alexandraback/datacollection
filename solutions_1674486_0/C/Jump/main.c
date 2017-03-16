#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int** addrow(int r1, int r2, int**data, int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (data[r2][i] == 1) {
			if (data[r1][i] == 0)
				data[r1][i] = 9;
			else
				data[r1][i] = -1;
		}
	}
	for (i=0;i<n;i++) {
		if (data[r2][i]==1) data = addrow(r1,i,data,n);
	}
	return data;
}

int main() {
	int testcase, it;
	scanf("%d", &testcase);
	for (it = 1; it <= testcase; it++) {
		int n, i, j, k, ans;
		ans = 0;
		scanf("%d", &n);
		int** data = malloc(sizeof(int*) * n);
		for (i = 0; i < n; i++)
			data[i] = malloc(sizeof(int) * n);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				data[i][j] = 0;
		for (i = 0; i < n; i++) {
			int t;
			scanf("%d", &t);
			for (j = 0; j < t; j++) {
				if (t == 0)
					break;
				int t1;
				scanf("%d", &t1);
				data[i][t1-1] = 1;
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (data[i][j] == 1)
					data = addrow(i, j, data, n);
			}
			for (k = 0; k < n; k++) {
				if (data[i][k] == -1)
					ans = 1;
			}
			if (ans == 1)
				break;
		}

		if (ans == 1)
			printf("Case #%d: Yes\n", it);
		else
			printf("Case #%d: No\n", it);
	}
	return 0;
}
