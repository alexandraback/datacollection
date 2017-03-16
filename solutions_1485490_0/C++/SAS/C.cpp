#include<stdio.h>
#include<stdlib.h>
int N,M;
long long int a[121];
long long int as[121][121];
int A[121];
long long int b[121];
long long int bs[121][121];
int B[121];
long long int LCS[121][121];
long long int min(long long int x,long long int y){
	if(x > y) return y;
	return x;
}
long long int max(long long int x,long long int y){
	if(x < y) return y;
	return x;
}
long long int max(long long int x,long long int y,long long int z){
	return max(max(x,y),z);
}



int main(){
	int T;
	scanf("%d",&T);
	for(int ca=1;ca<=T;ca++){
		scanf("%d %d",&N,&M);
		for(int i=0;i<121;i++)for(int j=0;j<121;j++) as[i][j] = bs[i][j] = 0;
		for(int i=0;i<N;i++){
			scanf("%lld %d",&a[i],&A[i]);
			for(int j=0;j<121;j++){
				as[j][i + 1] = as[j][i];
			}
			as[A[i]][i + 1] = as[A[i]][i] + a[i];
		}
		for(int i=0;i<M;i++){
			scanf("%lld %d",&b[i],&B[i]);
			for(int j=0;j<121;j++){
				bs[j][i + 1] = bs[j][i];
			}
			bs[B[i]][i + 1] = bs[B[i]][i] + b[i];
		}
		/*
		for(int i=1;i<3;i++){
			for(int j=0;j<=N;j++)
				printf("%lld ",as[i][j]);
			printf("\n");
		}
		for(int i=1;i<3;i++){
			for(int j=0;j<=M;j++)
				printf("%lld ",bs[i][j]);
			printf("\n");
		}
		*/
		for(int i=0;i<121;i++)for(int j=0;j<121;j++)LCS[i][j] = 0;
		
		long long int tmpS = 0;
		for(int j=0;j<M;j++){
			if(A[0] == B[j]){
				tmpS += b[j];
			}
			LCS[0][j] = min(tmpS,a[0]);
		}
		tmpS = 0;
		for(int i=0;i<N;i++){
			if(A[i] == B[0]){
				tmpS += a[i];
			}
			LCS[i][0] = min(tmpS,b[0]);
		}
		/*
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				printf("%lld ",LCS[i][j]);
			}
			printf("\n");
		}*/

		for(int i=1;i<N;i++){
			for(int j=1;j<M;j++){
				
				long long int _max = max(LCS[i - 1][j - 1], LCS[i - 1][j], LCS[i][j - 1]);
				if(A[i] != B[j]){
					LCS[i][j] = _max;
					continue;
				}
		//		printf("<%d,%d>o_max = %lld",i,j,_max);
				for(int ii = 0;ii <= i ;ii++){
					for(int jj = 0;jj<=j;jj++){
		//				if(ii == 0 && jj == 0){
		//					printf(" %d %d <ii = %d jj = %d> %lld %lld\n",A[i],B[j],ii,jj,as[A[i]][i] - as[A[i]][ii]   , bs[B[j]][j] - bs[B[j]][jj]);
		//					printf(" %lld-%lld %lld-%lld\n",as[A[i]][i],  as[A[i]][ii]   , bs[B[j]][j] , bs[B[j]][jj]);
		//				}
						long long int y = 0;
						if(ii-1 >= 0 && jj - 1 >= 0) y = LCS[ii-1][jj-1];
						_max = max(_max, y+ min( as[A[i]][i + 1] - as[A[i]][ii]   , bs[B[j]][j + 1] - bs[B[j]][jj]  ));
					}
				}
		//		printf("  o_max = %lld\n",_max);
				LCS[i][j] = _max;
			}
		}
		//for(int i=0;i<N;i++){
		//	for(int j=0;j<M;j++){
		//		printf("%lld ",LCS[i][j]);
		//	}
		//	printf("\n");
		//}
		printf("Case #%d: %lld\n",ca,LCS[N-1][M-1]);
	}
	return 0;
}
