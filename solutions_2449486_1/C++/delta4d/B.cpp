#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 128;

int a[MAXN][MAXN];
int c[MAXN], r[MAXN];
int x[MAXN][MAXN];

int main() {
	int tc, cn = 0;
	int m, n;
	
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &m, &n);
		for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) scanf("%d", a[i]+j);
		memset(c, 0, sizeof(c));
		memset(r, 0, sizeof(r));
		for (int i=0; i<m; ++i) {
			for (int j=0; j<n; ++j) r[i] = max(r[i], a[i][j]);
		}	
		for (int j=0; j<n; ++j) {
			for (int i=0; i<m; ++i) c[j] = max(c[j], a[i][j]);
		}	
		for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) x[i][j] = 100;
		for (int i=0; i<m; ++i) {
			for (int j=0; j<n; ++j) x[i][j] = min(x[i][j], r[i]);
		}
		for (int j=0; j<n; ++j) {
			for (int i=0; i<m; ++i) x[i][j] = min(x[i][j], c[j]);
		}
//		for (int i=0; i<m; ++i) printf("%d ", r[i]); puts("");
//		for (int i=0; i<n; ++i) printf("%d ", c[i]); puts("");
		bool ok = true;
		for (int i=0; i<m; ++i) {
			for (int j=0; j<n; ++j) {
				if (a[i][j] != x[i][j]) ok = false;	
			}
		}
		printf("Case #%d: %s\n", ++cn, ok?"YES":"NO");
	}

	return 0;
}
