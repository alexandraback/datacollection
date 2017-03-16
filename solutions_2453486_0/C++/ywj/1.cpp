#include<stdio.h>

char map[10][10];

bool hang(int i,char c){
	for(int j=0;j<4;j++){
		if(map[i][j]!=c&&map[i][j]!='T'){
			return false;
		}
	}
	return true;
}

bool lie(int i,char c){
	for(int j=0;j<4;j++){
		if(map[j][i]!=c&&map[j][i]!='T'){
			return false;
		}
	}
	return true;
}

bool is_win(char c){
	for(int i=0;i<4;i++){
		if(hang(i,c))return true;
	}
	for(int j=0;j<4;j++){
		if(lie(j,c))return true;
	}
	int id=0;
	for(;id<4;id++){
		if(map[id][id]!=c&&map[id][id]!='T')break;
	}
	if(id>=4)return true;
	id=0;
	for(;id<4;id++){
		if(map[id][3-id]!=c&&map[id][3-id]!='T')break;
	}
	if(id>=4)return true;
	return false;
}

bool is_empty(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(map[i][j]=='.')return true;
		}
	}
	return false;
}


int main(){
	freopen("A-small.in","r",stdin);
	freopen("A-small.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int Case=1;Case<=T;Case++){
		for(int i=0;i<4;i++){
			scanf("%s",map[i]);
		}
		if(is_win('X')){
			printf("Case #%d: X won\n",Case);
			continue;
		}
		if(is_win('O')){
			printf("Case #%d: O won\n",Case);
			continue;
		}
		if(is_empty()){
			printf("Case #%d: Game has not completed\n",Case);
			continue;
		}
		printf("Case #%d: Draw\n",Case);
	}
	return 0;
}
