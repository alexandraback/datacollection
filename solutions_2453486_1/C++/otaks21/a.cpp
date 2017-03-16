#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

string s[4];

bool row(int y, char c){
	for(int x = 0; x < 4; x++){
		if( s[y][x] != c && s[y][x] != 'T' ){
			return false;
		}
	}
	return true;
}

bool col(int x, char c){
	for(int y = 0; y < 4; y++){
		if( s[y][x] != c && s[y][x] != 'T' ){
			return false;
		}
	}
	return true;
}

bool obliqueness(char c){
	bool flag = true;
	for(int i = 0; i < 4; i++){
		if( s[i][i] != c && s[i][i] != 'T' ){
			flag = false;
		}
	}
	if( flag ) return true;
	for(int i = 0; i < 4; i++){
		if( s[3-i][i] != c && s[3-i][i] != 'T' ){
			return false;
		}
	}
	return true;
}

string solve(){
	for(int y = 0; y < 4; y++){
		if( row(y, 'X') ) return "X won";
		if( row(y, 'O') ) return "O won";
	}
	for(int x = 0; x < 4; x++){
		if( col(x, 'X') ) return "X won";
		if( col(x, 'O') ) return "O won";
	}
	if( obliqueness('X') ) return "X won";
	if( obliqueness('O') ) return "O won";
	
	int cnt = 0;
	for(int y = 0; y < 4; y++){
		for(int x = 0; x < 4; x++){
			if( s[y][x] != '.' ) cnt++;
		}
	}
	if( cnt == 16 ) return "Draw";
	return "Game has not completed";
}

int main(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		for(int i = 0; i < 4; i++) cin >> s[i];
		cout << "Case #" << t << ": " << solve() << endl;
	}
}
