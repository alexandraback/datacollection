#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

char board[4][4];
  
int main()
{
    int T;
    scanf("%d\n",&T);
    for(int t=1; t<=T; t++)
    {
        int ti=-1;
        int tj=-1;
        bool xwin=false;
        bool owin=false;
        bool isend=true;
		for(int i=0;i<4;i++){
    	    for(int j=0;j<4;j++){
         	    scanf("%c",&board[i][j]);
         	    if(board[i][j]=='T'){
         	    	ti=i;
         	    	tj=j;
         	    }
         	    if(board[i][j]=='.'){
         	    	isend=false;
         	    }
            }
            scanf("\n");
        }
        scanf("\n");
        
        if(ti>=0){
        	board[ti][tj]='X';
        }
        for(int i=0;i<4;i++){
        	if(board[i][0]=='X' && board[i][1]=='X' && board[i][2]=='X' && board[i][3]=='X'){
        		xwin=true;
        		break;
        	}
        	if(board[0][i]=='X' && board[1][i]=='X' && board[2][i]=='X' && board[3][i]=='X'){
        		xwin=true;
        		break;
        	}
        }
        if(board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X' && board[3][3]=='X'){
        	xwin=true;
        }
        if(board[0][3]=='X' && board[1][2]=='X' && board[2][1]=='X' && board[3][0]=='X'){
        	xwin=true;
        }
        if(!xwin){
	        if(ti>=0){
	        	board[ti][tj]='O';
	        }
	        for(int i=0;i<4;i++){
	        	if(board[i][0]=='O' && board[i][1]=='O' && board[i][2]=='O' && board[i][3]=='O'){
	        		owin=true;
	        		break;
	        	}
	        	if(board[0][i]=='O' && board[1][i]=='O' && board[2][i]=='O' && board[3][i]=='O'){
	        		owin=true;
	        		break;
	        	}
	        }
	        if(board[0][0]=='O' && board[1][1]=='O' && board[2][2]=='O' && board[3][3]=='O'){
	        	owin=true;
	        }
	        if(board[0][3]=='O' && board[1][2]=='O' && board[2][1]=='O' && board[3][0]=='O'){
	        	owin=true;
	        }
        }
        if(xwin) printf("Case #%d: X won\n",t);
        else if(owin) printf("Case #%d: O won\n",t);
        else if(isend) printf("Case #%d: Draw\n",t);
        else printf("Case #%d: Game has not completed\n",t);
        
    }
  return 0;
}
