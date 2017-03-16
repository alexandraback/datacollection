#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
typedef long long ll;
int a[MAXN][MAXN];
int b[MAXN];
int len;

void conv(ll M) {
	len = 0;
	while (M > 0) {
		b[len++] = M & 1;
		M >>= 1;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; tt++) {
		ll B;
		ll M;
		scanf("%I64d %I64d", &B, &M);
		printf("Case #%d:", tt);
		if (M > (1ll << (B-2))) {
			puts(" IMPOSSIBLE");
			continue;
		}
		conv(M);
		puts(" POSSIBLE");
		memset(a, 0, sizeof(a));
		for (int i = B-len+1; i <= B - 1; i++) 
			for (int j = i + 1; j <= B; j++) a[i][j] = 1;
		//cout << len << ' ' << B << endl;
		for (int i = max(B - len, 2ll); i <= B; i++) {
			//cout << i << endl;
			a[1][i] = 1;
		}
		if (B-len > 1)
			for (int i = 0; i < len-1; i++) a[B-len][B-i-1] = b[i];
		for (int i = 1; i <= B; i++) {
			for (int j = 1; j <= B; j++) printf("%d", a[i][j]);
			puts("");
		}
	}
	return 0;
}
