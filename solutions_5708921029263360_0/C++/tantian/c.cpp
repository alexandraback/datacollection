#include <cstdio>

int main(){
	int T=0;
	scanf("%d", &T);
	for (int t=1; t<=T; ++t){
		int J,P,S,K;
		scanf("%d%d%d%d", &J,&P,&S,&K);
		printf("Case #%d: ", t);
		if (K<S){
			printf("%d\n", J*P*K);
			for (int i=1; i<=J; ++i)
			for (int j=1; j<=P; ++j)
			for (int k=1; k<=K; ++k)
				printf("%d %d %d\n", i,j,(i+j+k)%S+1);
		} else {
			printf("%d\n", J*P*S);
			for (int i=1;i<=J; ++i)
			for (int j=1;j<=P; ++j)
			for (int k=1;k<=S; ++k)
				printf("%d %d %d\n", i,j,k);
		}
	}
}

