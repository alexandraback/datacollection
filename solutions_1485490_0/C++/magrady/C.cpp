#include<stdio.h>
long long s[101][101];
long long B[101][2],G[101][2],bs[101][101],gs[101][101];
main(){
	int n,m;
	int i,j,p,q,x;
	long long k;
	int T,TN;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++){
			scanf("%I64d%I64d",&B[i][0],&B[i][1]);
		}
		for(i=0;i<m;i++){
			scanf("%I64d%I64d",&G[i][0],&G[i][1]);
		}
		for(i=0;i<n;i++){
			k=B[i][0];
			x=B[i][1];
			bs[i][i]=0;
			bs[i][i+1]=B[i][0];
			for(j=i+1;j<n;j++){
				bs[i][j+1]=k+(B[j][1]==x?B[j][0]:0);
				if(B[j][1]!=x)continue;
				k+=B[j][0];		
			}
		}
		for(i=0;i<m;i++){
			k=G[i][0];
			x=G[i][1];
			gs[i][i]=0;
			gs[i][i+1]=G[i][0];
			for(j=i+1;j<m;j++){
				gs[i][j+1]=k+(G[j][1]==x?G[j][0]:0);
				if(G[j][1]!=x)continue;
				k+=G[j][0];		
			}
		}
		/*for(i=0;i<n;i++){
			for(j=i+1;j<=n;j++){
				printf("%I64d ",bs[i][j]);
			}
			puts("");
		}
		for(i=0;i<m;i++){
			for(j=i+1;j<=m;j++){
				printf("%I64d ",gs[i][j]);
			}
			puts("");
		}*/
				
		for(i=0;i<n;i++){
			s[i][m]=0;
		}
		for(i=0;i<m;i++){
			s[n][i]=0;
		}
		s[n][m]=0;
		for(i=n-1;i>=0;i--){
			for(j=m-1;j>=0;j--){
				if(B[i][1]!=G[j][1]){
					s[i][j]=s[i+1][j]>?s[i][j+1];
					continue;
				}
				//same!!
				s[i][j]=k=0;
				for(p=i+1;p<=n;p++){
					for(q=j+1;q<=m;q++){
						k>?=s[p][q]+(bs[i][p]<?gs[j][q]);
					}
				}
				s[i][j]>?=k;
			}
		}
		printf("Case #%d: %I64d\n",T,s[0][0]);
	}
}
