#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int T;
int N;
int S;
int p;
int score[100];
int out;

void get(){
	scanf("%d %d %d",&N,&S,&p);
	for(int i=0;i<N;i++){
		scanf("%d",&score[i]);
	}
	return;
}

void solve(){
	int sup=0;
	out=0;
	for(int i=0;i<N;i++){
		if(score[i]>=p*3-2){
			out++;
		}else if(score[i]>=2 && score[i] >= p*3-4 && sup<S){
			out++;
			sup++;
		}
	}
}

int main(int argc,char **argv){
	scanf("%d\n",&T);
	for(int i=0;i<T;i++){
		get();
		solve();
		printf("Case #%d: %d\n",i+1,out);
	}
}
