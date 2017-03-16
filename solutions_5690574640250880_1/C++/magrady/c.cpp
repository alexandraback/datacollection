#include<stdio.h>
int general_solve_func(int N,int M,int K,int &x,int &y,int &k){
	for(x=2;x<=N;x++)
		for(y=2;y<=M;y++)
			if(!(k=K-x*y)) return 3;
			else if(k>1&&k<x&&y<M) return 1;
			else if(k>1&&k<y&&x<N) return 2;
	return 0;
}
bool is_mine(int type,int i,int j,int x,int y,int f,int k){
	if(type==1) return i==x-1&&j>1||i==x-2&&j==y-1;
	return !(i<x&&j<y||f==1&&j==y&&i<k||f==2&&i==x&&j<k);
}
void print_general(int N,int M,int type,int x,int y,int f,int k){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			putchar(i+j==0?'c':is_mine(type,i,j,x,y,f,k)?'*':'.');
		}
		puts("");
	}
}
int main(){
	int T,TN;
	int N,M,K;
	int x,y,f,k;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		scanf("%d%d%d",&N,&M,&K);
		printf("Case #%d:\n",T);
		if(!K){
			print_general(N,M,0,840527,840527,0,840527);
		} else if(K==N*M-1){
			print_general(N,M,0,0,0,0,840527);
		} else if(N==1){
			print_general(N,M,0,840527,M-K,0,840527);
		} else if(M==1){
			print_general(N,M,0,N-K,840527,0,840527);
		} else if(N>=4&&N==M&&K==N-1){
			print_general(N,M,1,N,N,1,840527);
		} else if(f=general_solve_func(N,M,N*M-K,x,y,k)){
			print_general(N,M,0,x,y,f,k);
		} else {
			puts("Impossible");
		}
	}
}
