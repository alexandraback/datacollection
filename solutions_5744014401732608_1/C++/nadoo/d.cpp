#include<stdio.h>

int arr[100][100];
long long int pow(int n) {
	if (n >= 1) return pow(n - 1) * 2;
	else return 1;
}
int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int n, i, j,b;
	int t, ti;
	long long int m;
	scanf("%d", &t);
	for (ti = 0; ti < t; ti++) {
		printf("Case #%d: ", ti + 1);
		scanf("%d %lld", &b, &m);
		if (m > pow(b - 2)) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		else printf("POSSIBLE\n");
		m--;
		arr[1][b] = 1;
		for (i = b-1; i >=2 ; i--) {
			if (m % 2 == 1) arr[1][i] = 1;
			else arr[1][i] = 0;
			m /= 2;
		}
		for (i = 2; i <= b; i++) {
			for (j = i+1; j <= b; j++) {
				arr[i][j] = 1;
			}
		}
		for (i = 1; i <= b; i++) {
			for (j = 1; j <= b; j++) {
				printf("%d", arr[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}