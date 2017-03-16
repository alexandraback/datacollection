#include <cstdio>
#include <cstring>
typedef long long ll;
const int POW[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
int dig[10];
bool done[2000010];
int main() {
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int TST;
	scanf("%d", &TST);

	for ( int tst = 1; tst <= TST; tst ++ ) {
		printf("Case #%d: ", tst);
		memset(done, 0, sizeof(done));
		int A, B;
		scanf("%d%d", &A, &B);
		ll ans = 0;
		for ( int x = A; x <= B; x ++ ) {
			int tmp = x;
			int nDig = 0;
			while ( tmp ) {
				dig[nDig ++] = tmp % 10;
				tmp /= 10;
			}
			bool allSame = true;
			for ( int i = 0; i < nDig - 1; i ++ )
				if ( dig[i] != dig[i + 1] )
					allSame = false;
			if ( allSame ) 
				continue;
			tmp = x;
			int ok = 0;
			for ( int i = 0; i < nDig; i ++ ) {
				if ( A <= tmp && tmp <= B && !done[tmp] ) { 
					ok ++;
					done[tmp] = true;
				}
				int head = tmp / POW[nDig - 1] % 10;
				tmp = tmp % POW[nDig - 1];
				tmp = tmp * 10 + head;
			}

			ans += ok * (ok - 1) / 2;
		}
		printf("%lld\n", ans);
	}
}
