#include <iostream>
#include <string>

using namespace std;

char data[10][10];

bool check(char x);

int main(){
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cout << "Case #" << (t+1) << ": ";
		for (int r = 0; r < 4; r++)
			cin >> data[r];
		cin.get();
		
		if (check('O'))
			cout << "O won" << endl;
		else if (check('X')) 
			cout << "X won" << endl;
		else {
			bool draw = true;
			for (int r = 0; r < 4; r++) {
				for (int c = 0; c < 4; c++) {
					if (data[r][c] == '.') {
						draw = false;
						break;
					}
				}
				if (draw == false) 
					break;
			}
			if (draw)
				cout << "Draw" << endl;
			else
				cout << "Game has not completed" << endl;
		}
	}
	
	return 0;
}

bool check(char x) {
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			if (data[r][c] != x && data[r][c] != 'T') 
				break;
			if (c == 3) return true;
		}
	}
	for (int c = 0; c < 4; c++) {
		for (int r = 0; r < 4; r++) {
			if (data[r][c] != x && data[r][c] != 'T') 
				break;
			if (r == 3) return true;
		}
	}
	for (int r = 0; r < 4; r++) {
		if (data[r][r] != x && data[r][r] != 'T') 
			break;
		if (r == 3) return true;
	}
	for (int r = 0; r < 4; r++) {
		if (data[r][3-r] != x && data[r][3-r] != 'T') 
			break;
		if (r == 3) return true;
	}
	return false;
}

