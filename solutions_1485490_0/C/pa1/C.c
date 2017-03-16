long long int __max(long long int a,long long int b) {return a > b ? a : b;}
long long int __min(long long int a,long long int b) {return a < b ? a : b;}

int main(){
	int t,T,N,M,ty_A[108],i,j,k,l,ty_B[108],ci,cj,add_A = 1,add_B = 1;
	long long int F[108][108],q_B[108],q_A[108],res,cA,cB,ct;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d",&N);
		scanf("%d",&M);
		
		for(i=1;i<=N;i++){
			scanf("%lld",&q_A[i]);
			scanf("%d",&ty_A[i]);
		}
		
		for(i=1;i<=M;i++){
			scanf("%lld",&q_B[i]);
			scanf("%d",&ty_B[i]);
		}
		
		for(i=0;i<=N;i++)
			F[i][M+1] = 0;
			
		for(i=0;i<=M;i++)
			F[N+1][i] = 0;
			
		for(i=N;i>=1;i--){
			for(j=M;j>=1;j--){
				if(ty_A[i] == ty_B[j]){
					cA = 0;
					cB = 0;
					ci = i;
					cj = j;
					add_A = 1;
					add_B = 1;
					
					res = 0;
					while(ci<=N && cj<=M){
						if((add_A == 1) && ty_A[ci] == ty_A[i]){
							add_A = 0;
							cA += q_A[ci];
						}
						
						if(ty_B[cj] == ty_B[j]){
							cB += q_B[cj];
							add_B = 0;
						}
					
						if(ty_A[ci] == ty_B[cj]){
							res = __max(res, __min(cA,cB) + F[ci+1][cj+1]);
						}
						
						//printf("%d %d - %lld %lld\n",ci,cj,cA,cB);
						if(cA < cB){
							ci++;add_A = 1;
						} else if(cA > cB){
							cj++;add_B = 1;
						} else 
							break;
					}
					F[i][j] = res;
					//printf("%d %d res = %lld\n",i,j,res);
				} else {
					F[i][j] = __max(F[i+1][j], F[i][j+1]);
				}
			}
		}
		res = 0;
		for(i=1;i<=N;i++)
			for(j=1;j<=M;j++)
				res = __max(res,F[i][j]);
		printf("Case #%d: %lld\n",t,res);
	}
}