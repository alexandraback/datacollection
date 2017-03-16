#include <cstdio>
#include <cstring>

using namespace std;

int g[100][100];
int n,m;

int main(){
	int T=0;
	scanf("%d", &T);
	for (int t=1;t<=T;++t){
		printf("Case #%d: ", t);
		scanf("%d %d", &n, &m);
		memset(g,0,sizeof(g));
		for (int i=0; i<n-1; ++i)
			for (int j=i+1; j<n-1; ++j) g[i][j]=1;
		if (m==(1<<(n-2)))
			for (int i=0; i<n-1; ++i) g[i][n-1]=1;
		else {
			for (int i=0; i<n-2; ++i)
				if ((1<<i)&m){
					g[i+1][n-1]=1;
				}
		}
		if (m>(1<<(n-2))){
			printf("IMPOSSIBLE\n");
		} else {
			printf("POSSIBLE\n");
			for (int i=0; i<n; ++i){
				for (int j=0; j<n; ++j)
					printf("%d", g[i][j]);
				printf("\n");
			}
		}
	}
}

