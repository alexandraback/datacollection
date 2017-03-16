#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
int a[100][100];

int main() {
	int o, cas = 0;
	scanf("%d", &o);
	while (o--) {
		int n;
		long long m;
		cin>>n>>m;
		printf("Case #%d: ", ++cas);
		memset(a, 0, sizeof(a));
		for (int i = 2; i <n; i++) {
			for (int j = 1; j < i; j++) {
				a[j][i] = 1;
			}
		}
		int k = 2;
		long long now = 1, sum = 0;
		for (int i = 1; i < n; i++) {
			if (i > 2)
				now *= 2;
			sum+=now;
		}
		if (sum < m) {
			printf("IMPOSSIBLE\n");
		}else {
			printf("POSSIBLE\n");
			a[1][n] = 1;
			m--;
			int k = 2;
			while (m > 0) {
				if (m % 2 == 1) a[k][n] = 1;
				k ++;
				m /= 2;
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j<=n; j++)
					printf("%d", a[i][j]);
				printf("\n");
			}
		}
	}
}
