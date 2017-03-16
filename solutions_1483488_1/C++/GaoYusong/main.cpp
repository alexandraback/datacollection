#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int vis[2001000];

int main()
{
	int T;

	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);

	scanf("%d", &T);
	for (int cn = 0; cn < T; cn++) {
		int A, B;
		scanf("%d%d", &A, &B);
		memset(vis, 0, sizeof(vis));
		int cnt = 1;
		int ans = 0;
		for (int i = A; i <= B; i++) {
			int x = i;
			int aa[20], cc = 0;
			while (x) {
				aa[cc++] = x % 10;
				x /= 10;
			}
			reverse(aa, aa + cc);
			for (int j = 1; j <= cc - 1; j++) {
				for (int k = cc; k >= 1; k--)
					aa[k] = aa[k - 1];
				aa[0] = aa[cc];
				int y = 0;
				for (int k = 0; k < cc; k++) {
					y = y * 10 + aa[k];
				}
				if (y >= A && y <= B && y > i) {
					if (vis[y] != cnt) {
						ans++;
						vis[y] = cnt;
					}
				}
			}
			cnt++;
		}
		
		printf("Case #%d: %d\n", cn + 1, ans);
	}
	return 0;
}
