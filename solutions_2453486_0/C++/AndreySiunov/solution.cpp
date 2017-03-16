#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

char charO='O', charX='X';
char a[4][4];

bool diagonalWin(char c){
	{
		bool pp=1;
		for (int j=0;j<4;j++){
			if (a[j][j]!=c && a[j][j]!='T'){
				pp=false;
			}
		}
		if (pp){
			return true;
		}
	}

	{
		bool pp=1;
		for (int j=0;j<4;j++){
			if (a[3-j][j]!=c && a[3-j][j]!='T'){
				pp=false;
			}
		}
		if (pp){
			return true;
		}
	}
}

bool rowWin(char c, int rowN){
	bool pp=1;
	for (int j=0;j<4;j++){
		if (a[rowN][j]!=c && a[rowN][j]!='T'){
			pp=false;
		}
	}
	return pp;
}

bool columnWin(char c, int columnN){
	bool pp=1;
	for (int j=0;j<4;j++){
		if (a[j][columnN]!=c && a[j][columnN]!='T'){
			pp=false;
		}
	}
	return pp;
}

string solve(){
	bool hasPoint=false;
	for (int i=0;i<4;i++){
		for (int j=0;j<4;j++){
			cin>>a[i][j];
			if (a[i][j]=='.'){
				hasPoint=true;
			}
		}
	}
	bool oWin=diagonalWin(charO);
	bool xWin=diagonalWin(charX);
	for (int i=0;i<4;i++){
		oWin=oWin||rowWin(charO,i)||columnWin(charO,i);
		xWin=xWin||rowWin(charX,i)||columnWin(charX,i);
	}

	if (oWin){
		return "O won";
	}
	if (xWin){
		return "X won";
	}
	if (hasPoint){
		return "Game has not completed";
	}
	return "Draw";
}

int main(){
	freopen("input.txt","rt", stdin);
	freopen("output.txt","wt", stdout);
	int t;
	cin>>t;
	for (int i=1;i<=t;i++){
		cout<<"Case #"<<i<<": "<<solve()<<'\n';
	}
	return 0;
}