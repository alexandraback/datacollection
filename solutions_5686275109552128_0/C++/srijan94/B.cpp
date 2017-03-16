#include <cstdio>

using namespace std;

int P[1009];

int max(int a, int b) {
	return (a > b ? a : b);
}
int min(int a, int b) {
	return (a < b ? a : b);
}

int main(int argc, char const *argv[])
{
	freopen("iSB.in", "r", stdin);
	freopen("oSB.txt", "w", stdout);
	int tc, T, D, i, j, lim, ans, tm;
	scanf("%d", &T);
	for(tc = 1; tc <= T; tc++) {
		scanf("%d", &D);
		lim = -1;
		for(i = 0; i < D; i++) {
			scanf("%d", &P[i]);
			lim = max(lim, P[i]);
		}
		ans = 100000000;
		for(i = 1; i <= lim; i++) {
			tm = 0;
			for(j = 0; j < D; j++) {
				if(i < P[j]) {
					tm += (P[j] / i);
					if(P[j] % i == 0) tm--;
				}
			}
			ans = min(ans, i + tm);
		}
		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}