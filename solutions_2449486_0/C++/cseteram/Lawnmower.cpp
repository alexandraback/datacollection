#include<stdio.h>

int lawn[110][110];

inline int max(int a, int b) { return (a>b)?a:b; }

int main() {

	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	int t,T,i,j,n,m,h_max;
	bool pos=true;

	scanf("%d", &T);
	for(t=1 ; t<=T ; t++) {
		scanf("%d %d", &n, &m);
		for(i=1 ; i<=n ; i++) 
			for(j=1 ; j<=m ; j++)
				scanf("%d", &lawn[i][j]);
	
		for(i=1 ; i<=n ; i++) {
			for(j=1,h_max=0 ; j<=m ; j++)
				h_max=max(h_max,lawn[i][j]);
			lawn[i][m+1]=h_max;
		}
		for(j=1 ; j<=m ; j++) {
			for(i=1,h_max=0 ; i<=n ; i++)
				h_max=max(h_max,lawn[i][j]);
			lawn[n+1][j]=h_max;
		}

		for(i=1,pos=true ; i<=n ; i++) {
			for(j=1 ; j<=m ; j++) {
				if(lawn[i][j] < lawn[i][m+1] && lawn[i][j] < lawn[n+1][j]) {
					pos=false;
					break;
				}
			}
		}

		printf("Case #%d: ", t);
		if(pos) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}