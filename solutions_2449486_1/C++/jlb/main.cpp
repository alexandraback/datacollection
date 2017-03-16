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
	int caseNum,row,col;
	int board[101][101],rawBoard[101][101];
	bool isOk;
	bool cutAll,cut;
	int cutNum,high;
	int onMax,onMin,rawMax;
	cin>>caseNum;
	for(int num=0;num<caseNum;num++){
		cin>>row>>col;
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				cin>>rawBoard[i][j];
				board[i][j]=100;
			}
		}
		//row
		for(int i=0;i<row;i++){
			onMin=board[i][0];
			rawMax=rawBoard[i][0];
			cutNum=0;
			for(int j=0;j<col;j++){
				if(board[i][j]>rawBoard[i][j]){
					cutNum++;
					onMin=max(onMin,board[i][j]);
					rawMax=max(rawMax,rawBoard[i][j]);
				}else{
					continue;
				}
			}
			if(cutNum==col){
				for(int j=0;j<col;j++){
					board[i][j]=rawMax;
				}
			}
		}
		//col
		for(int i=0;i<col;i++){
			onMax=onMin=board[0][i];
			rawMax=rawBoard[0][i];
			cutNum=0;
			for(int j=0;j<row;j++){
				if(board[j][i]>=rawBoard[j][i]){
					cutNum++;
					onMin=min(onMin,board[j][i]);
					onMax=max(onMax,board[j][i]);
					rawMax=max(rawMax,rawBoard[j][i]);
				}else{
					continue;
				}
			}
			if(cutNum==row && onMax > rawMax){
				for(int j=0;j<row;j++){
					if(board[j][i]>rawMax){
						board[j][i]=rawMax;
					}
				}
			}
		}
		isOk=true;
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				if(board[i][j]!=rawBoard[i][j]){
					isOk=false;
					break;
				}
			}
			if(!isOk){
				break;
			}
		}
		if(isOk){
			cout<<"Case #"<<num+1<<": YES"<<endl;
		}else{
			cout<<"Case #"<<num+1<<": NO"<<endl;
		}
	}
	return 0;
}