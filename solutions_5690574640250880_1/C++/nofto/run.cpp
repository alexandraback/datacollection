#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

char board[50][50];

int main()
{
	int T;
	scanf("%d",&T);  
	for(int t=1; t<=T; t++)
	{		
		int R,C,M;
		scanf("%d %d %d",&R,&C,&M);
		bool possible=false;
		int F=R*C-M;
		for(int i=0;i<R;i++) for(int j=0;j<C;j++) board[i][j]='.';
		if(R==1){
			for(int j=0;j<M;j++) board[0][j]='*';
			board[0][C-1]='c';
			possible=true;
		}
		else if(C==1){
			for(int i=0;i<M;i++) board[i][0]='*';
			board[R-1][0]='c';
			possible=true;			
		}
		else if(R==2){
			if(F==1){
				for(int i=0;i<R;i++) for(int j=0;j<C;j++) board[i][j]='*';
				board[0][0]='c';		
				possible=true;
			}
			else if(F!=2 && F%2==0){
				for(int j=0;j<M/2;j++){
					board[0][j]='*';
					board[1][j]='*';
				}
				board[R-1][C-1]='c';
				possible=true;
			}
		}
		else if(C==2){
			if(F==1){
				for(int i=0;i<R;i++) for(int j=0;j<C;j++) board[i][j]='*';
				board[0][0]='c';		
				possible=true;
			}
			else if(F!=2 && F%2==0){
				for(int i=0;i<M/2;i++){
					board[i][0]='*';
					board[i][1]='*';
				}
				board[R-1][C-1]='c';
				possible=true;
			}
		}
		else if(F==1){
			for(int i=0;i<R;i++) for(int j=0;j<C;j++) board[i][j]='*';
			board[0][0]='c';		
			possible=true;		
		}
		else if(F==4){
			for(int i=0;i<R;i++) for(int j=0;j<C;j++) board[i][j]='*';
			board[0][0]='c';
			board[0][1]='.';
			board[1][0]='.';
			board[1][1]='.';		
			possible=true;		
		}
		else if(F==6){
			for(int i=0;i<R;i++) for(int j=0;j<C;j++) board[i][j]='*';
			board[0][0]='c';
			board[0][1]='.';
			board[1][0]='.';
			board[1][1]='.';		
			board[2][0]='.';
			board[2][1]='.';		
			possible=true;		
		}
		else if(F>7){
			if(M<=(R-2)*(C-2)){
				for(int i=0;i<M;i++) board[i/(C-2)][i%(C-2)]='*';
			}
			else{
				for(int i=0;i<(R-2)*(C-2);i++) board[i/(C-2)][i%(C-2)]='*';
				int left=M-(R-2)*(C-2);
				if(F%2==1){
					board[R-3][C-3]='.';	
					left++;
				}
				int added=0;
				for(int j=0;j<left/2 && j<C-3;j++){
					board[R-2][j]='*';
					board[R-1][j]='*';
					added+=2;
				}
				left-=added;
				if(left>0) for(int i=0;i<left/2;i++){
					board[i][C-2]='*';
					board[i][C-1]='*';
				}				
			}
			board[R-1][C-1]='c';
			possible=true;
		}
		printf("Case #%d:\n",t);
		if(possible) for(int i=0;i<R;i++){
			for(int j=0;j<C;j++) printf("%c",board[i][j]);
			printf("\n");
		}
		else printf("Impossible\n");			
	}
  return 0;
}
