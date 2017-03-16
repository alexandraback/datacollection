#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAXN 110

int map[MAXN][MAXN];
int oprn[MAXN], oprm[MAXN];

int main(){
	int i, j, k, n, m, T;
//	freopen("B-large.in", "r", stdin);
//	freopen("B.out", "w", stdout);
	scanf("%d", &T);
	for (k = 1; k <= T; k++){
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++){
				scanf("%d", &map[i][j]);
			}
			
		printf("Case #%d: ", k);
		for (i = 0; i < n; i++){
			oprn[i] = 0;
			for (j = 0; j < m; j++)
				oprn[i] = max(oprn[i], map[i][j]);
		}
		for (j = 0; j < m; j++){
			oprm[j] = 0;
			for (i = 0; i < n; i++)
				oprm[j] = max(oprm[j], map[i][j]);
		}
		
		for (i = 0; i < n; i++){
			for (j = 0; j < m; j++){
				if (map[i][j] != min(oprn[i], oprm[j])) break;
			}
			if (j < m) break;
		}
		if (i < n) printf("NO\n");
		else printf("YES\n");
	} 
	return 0;
}
