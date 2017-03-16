#include <cstdio>
int main (){
	bool YN,YN_2,b;
	int T,N,M,s[100][100],i,j,k,l;
	scanf("%d",&T);
	for (i=1;i<=T;i++){
		scanf("%d %d",&N,&M);
		for (j=0;j<N;j++){
			for (k=0;k<M;k++){
				scanf("%d",&s[j][k]);
			}
		}
		b=1;
		for (j=0;j<N;j++){
			for (k=0;k<M;k++){
				YN=0;
				YN_2=0;
				for (l=0;l<M;l++){
					if (s[j][k]<s[j][l]) YN=1;
				}
				for (l=0;l<N;l++){
					if (s[j][k]<s[l][k]) YN_2=1;
				}
				if (YN && YN_2){
					b=0;
				}
			}
		}
		if (b){
			printf("Case #%d: YES\n",i);
		} else {
			printf("Case #%d: NO\n",i);
		}
	}
	return 0;
}
