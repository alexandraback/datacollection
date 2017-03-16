#include<stdio.h>
#include<string.h>
#include<algorithm>
long long dp[101][101];
struct X {
	long long type;
	long long count;
}box[1001],gift[10001];
long long u,v;
long long ioi[101][101],oio[101][101];
main(){
	int i,j,k,a,b;
	int T,TN;
	int n,m;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		scanf("%d%d",&n,&m);
		printf("Case #%d: ",T);
		for(i=0;i<n;i++){
			scanf("%I64d%I64d",&box[i].count,&box[i].type);
		}
		for(i=0;i<m;i++){
			scanf("%I64d%I64d",&gift[i].count,&gift[i].type);
		}
		for(i=0;i<n;i++){
			u=0;
			for(a=i+1;a<=n;a++){
				if(box[a-1].type==box[i].type){
					u+=box[a-1].count;
				}
				ioi[i][a]=u;
			}
		}
		for(j=0;j<m;j++){
			v=0;
			for(b=j+1;b<=m;b++){
				if(gift[b-1].type==gift[j].type){
					v+=gift[b-1].count;
				}
				oio[j][b]=v;
			}
		}
		for(i=0;i<=m;i++)dp[n][i]=0;
		for(i=0;i<=n;i++)dp[i][m]=0;
		for(i=n-1;i>=0;i--){
			for(j=m-1;j>=0;j--){
				if(box[i].type!=gift[j].type){
					dp[i][j]=dp[i+1][j]>?dp[i][j+1];
				} else {
					dp[i][j]=0;
					for(a=i+1;a<=n;a++){
						for(b=j+1;b<=m;b++){
							if(a==i&&b==j)continue;
							dp[i][j]>?=dp[a][b]+(ioi[i][a]<?oio[j][b]);
							//printf("[%d,%d,%I64d]",i,j,dp[i][j]);
						}
					}
				}
			}
		}
		printf("%I64d\n",dp[0][0]);
	}
}
