#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
#include <string>

using namespace std;

int n, m, at[128][128], heng[128], shu[128];

int main() {
	freopen("/home/family/Desktop/B-large.in", "r", stdin);
	freopen("/home/family/Desktop/B-large.out", "w", stdout);
	int T, Cas = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", at[i] + j);
		memset(heng, 0, sizeof(heng));
		memset(shu, 0, sizeof(shu));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				heng[i] = max(heng[i], at[i][j]);
				shu[j] = max(shu[j], at[i][j]);
			}
		}
		bool yes = true;
		for (int i = 0; yes && i < n; i++)
			for (int j = 0; yes && j < m; j++)
				if (heng[i] > at[i][j] && shu[j] > at[i][j])
					yes = false;
		printf("Case #%d: %s\n", ++Cas, yes ? "YES" : "NO");
	}
	return 0;
}
