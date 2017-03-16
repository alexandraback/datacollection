#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<stdlib.h>

using namespace std;
#define MEM(v,i) memset(v,0,sizeof(v));

int N = 0;
int matrix[1002][1002];
int paths[1002][1002];

void print_matrix(){
	cout<<"Printing Matrix"<<endl<<flush;
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=N; j++){
			cout<<matrix[i][j]<<" "<<flush;
		}
		cout<<endl<<flush;
	}
}

void print_paths(){
	cout<<"Printing Paths"<<endl<<flush;
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=N; j++){
			cout<<paths[i][j]<<" "<<flush;
		}
		cout<<endl<<flush;
	}
}

int find_diamond(){
	int i = 0, j = 0,k =0;
	int flag=0;
//	print_matrix();
//	print_paths();
	do{
		flag = 0;
		for(i = 1; i<=N; i++){
			for(j = 1; j<=N; j++){
				int temp = 0;
				for(k = 1; k<=N; k++){
					if(matrix[i][k]==1 && paths[k][j]>=1){
						temp+= paths[k][j];
					}
				}
				if(matrix[i][j] == 1)
					temp++;
				if(temp>paths[i][j]){
					paths[i][j] = temp;
					flag = 1;
				}
			}
		}
	}while(flag==1);

//	print_paths();
	for(i = 1; i<= N; i++){
		for(j = 1; j<=N; j++){
			if(paths[i][j]>1){
				return(0);
			}
		}
	}
	return(1);
}

int main(){
	int test = 0, x_test = 0;
	int i = 0, j = 0;
	scanf("%d\n",&test);
	for(x_test = 1; x_test<= test; x_test++){
		scanf("%d\n",&N);
		int count = 0,pos = 0;
		for(i = 1; i<=N; i++){
			scanf("%d",&count);
			for(j = 1; j<=count; j++){
				scanf("%d",&pos);
				matrix[i][pos] = 1;
				paths[i][pos]=1;
			}
		}
		int result = find_diamond();
		if(result==0)
			printf("Case #%d: Yes\n",x_test);
		else printf("Case #%d: No\n",x_test);
		MEM(matrix,0);
		MEM(paths,0);
	}
	return(0);
}
