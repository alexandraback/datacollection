#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue>

using namespace std;
const int maxN = 1000009;
typedef pair<int, char> para;

int t, n, k;
long long int m;
int tab[100][100], stop[100];

void rozloz(long long int k, int p) {
	long long int result = 1;
	int potega = p - 1;
	while (result < k) {
		result *= 2;
		potega--;
	}
	while (k != 0){
		if (k >= result) {
			k -= result;
			stop[potega] = 1;
		}
		result /= 2;
		potega++;
	}
}
int main() {
	scanf("%d",&t);
	for (int i = 1; i <= t; i++) {
		scanf("%d%lld", &n,&m);
		
		long long int maks = max(1LL, (long long)pow(2,(n-2)));
		printf("CASE #%d: ",i);
		if (m > maks)
			printf("IMPOSSIBLE\n");
		else {
			printf("POSSIBLE\n");
			tab[1][n] = 1;
			m--;
			long long int cnt = 1;
			int licz = n - 1;
			while (m - cnt >= 0) {
				tab[1][licz] = 1;
				for (int j = n; j >= licz + 1; j--)
					tab[licz][j] = 1;
				m -= cnt;
				cnt *= 2;
				licz--;
			}
			if (m > 0) {
				rozloz(m, n);
				tab[1][licz] = 1;
				for (int i = 1; i < n; i++) {
					if (stop[i] == 1)
					{
						tab[licz][i] = 1;
					}
				}
			}
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					printf("%d",tab[j][k]);
					tab[j][k] = 0;
					stop[j] = 0;
				}
				printf("\n");
			}
		}
	}
	return 0;
}
