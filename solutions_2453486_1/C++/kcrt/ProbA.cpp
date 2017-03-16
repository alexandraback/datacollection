
/*
 * 	FILENAME - FILEDESCRIPTION
 *		Programmed by kcrt <kcrt@kcrt.net>
 */

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


bool CellMatch(char x, char y){

	if(x == 'T') return true;
	if(x == y) return true;
	return false;

}
bool CheckGame(char c[], char X){

	// 横 
	for(int i = 0;i<=3; i++){
		if(
			CellMatch(c[i*4 + 0], X) &&
			CellMatch(c[i*4 + 1], X) &&
			CellMatch(c[i*4 + 2], X) &&
			CellMatch(c[i*4 + 3], X)
		  ){
			return true;
		}
	}

	// 縦
	for(int i = 0; i<=3; i++){
		if(
			CellMatch(c[i + 4*0], X) &&
			CellMatch(c[i + 4*1], X) &&
			CellMatch(c[i + 4*2], X) &&
			CellMatch(c[i + 4*3], X)
		  ){
			return true;
		}
	}

	// ななめ
	if(
		CellMatch(c[0], X) &&
		CellMatch(c[5], X) &&
		CellMatch(c[10], X) &&
		CellMatch(c[15], X)
	  ){
		return true;
	}
	if(
		CellMatch(c[3], X) &&
		CellMatch(c[6], X) &&
		CellMatch(c[9], X) &&
		CellMatch(c[12], X)
	  ){
		return true;
	}
	

	return false;

}

bool HasEmpty(char* c){

	for(int i = 0; i < 4*4; i++){
		if(c[i] == '.') return true;
	}
	return false;

}

int main(){

	int testcase;
	vector<string> ans(8);
	int anstype = 0;
	char c[32];

	ans[0] = "X won";
	ans[1] = "O won";
	ans[2] = "Draw";
	ans[3] = "Game has not completed";
	ans[4] = "Undefined";

	scanf("%d", &testcase);

	for(int i = 0; i < testcase; i++){

		scanf("%s", &(c[0]));
		scanf("%s", &(c[4]));
		scanf("%s", &(c[8]));
		scanf("%s", &(c[12]));

		bool XWon = CheckGame(c, 'X');
		bool OWon = CheckGame(c, 'O');

		if(XWon && OWon){
			anstype=4;
		}else if(XWon){
			anstype=0;
		}else if(OWon){
			anstype=1;
		}else if(!HasEmpty(c)){
			anstype=2;
		}else{
			anstype=3;
			
		}
		printf("Case #%d: %s\n", i+1, ans[anstype].c_str());
	}

}
