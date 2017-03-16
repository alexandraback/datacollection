#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctype.h>
#include <string.h>

using namespace std;

int main(int argc,char** argv){
	int caseNum;
	char board[4][4];
	cin>>caseNum;
	bool hasEmpty=false;
	bool isWin;
	char winner;
	for(int num=0;num<caseNum;num++){
		hasEmpty=false;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				cin>>board[i][j];
				if(board[i][j]=='.'){
					hasEmpty=true;
				}
			}
		}
		//row
		for(int i=0;i<4;i++){
			isWin=true;
			if(board[i][0]=='.'){
				isWin=false;
				continue;
			}
			for(int j=1;j<4;j++){
				if(board[i][j]!=board[i][0]&&board[i][j]!='T'){
					isWin=false;
					break;
				}
			}
			if(isWin==true){
				winner=board[i][0];
				if(winner=='T'){
					winner=board[i][1];
				}
				break;
			}
		}
		if(isWin==true){
			printf("Case #%d: %c won\n",num+1,winner);
			continue;
		}
		//col
		for(int i=0;i<4;i++){
			isWin=true;
			if(board[0][i]=='.'){
				isWin=false;
				continue;
			}
			for(int j=1;j<4;j++){
				if(board[j][i]!=board[0][i]&&board[i][j]!='T'){
					isWin=false;
					break;
				}
			}
			if(isWin==true){
				winner=board[0][i];
				if(winner=='T'){
					winner=board[1][i];
				}
				break;
			}
		}
		if(isWin==true){
			printf("Case #%d: %c won\n",num+1,winner);
			continue;
		}
		//cross 1
		isWin=true;
		for(int i=1;i<4;i++){
			if((board[i][i]!=board[0][0]&&board[i][i]!='T')||board[i][i]=='.'){
				isWin=false;
				break;
			}
		}

		if(isWin==true){
			winner=board[0][0];
			if(winner=='T'){
				winner=board[1][1];
			}
			printf("Case #%d: %c won\n",num+1,winner);
			continue;
		}
		//cross 2
		isWin=true;
		for(int i=1;i<4;i++){
			if((board[i][3-i]!=board[0][3]&&board[i][3-i]!='T')||board[i][3-i]=='.'){
				isWin=false;
				break;
			}
		}
		if(isWin==true){
			winner=board[0][3];
			if(winner=='T'){
				winner=board[1][2];
			}
			printf("Case #%d: %c won\n",num+1,winner);
			continue;
		}
		if(!hasEmpty){
			printf("Case #%d: Draw\n",num+1);
		}else{
			printf("Case #%d: Game has not completed\n",num+1);
		}
	}
	return 0;
}