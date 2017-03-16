#include<stdio.h>
bool valid(int val){
	return val!=2&&val!=3&&val!=5&&val!=7;	
}
int star;
void solve_general(int N,int M,int K){
	int i,j,k=0,x=1,y=1,f;
	if(K==1){
		x=y=1;
		f=0;
	} else {
		for(i=2;i<=N;i++){
			for(j=2;j<=M;j++){
				k=K-i*j;
				x=i;
				y=j;
				if(!k){
					f=0;
					goto out;
				} else if(k>1&&k<i&&j<M){
					f=1;
					goto out;
				} else if(k>1&&k<j&&i<N){
					f=2;
					goto out;
				}
			}
		}
	}
	
out:
	//printf("(%d,%d,%d)\n",x,y,k);
	//puts("QQ");
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			putchar(i+j==0?'c':i<x&&j<y||f==1&&j==y&&i<k||f==2&&i==x&&j<k?'.':(star++,'*'));
		}
		puts("");
	}
}
void solve_special(int N){
	int i,j,k,x,y;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			putchar(i+j==0?'c':i==N-1&&j>1||i==N-2&&j==N-1?(star++,'*'):'.');
		}
		puts("");
	}
}
void solve_N_1(int N,int K){
	int i;
	for(i=0;i<N;i++){
		putchar(!i?'c':i<K?'.':(star++,'*'));
	}
	puts("");
}
void solve_M_1(int M,int K){
	int i;
	for(i=0;i<M;i++){
		putchar(!i?'c':i<K?'.':(star++,'*'));
		puts("");
	}
}
void solve_trivial(int N,int M,int K){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			putchar(i+j==0?'c':K?(star++,'*'):'.');
		}
		puts("");
	}
}
int main(){
	int T,TN;
	int N,M,K;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		scanf("%d%d%d",&N,&M,&K);
		printf("Case #%d:\n",T);
		star=0;
		if(K==0||K==N*M-1){
			solve_trivial(N,M,K);
		} else if(N==1){
			solve_N_1(M,M-K);
		} else if(M==1){
			solve_M_1(N,N-K);
		} else if(N>3&&N==M&&K==N-1){
			solve_special(N);
		} else if(valid(N*M-K)&&!((N==2||M==2)&&K%2)){
			solve_general(N,M,N*M-K);
		} else {
			star=-1;
			puts("Impossible");
		}
		if(star!=-1&&star!=K){
			printf("%d %d %d ERR %d %d\n",N,M,K,star,K);
			while(1);
		}
	}
}
