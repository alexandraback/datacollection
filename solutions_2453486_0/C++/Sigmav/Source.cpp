#define _CRT_SECURE_NO_DEPRECATE
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <map>
#include <list>
#include <sstream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <iomanip>
#include <queue>
#include <set>	
#include <cstring>
using namespace std;
typedef long long		ll;
typedef pair<int, int>	ii;
typedef pair<ii, int>	iii;
typedef vector<ii>		vii;
typedef vector<iii>		viii;
typedef vector<int>		vi;
typedef vector<char>	vc;
typedef vector<vc>		vvc;
typedef vector<string>	vs;
typedef unsigned long	ul;
typedef vector<ul>		vul;
typedef vector<bool>	vb;
typedef vector<vi>		vvi;
typedef vector<vii>		vvii;
typedef vector<double>	vd;
#define INF 1000000000
#define PI 3.14159265

bool isWon(char X,char a, char b, char c, char d){
	int countX = 0;
	bool isT = false;
	if (X==a) countX ++;
	if (X==b) countX ++;
	if (X==c) countX ++;
	if (X==d) countX ++;
	isT = a=='T' || b=='T' || c=='T' || d=='T';
	return countX == 4 || (countX==3 && isT);
}



int main(int argc, char *argv[]){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	char board[4][4] = {{'.','.','.','.'},{'.','.','.','.'},{'.','.','.','.'},{'.','.','.','.'}};
	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		bool boardComplete = true;
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++) {
				cin >> board[i][j];
				if (board[i][j]=='.') boardComplete = false;
			}
		}
		bool xWon = false;
		bool oWon = false;
		for (int i=0; i<4; i++) {
			xWon = xWon || isWon('X',board[i][0],board[i][1],board[i][2],board[i][3]);
			xWon = xWon || isWon('X',board[0][i],board[1][i],board[2][i],board[3][i]);
			oWon = oWon || isWon('O',board[i][0],board[i][1],board[i][2],board[i][3]);
			oWon = oWon || isWon('O',board[0][i],board[1][i],board[2][i],board[3][i]);
		}
		// diag
		xWon = xWon || isWon('X',board[0][0],board[1][1],board[2][2],board[3][3]);
		xWon = xWon || isWon('X',board[0][3],board[1][2],board[2][1],board[3][0]);
		oWon = oWon || isWon('O',board[0][0],board[1][1],board[2][2],board[3][3]);
		oWon = oWon || isWon('O',board[0][3],board[1][2],board[2][1],board[3][0]);

		cout << "Case #" << t << ": ";
		if (xWon) 
			cout << "X won";
		else if (oWon)
			cout << "O won";
		else if (boardComplete)
			cout << "Draw";
		else 
			cout << "Game has not completed";
		cout << endl;
	}


	return EXIT_SUCCESS;
}