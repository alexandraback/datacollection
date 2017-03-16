#include <stdio.h>
#define MAX 1010
int map[MAX][MAX], n, used[MAX];
int DFS(int node) {
	int ans, i;
	for(i=0;i<n;i++) {
		if(map[node][i] == 1) {
			if(used[i] == 0) {
				//fprintf(stderr, "%d\n", i);
				used[i] = 1;
				ans=DFS(i);
				if(ans == 1) return 1;
			}
			else return 1;
		}
	}
	return 0;
}
int main() {
	int i, ii, jj, j, k, t, T, m, tmp;
	scanf("%d", &T);
	for(t=0;t<T;t++) {
		scanf("%d", &n);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				map[i][j] = 0;
		for(i=0;i<n;i++) {
			scanf("%d", &m);
			for(j=0;j<m;j++) {
				scanf("%d", &tmp);
				map[i][tmp - 1] = 1;
			}
		}
		printf("Case #%d: ", t + 1);
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++) {
				used[j] = 0;
			}
			used[i] = 1;
			ii = DFS(i);
			if(ii) {
				printf("Yes\n");
				break;
			}
		}
		if(!ii) printf("No\n");
	}
	return 0;
}
