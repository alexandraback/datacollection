#include<stdio.h>
int TC,TC_C,i,E,R,N,w[100],D[11][6],Res,j,k;
int max(int a,int b){return a<b?b:a;}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&TC);
	while(TC--){
		printf("Case #%d: ",++TC_C);
		scanf("%d%d%d",&E,&R,&N);
		if(R>=E)R=E;
		for(i=1;i<=N;i++){
			scanf("%d",&w[i]);
			for(j=R;j<=E;j++){
				D[i][j]=0;
				for(k=R;k<=E;k++){
					if(k<j-R)continue;
					if(D[i][j]<D[i-1][k]+(k-(j-R))*w[i])D[i][j]=D[i-1][k]+(k-(j-R))*w[i];
				}
			}
		}
		Res=0;
		for(i=R;i<=E;i++)if(D[N][i]>Res)Res=D[N][i];
		printf("%d\n",Res);
	}
}