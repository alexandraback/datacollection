#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

char c[5][5];

bool isWin(char ch){
	
	for(int i=0;i<4;i++){
		int cnt = 0;
		for(int j=0;j<4;j++){
			cnt = cnt + (c[i][j] == ch) + (c[i][j] == 'T'); 
		}
		if(cnt==4)
			return true;
	}

	for(int i=0;i<4;i++){
		int cnt = 0;
		for(int j=0;j<4;j++){
			cnt = cnt + (c[j][i] == ch) + (c[j][i] == 'T'); 
		}
		if(cnt==4)
			return true;
	}

	int cnt = 0;
	for(int j=0,i=0;j<4;j++,i++){
		cnt = cnt + (c[i][j] == ch) + (c[i][j] == 'T'); 
	}
	if(cnt==4)
		return true;

	cnt = 0;
	for(int j=0,i=3;j<4;j++,i--){
		cnt = cnt + (c[i][j] == ch) + (c[i][j] == 'T'); 
	}
	if(cnt==4)
		return true;
		
	return false;
}

bool isComplete(){
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(c[i][j]=='.')
				return false;
	return true;
}

int sol(){
	for(int i=0;i<4;i++)
		cin >> c[i];
	if(isWin('X'))
		cout << "X won";
	else if(isWin('O'))
		cout << "O won";
	else if(isComplete())
		cout << "Draw";
	else
		cout << "Game has not completed";
}

int main(){
	int t=0;
	cin >> t;
	for(int i=1;i<=t;i++){
		cout << "Case #"<<i<< ": ";
		sol();
		cout<<endl;
	}		
}
