#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
char map[5][5];

bool empty(){
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			if(map[i][j]=='.') return 1;
	return 0;
}
bool win(char ch){
	int flag=0, tmp, i, j;
	for(i=0, tmp=1; i<4; i++)
		if(map[i][i]!='T'&&map[i][i]!=ch) tmp=0;
	flag|=tmp;
	for(i=0, tmp=1; i<4; i++)
		if(map[i][3-i]!='T'&&map[i][3-i]!=ch) tmp=0;
	flag|=tmp;
	for(i=0; i<4; i++){
		for(j=0, tmp=1; j<4; j++)
			if(map[i][j]!='T'&&map[i][j]!=ch) tmp=0;
		flag|=tmp;
	}
	for(i=0; i<4; i++){
		for(j=0, tmp=1; j<4; j++)
			if(map[j][i]!='T'&&map[j][i]!=ch) tmp=0;
		flag|=tmp;
	}
	return flag;
}

int main(){
	int T, time=0;
	scanf("%d", &T);
	while(T--){
		for(int i=0; i<4; i++)
			scanf(" %s", map[i]);
		printf("Case #%d: ", ++time);
		if(win('X')) puts("X won");
		else if(win('O')) puts("O won");
		else if(empty()) puts("Game has not completed");
		else puts("Draw");
	}
	return 0;
}
