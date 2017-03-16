#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long

int n,m,a[105][105];

int main() {
	int tc;
	scanf("%d",&tc);
	for (int t=1; t<=tc; t++) {
		scanf("%d%d",&n,&m);
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++) {
				scanf("%d",&a[i][j]);
			}
		int yes = 1;
		for (int x=1; x<=100; x++) {
			for (int i=0; i<n; i++)
				for (int j=0; j<m; j++)
					if (a[i][j] == x) {
						int ok = 2;
						for (int k=0; k<n; k++)
							if (a[k][j] > a[i][j]) { ok--; break; }
						for (int k=0; k<m; k++)
							if (a[i][k] > a[i][j]) { ok--; break; }
						if (ok == 0) {
							yes = 0;
						}
					}
		}
		if (yes) printf("Case #%d: YES\n",t);
		else printf("Case #%d: NO\n",t);
	}
	return 0;
}
