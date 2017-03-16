#include<iostream>
using namespace std;

const int N= 6;
char mp[N][N];

bool checkRow(int ri, char ch){
	for(int i= 1; i <= 4; i++)
		if(mp[ri][i] != 'T' && mp[ri][i] != ch)
			return false;
	return true;
}

bool checkCol(int ci, char ch){
	for(int i= 1; i <= 4; i++)
		if(mp[i][ci] != 'T' && mp[i][ci] != ch)
			return false;
	return true;
}



bool checkDiag0(char ch){
	for(int i= 1; i <= 4; i++)
		if(mp[i][i] != 'T' && mp[i][i] != ch)
			return false;
	return true;
}

bool checkDiag1(char ch){
	for(int i= 1; i <= 4; i++)
		if(mp[i][5-i] != 'T' && mp[i][5-i] != ch)
			return false;
	return true;
}

bool checkWin(char ch){
	bool flag= false;
	for(int i= 1; i <= 4; i++){
		flag= checkRow(i, ch);
		if(flag == true)
			return true;
		flag= checkCol(i, ch);
		if(flag == true)
			return true;
	}
	flag= checkDiag0(ch);
	if(flag == true)
		return true;
	flag= checkDiag1(ch);
	if(flag == true)
		return true;
	return false;
}

bool checkEmpty(){
	for(int i= 1; i <= 4; i++)
		for(int j= 1; j <= 4; j++)
			if(mp[i][j] == '.')
				return true;
	return false;
}

int main(){
	freopen("A.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int cas= 1; cas <= t; cas++){
		for(int i= 1; i <= 4; i++)
			scanf("%s", mp[i]+1);
		if(checkWin('X')){
			printf("Case #%d: X won\n", cas);
			continue;
		}
		if(checkWin('O')){
			printf("Case #%d: O won\n", cas);
			continue;
		}
		if(checkEmpty()){
			printf("Case #%d: Game has not completed\n", cas);
			continue;
		}
		printf("Case #%d: Draw\n", cas);
	}
	return 0;
}