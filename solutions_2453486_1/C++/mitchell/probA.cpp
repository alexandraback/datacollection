#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <utility>
#include <cmath>
#include <list>
#include <map>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
bool winX(char a, char b, char c, char d){
	if(a == '.' || b == '.' || c == '.' || d == '.' || a == 'O' || b == 'O' || c == 'O' || d == 'O'){
		return false;
	}
	return ((int)(a == 'X')) + ((int)(b == 'X')) + ((int)(c == 'X')) + ((int)(d == 'X')) >= 3;
}
bool winY(char a, char b, char c, char d){
	if(a == '.' || b == '.' || c == '.' || d == '.' || a == 'X' || b == 'X' || c == 'X' || d == 'X'){
		return false;
	}
	return ((int)(a == 'O')) + ((int)(b == 'O')) + ((int)(c == 'O')) + ((int)(d == 'O')) >= 3;
}
char x[4][4];
int main(){
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		bool empty = false;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				cin >> x[i][j];
				empty |= (x[i][j] == '.');
			}
		}
		if(winX(x[0][0], x[1][0], x[2][0], x[3][0]) || winX(x[0][1], x[1][1], x[2][1], x[3][1]) || winX(x[0][2], x[1][2], x[2][2], x[3][2]) || winX(x[0][3], x[1][3], x[2][3], x[3][3])
		|| winX(x[0][0], x[0][1], x[0][2], x[0][3]) || winX(x[1][0], x[1][1], x[1][2], x[1][3]) || winX(x[2][0], x[2][1], x[2][2], x[2][3]) || winX(x[3][0], x[3][1], x[3][2], x[3][3])
		|| winX(x[0][0], x[1][1], x[2][2], x[3][3]) || winX(x[3][0], x[2][1], x[1][2], x[0][3]) ){
			cout << "Case #" << (t+1) << ": X won" << endl;
			continue;
		}
		if(winY(x[0][0], x[1][0], x[2][0], x[3][0]) || winY(x[0][1], x[1][1], x[2][1], x[3][1]) || winY(x[0][2], x[1][2], x[2][2], x[3][2]) || winY(x[0][3], x[1][3], x[2][3], x[3][3])
		|| winY(x[0][0], x[0][1], x[0][2], x[0][3]) || winY(x[1][0], x[1][1], x[1][2], x[1][3]) || winY(x[2][0], x[2][1], x[2][2], x[2][3]) || winY(x[3][0], x[3][1], x[3][2], x[3][3])
		|| winY(x[0][0], x[1][1], x[2][2], x[3][3]) || winY(x[3][0], x[2][1], x[1][2], x[0][3]) ){
			cout << "Case #" << (t+1) << ": O won" << endl;
			continue;
		}
		if(empty){
			cout << "Case #" << (t+1) << ": Game has not completed" << endl;
		} else {
			cout << "Case #" << (t+1) << ": Draw" << endl;
		}
	}
	return 0;
}
