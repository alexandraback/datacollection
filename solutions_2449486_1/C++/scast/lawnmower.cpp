#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
using namespace std;
#define MAXN 101
#define INF 0x3f3f3f3f

int t, n, m, tab[MAXN][MAXN], r[MAXN], c[MAXN];
int main () {
    scanf("%d", &t);
    for (int T=1; T<=t; T++) {
	scanf("%d%d", &n, &m);
	memset(r, 0, sizeof r);
	memset(c, 0, sizeof c);
	for (int i=0; i<n; i++) {
	    for (int j=0; j<m; j++) {
		scanf("%d", &tab[i][j]);
		r[i] = max(r[i], tab[i][j]);
	    }
	}
	for (int j=0; j<m; j++) {
	    for (int i=0; i<n; i++) c[j] = max(c[j], tab[i][j]);
	}
	bool solvable = true;
	for (int i=0; i<n && solvable; i++) {
	    for (int j=0; j<m && solvable; j++) {
		solvable = (r[i] == tab[i][j] || c[j] == tab[i][j]);
	    }
	}
	if (solvable)printf("Case #%d: YES\n", T);
	else printf("Case #%d: NO\n", T);

    }
    return 0;
}
