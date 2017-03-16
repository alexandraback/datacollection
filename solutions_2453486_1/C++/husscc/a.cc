#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <unordered_map>

using namespace std;
#define REP1(i,n) for((i)=1;(i)<(int)(n);(i)++)
#define REP0(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define RITR(c,itr) for(__typeof((c).begin()) itr=(c).begin();(itr)!=(c).end();(itr)++)

int T;
char board[4][4];

string solve(){
	int i, j, k = 0, X, O, T;
	REP0(i, 4){
		X = 0, O = 0, T = 0;
		REP0(j, 4){
			if(board[i][j] == 'X') X++;
			else if(board[i][j] == 'O') O++;
			else if(board[i][j] == 'T') T++;
			else{k++; break;}
		}
		if(X+T == 4) return "X won";
		else if(O+T == 4) return "O won";
	}	
	REP0(i, 4){
		X = 0, O = 0, T = 0;
		REP0(j, 4){
			if(board[j][i] == 'X') X++;
			else if(board[j][i] == 'O') O++;
			else if(board[j][i] == 'T') T++;
			else{k++; break;}
		}
		if(X+T == 4) return "X won";
		else if(O+T == 4) return "O won";
	}
	X = 0, O = 0, T = 0;
	REP0(i, 4){
		if(board[i][i] == 'X') X++;
		else if(board[i][i] == 'O') O++;
		else if(board[i][i] == 'T') T++;
		else{k++; break;}
	}	
	if(X+T == 4) return "X won";
	else if(O+T == 4) return "O won";
	X = 0, O = 0, T = 0;
	REP0(i, 4){
		if(board[i][3-i] == 'X') X++;
		else if(board[i][3-i] == 'O') O++;
		else if(board[i][3-i] == 'T') T++;
		else{k++; break;}
	}
	if(X+T == 4) return "X won";
	else if(O+T == 4) return "O won";
	else if(k > 0) return "Game has not completed";
	else return "Draw";
}

int main(){
	int i, j, k; 
	string str;
	cin>> T;
	REP1(i, T+1){
		REP0(j, 4){
			cin>>str;
			REP0(k, 4)
				board[j][k] = str[k];
		}
		cout<<"Case #"<<i<<": "<<solve()<<endl;
	}
}