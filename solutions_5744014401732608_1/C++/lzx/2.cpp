#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 55;
int T, f[N];
long long pow[N];

int main()
{
	//freopen("2.in", "r", stdin);
	//freopen("2.out", "w", stdout);
	scanf("%d", &T);
	pow[0] = 1;
	for (int i = 1; i <= 62; ++ i)
		pow[i] = pow[i - 1] * 2ll;
	int Case = 0;
	while (T --)
	{
		++ Case;
		int n;
		long long m;
		scanf("%d%lld", &n, &m);
		printf("Case #%d: ", Case);
		memset(f, 0, sizeof(f));
		for (int i = n - 3, j = 2; j < n && i + 1; -- i, ++ j)
			if (pow[i] <= m)
			{
				m -= pow[i];
				f[j] = 1;
			}
		if (m > 1) puts("IMPOSSIBLE");
		else 
		{
			if (m) f[n] = 1;
			puts("POSSIBLE");
			for (int i = 1; i <= n; ++ i)
				printf("%d", f[i]);
			puts("");
			for (int i = 2; i <= n; ++ i)
			{
				for (int j = 1; j <= n; ++ j)
					if (j > i) printf("1");
						else printf("0");
				puts("");
			}
		}
	}
}