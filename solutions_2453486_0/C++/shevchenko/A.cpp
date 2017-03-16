#include<stdio.h>

char map[4][5];

void process(){
	int i,j,board_full=1;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(map[i][j]=='.') board_full=0;
		}
	}
	int Xwin=0,Owin=0;
	int x,o,t;
	for(i=0;i<4;i++){
		x=0;o=0;t=0;
		for(j=0;j<4;j++){
			if(map[i][j]=='X') x++;
			if(map[i][j]=='O') o++;
			if(map[i][j]=='T') t++;
		}
		if((x==3 && t==1) || x==4) Xwin=1;
		if((o==3 && t==1) || o==4) Owin=1;

		x=0;o=0;t=0;
		for(j=0;j<4;j++){
			if(map[j][i]=='X') x++;
			if(map[j][i]=='O') o++;
			if(map[j][i]=='T') t++;
		}
		if((x==3 && t==1) || x==4) Xwin=1;
		if((o==3 && t==1) || o==4) Owin=1;
	}
	
	x=0;o=0;t=0;
	for(i=0;i<4;i++){
		if(map[i][i]=='X') x++;
		if(map[i][i]=='O') o++;
		if(map[i][i]=='T') t++;
	}
	if((x==3 && t==1) || x==4) Xwin=1;
	if((o==3 && t==1) || o==4) Owin=1;
	
	x=0;o=0;t=0;
	for(i=0;i<4;i++){
		if(map[i][3-i]=='X') x++;
		if(map[i][3-i]=='O') o++;
		if(map[i][3-i]=='T') t++;
	}
	if((x==3 && t==1) || x==4) Xwin=1;
	if((o==3 && t==1) || o==4) Owin=1;

	if(Xwin==1) printf("X won\n");
	else if(Owin==1) printf("O won\n");
	else if(board_full==0) printf("Game has not completed\n");
	else printf("Draw\n");
}

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int i,j,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		for(j=0;j<4;j++) scanf("%s",map[j]);
		printf("Case #%d: ",i);
		process();
	}
	return 0;
}