#include <stdio.h>
#include <algorithm>
using namespace std;
main(){
	int testcase;
	scanf("%d ",&testcase);
	for(int casenum=1;casenum<=testcase;casenum++){
		printf("Case #%d: ",casenum);
		char board[5][5];
		for(int i=0;i<4;i++){
			scanf("%s ",board[i]);
		}
		int bl=0;
		bool xw=false,ow=false;
		for(int i=0;i<4;i++)for(int j=0;j<4;j++)if(board[i][j]=='.')bl++;
		int x,o,t;
		for(int i=0;i<4;i++){
			x=0,o=0,t=0;
			for(int j=0;j<4;j++){
				if(board[i][j]=='X')x++;
				if(board[i][j]=='O')o++;
				if(board[i][j]=='T')t++;
			}
			if(x+t==4)xw=true;
			if(o+t==4)ow=true;
			
			x=0,o=0,t=0;
			for(int j=0;j<4;j++){
				if(board[j][i]=='X')x++;
				if(board[j][i]=='O')o++;
				if(board[j][i]=='T')t++;
			}
			if(x+t==4)xw=true;
			if(o+t==4)ow=true;
		}
		x=0,o=0,t=0;
		for(int j=0;j<4;j++){
			int i=j;
			if(board[j][i]=='X')x++;
			if(board[j][i]=='O')o++;
			if(board[j][i]=='T')t++;
		}
		if(x+t==4)xw=true;
		if(o+t==4)ow=true;

		x=0,o=0,t=0;
		for(int j=0;j<4;j++){
			int i=3-j;
			if(board[j][i]=='X')x++;
			if(board[j][i]=='O')o++;
			if(board[j][i]=='T')t++;
		}
		if(x+t==4)xw=true;
		if(o+t==4)ow=true;
		
		if(xw)puts("X won");
		if(ow)puts("O won");
		if(!xw&&!ow)puts(bl?"Game has not completed":"Draw");
	}
}