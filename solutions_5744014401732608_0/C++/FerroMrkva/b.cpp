#include <stdio.h>
#include <string.h>

const int N = 60;

long long res[N],m;
int n;
int G[N][N];

int main(){
	int cases;
	scanf("%d",&cases);
	for(int t=1;t<=cases;++t){
		printf("Case #%d: ",t);
		memset(res,0,sizeof(res));
		memset(G,0,sizeof(G));
		scanf("%d%lld",&n,&m);
		res[n-1]=1;
		for(int i=n-2;i>=0;--i){
			res[i]=0;
			for(int j=i+1;j<n;++j){
				if (res[i]+res[j]<=m){
					res[i]+=res[j];
					G[i][j]=1;
				}
			}
		}
		if (res[0]==m){
			puts("POSSIBLE");
			for(int i=0;i<n;++i){
				for(int j=0;j<n;++j){
					printf("%d",G[i][j]);
				}
				puts("");
			}
		} else puts("IMPOSSIBLE");
	}
	return 0;
}
