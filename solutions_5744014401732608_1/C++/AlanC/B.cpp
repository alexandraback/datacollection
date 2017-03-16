#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#define FOR(i, s, e) for (int i=(s);i<(e);i++)
#define FOE(i, s, e) for (int i=(s);i<=(e);i++)
#define N 55
#define LL long long int
using namespace std;

LL n, m, tc;
int a[N][N];

void solve(int tc) {
	
	scanf("%I64d%I64d", &n, &m);
	printf("Case #%d: ", tc + 1);
	if ((1LL << (n - 2)) < m) printf("IMPOSSIBLE\n");
	else {
		printf("POSSIBLE\n");
		FOR(i, 0, n) FOR(j, 0, n) a[i][j] = 0;
		FOR(i, 0, n-1)
		FOR(j, i + 1, n-1)
			a[i][j] = 1;
			
		int c = 1;
		if (m == (1LL << (n-2))) a[0][n-1] = 1, m--;
		while (m > 0) {
			if (m % 2 == 1) a[c][n - 1] = 1;
			m /= 2;
			c++;
		}
		FOR(i, 0, n) {
			FOR(j, 0, n) printf("%d", a[i][j]);
			printf("\n");
		}
	}
}

int main() {
	scanf("%d", &tc);
	FOR(i, 0, tc) solve(i);
	return 0;
} 
