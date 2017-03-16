#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int T, w, n, a[110][110], c[110], len, ans, m, k;
int flag;
char s[110], b[110][110];
int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &m, &k);
		ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if ((i & j) < k) ans++;
		printf("Case #%d: %d\n", ++w, ans);
	}
	return 0;
}
