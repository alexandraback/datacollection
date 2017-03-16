#include <stdio.h>

int n, graph[100][100];

int stack[100];

int paths(int i, int j) {
	int p, ret=0;
	if (i==j) return 1;
	for (p=0; p<n; p++) { 
		if (!stack[p] && graph[i][p]) {
			stack[p]=1;
			ret+=paths(p, j);
			stack[p]=0;
		}
	}
	return ret;
}

int main() {

	int t, i, j, k, m, mi;

	scanf("%d", &t);

	for (k=0; k<t; k++) {

		scanf("%d", &n);

		for (i=0; i<n; i++) for (j=0; j<n; j++) graph[i][j]=0;

		for (i=0; i<n; i++) {
			stack[i]=0;
			scanf("%d", &m);
			for (j=0; j<m; j++) {
				scanf("%d", &mi);
				mi--;
				graph[i][mi]=1;
			}
		}

		int done=0;

		for (i=0; i<n && !done; i++) {
			for (j=0; j<n && !done; j++) {
				stack[i]=1;
				if (paths(i, j)>1) done=1;
				stack[i]=0;
			}
		}

		if (done) printf("Case #%d: Yes\n", k+1);
		else printf("Case #%d: No\n", k+1);
	}

	return 0;
}

