#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<vector>
#include<map>
using namespace std;
int mat[1000][1000];

int check_child(int mat[][1000],int row,int N){
	int mark[1000]={0};
	int curr;
	vector<int> ms;
	ms.push_back(row);
	while(ms.size()!=0){
		curr=ms.back();
		ms.pop_back();
		for(int i=0;i<N;i++){
			if(mat[curr][i]==1){
				ms.push_back(i);
				if(mark[i]!=0)return 1;
				else mark[i]=1;
			}
		}
	}
	return 0;
}


void run(){
	int T;
	int N;
	int M;
	int par;
	int yes;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d\n",&N);
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				mat[j][k]=0;
			}
		}

		for(int j=0;j<N;j++){
			scanf("%d",&M);
			for(int k=0;k<M;k++){
				// create graph
				scanf("%d",&par);
				mat[par-1][j]=1;
			}
		}

/*
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				printf("\t%d",mat[j][k]);
			}
			printf("\n");
		}
*/
		//
		for(int j=0;j<N;j++){
			// check the same child
			yes=check_child(mat,j,N);
			if(yes==1)break;
		}

		printf("Case #%d: ",i+1);
		if(yes==1)printf("Yes");
		else printf("No");
		printf("\n");
	}
}


int main(int argc,char** argv){
	run();
	return 0;
}
