#include <stdio.h>

#define MAX(_a_,_b_) (((_a_)>(_b_))?_a_:_b_)
#define MIN(_a_,_b_) (((_a_)<(_b_))?_a_:_b_)

int main(){
	int T;
	int M,N;
	int desired[200][200];
	int maxN[200];
	int maxM[200];
	int grass[200][200];
	scanf("%d", &T);
	for(int t = 1;t<=T;t++){
		scanf("%d %d",&N,&M);
		for(int i = 0;i<N;i++){
			for(int j = 0;j<M;j++){
				scanf("%d",&(desired[i][j]));
				maxN[i] = 0;
				maxM[j] = 0;
				grass[i][j] = 100;
			}
		}
		
		for(int i = 0;i<N;i++){
			for(int j = 0;j<M;j++){
				maxN[i] = MAX(maxN[i],desired[i][j]);
				maxM[j] = MAX(maxM[j],desired[i][j]);
			}
		}

		int ok = 1;
		for(int i = 0;i<N;i++){
			for(int j = 0;j<M;j++){
				if(desired[i][j] != MIN(MIN(100,maxN[i]),maxM[j]))
					ok = 0;
			}
		}
		printf("Case #%d: ",t);
		if(ok)
			printf("YES");
		else
			printf("NO");

		printf("\n");	
	}

	return 0;
}
