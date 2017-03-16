#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int tcase, caseNo;
char Board[5][5];

bool isBoardFull(){
	 for(int i=0; i<4; ++i)
	 	for(int j=0; j<4; ++j) if(Board[i][j] == '.') return false;
	 return true;
}

bool is_Won(char c){
	 
	 char oc = (c=='X')?'O':'X';

	 for(int i=0; i<4; ++i){
	 	 bool isWon = true;
	 	 for(int j=0; j<4; ++j) if(Board[i][j] == '.' || Board[i][j] == oc) isWon = false;
	 	 if(isWon) return true;
	 }
	 for(int i=0; i<4; ++i){
	 	 bool isWon = true;
	 	 for(int j=0; j<4; ++j) if(Board[j][i] == '.' || Board[j][i] == oc) isWon = false;
	 	 if(isWon) return true;
	 }

	 bool isDia = true;
	 for(int i=0; i<4; ++i) if(Board[i][i] == '.' || Board[i][i] == oc) isDia = false;
	 if(isDia) return true;

	 bool isAntiDia = true;
	 for(int i=0; i<4; ++i) if(Board[i][3-i] == '.' || Board[i][3-i] == oc) isAntiDia = false;
	 if(isAntiDia) return true;
	 return false;

 }

int main(){
    for(scanf("%d",&tcase), caseNo = 1; tcase; tcase -=1, caseNo++){
    	 for(int i=0; i<4; ++i) scanf("%s",Board[i]);
    	 if(is_Won('X')) printf("Case #%d: X won\n", caseNo);
    	 else if(is_Won('O')) printf("Case #%d: O won\n", caseNo);
    	 else if(isBoardFull()) printf("Case #%d: Draw\n", caseNo);
    	 else printf("Case #%d: Game has not completed\n", caseNo);	
    }
    return 0;
}