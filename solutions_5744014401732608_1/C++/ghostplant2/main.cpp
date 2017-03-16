#include <stdio.h>
#include <string.h>

int main() {
	int T, n;
	typedef long long ll;
	ll m;
	scanf("%d", &T);
	static char g[55][55];
	for (int C=1;C<=T;++C) {
		scanf("%d%lld", &n, &m);
		ll top = 1ll<<(n-2);
		printf("Case #%d: ", C);
		if (m>top)
			puts("IMPOSSIBLE");
		else {
			puts("POSSIBLE");
			memset(g, '0', sizeof(g));
			for (int i=0;i<n;++i)
				g[i][n]=0;
			for (int i=1;i<n;++i)
				for (int j=i+1;j<n;++j)
					g[i][j]='1';
			for (int i=n-3, v=1;i>=0;--i, ++v)
				if (m>=(1ll<<i))
					m-=(1ll<<i), g[0][v]='1';
			if (m)
				g[0][n-1]='1';
			for (int i=0;i<n;++i)
				puts(g[i]);
		}
	}
	return 0;
}

/*

1->

*/
