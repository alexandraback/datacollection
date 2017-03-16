#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char g[5][5],tmp[5][5];
int judge(char c){
	bool note=1;
	for(int i=0;i<4;++i){
		note=1;
		for(int j=0;j<4;++j){
			if(tmp[i][j] != c){
				note=0;
				break;
			}
		}
		if(note) return 1;
	}
	for(int i=0;i<4;++i){
		note=1;
		for(int j=0;j<4;++j){
			if(tmp[j][i] != c){
				note=0;
				break;
			}
		}
		if(note) return 1;
	}
	note=1;
	for(int j=0;j<4;++j){
		if(tmp[j][j] != c){
			note=0;
			break;
		}
	}
	if(note) return 1;

	note=1;
	for(int j=0;j<4;++j){
		if(tmp[j][3-j] != c){
			note=0;
			break;
		}
	}
	return note;
}
int main(){
	int t,cas=1;
	freopen("E://A-large.in","r",stdin);
	freopen("E://A-large.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		bool note=1;
		for(int i=0;i<4;++i)
			scanf("%s",g[i]);
		for(int i=0;i<4;++i){
			for(int j=0;j<4;++j){
				if(g[i][j]=='.'){
					note=0;
				}
				if(g[i][j]=='T')
					tmp[i][j]='X';
				else tmp[i][j]=g[i][j];
			}
		}
		printf("Case #%d: ",cas++);
		if(judge('X')){
			printf("X won\n");
		}
		else{
			for(int i=0;i<4;++i){
				for(int j=0;j<4;++j){
					if(g[i][j]=='T')
						tmp[i][j]='O';
					else tmp[i][j]=g[i][j];
				}
			}
			if(judge('O')){
				printf("O won\n");
			}
			else{
				if(note==1)
					printf("Draw\n");
				else printf("Game has not completed\n");
			}
		}
	}return 0;
}
