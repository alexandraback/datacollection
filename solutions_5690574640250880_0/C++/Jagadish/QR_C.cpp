#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<cstring>
#include<map>
#include<algorithm>
#include<vector>
#include<stdlib.h>

using namespace std;

#define MEM(v,i) memset(v,i,sizeof(v))

typedef long long int LL;

void print(int R, int C, int M){
	int i = 0, j = 0, count = 0;
	int non_mines = R*C-M;
	char c = '*';
	char str[60][60];
	for(i = 0;i<R; i++){
		for(j = 0; j<C; j++){
			str[i][j] = '*';
		}
		str[i][C] = '\0';
	}
	if(M == 0){
		for(i = 0; i<R; i++){
			for(j = 0; j<C; j++){
				str[i][j] = '.';
			}
		}
		str[0][0] = 'c';
		for(i = 0; i<R; i++){
			printf("%s\n",str[i]);
		}
		return;
	}
	if(M == R*C-1){
		str[0][0] = 'c';
	}
	else if(R==1 || C == 1){
		str[0][0] = 'c';
		count = 1;
		if(R==1){
			for(i = 1; count<non_mines && i<C;count++,i++){
				str[0][i] = '.';
			}
		}
		else if(C==1){
			for(i = 1; count<non_mines && i<R; count++, i++){
				str[i][0] = '.';
			}
		}
	}
	else if(R==2 || C==2){
		str[0][0] = 'c';
		str[0][1] = '.', str[1][1] = '.', str[1][0] = '.';
		count = 4;
		i = 0, j = 0;
		if(R == 2){
			for(j = 2; count<non_mines; j++){
				str[0][j] = '.', str[1][j] = '.';
				count += 2;
			}
		}
		else{
			for(i = 2; count<non_mines; i++){
				str[i][0] = '.', str[i][1] = '.';
				count += 2;
			}
		}
	}
	else{
		str[0][0] = 'c';
		str[0][1] = '.', str[1][1] = '.', str[1][0] = '.';
		count = 4;
		int max_R = R;
		for(i = 2; i<R && count<non_mines; i++){
			if(count+3 == non_mines){
				max_R = i;
				break;
			}
			str[i][0] = '.', str[i][1] = '.';
			count += 2;
		}
//		cout<<count<<" "<<non_mines<<endl<<flush;
		for(j = 2; j<C && count<non_mines; j++){
			if(count+max_R==non_mines){
				for(i = 0; i<max_R; i++){
					str[i][j] = '.';
					count++;
				}
			}
			else if(count+max_R+1 == non_mines){
					for(i = 0; i<max_R-1; i++){
						str[i][j] = '.';
						count++;
					}
					max_R--;
			}
			else if(count+max_R>non_mines){
					for(i = 0; i<max_R && count<non_mines; i++){
						str[i][j] = '.';
						count++;
					}
			}
			else if(count+max_R<non_mines){
				for(i = 0;i<max_R; i++){
					str[i][j] = '.';
					count++;
				}
			}
		}
		if(count<non_mines){
			printf("Impossible\n");
			return;
		}
	}			
	 				
	for(i = 0;i<R; i++){
		printf("%s\n",str[i]);
	}
}

int main(){
	int test = 0, R = 0, C = 0, M = 0;
	int i = 0, j = 0;
	scanf("%d",&test);
	for(int x_test = 1;x_test<=test; x_test++){
		scanf("%d %d %d",&R,&C,&M);
		printf("Case #%d:\n",x_test);
		if(M==0){
			print(R,C,M);
//			printf("Impossible\n");
			continue;
		}
		if(M==R*C-1){
			print(R,C,M);
			continue;
		}
		if(R==1 || C==1){
			print(R,C,M);
			continue;
		}
		if(R*C-M>1 && R*C-M<4){
			printf("Impossible\n");
			continue;
		}
		if(R==2 || C==2){
			if(M%2==1){
				printf("Impossible\n");
				continue;
			}
			print(R,C,M);
			continue;			
		}
		if(R>=3 && C>=3){
			if(R*C-M==5){
				printf("Impossible\n");
				continue;
			}
			print(R,C,M);
		}
	}
	return(0);
}
