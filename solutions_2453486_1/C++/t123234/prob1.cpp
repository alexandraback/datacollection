#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char board[4][4];

int main(){
	int t, i, j, k;
	bool dt, d, x, o, f;
	cin >> t;
	for (i=0; i<t; ++i) {
		dt = false; f=false;
		for (j=0; j<4; ++j) {
			for (k=0; k<4; ++k) {
				cin>>board[j][k];
				if (board[j][k]=='.') {
					dt = true;
				}
			}
		}
		
		for (j=0; j<4; ++j) {
			x=false;o=false;d=false;
			for (k=0; k<4; ++k) {
				if (board[j][k]=='X') {
					x = true;
				} else if (board[j][k]=='O') {
					o = true;
				} else if (board[j][k]=='.') {
					d = true;
				}
			}
			if (!d && !x && o) {
				cout << "Case #" << (i+1) <<": "<<"O won"<<endl;
				f = true;
				break;
			} else if (!d && !o && x) {
				cout << "Case #" << (i+1) <<": "<<"X won"<<endl;
				f = true;
				break;
			}
		}
		if (f) continue;
		
		for (j=0; j<4; ++j) {
			x=false;o=false;d=false;
			for (k=0; k<4; ++k) {
				if (board[k][j]=='X') {
					x = true;
				} else if (board[k][j]=='O') {
					o = true;
				} else if (board[k][j]=='.') {
					d = true;
				}
			}
			if (!d && !x && o) {
				cout << "Case #" << (i+1) <<": "<<"O won"<<endl;
				f = true;
				break;
			} else if (!d && !o && x) {
				cout << "Case #" << (i+1) <<": "<<"X won"<<endl;
				f = true;
				break;
			}
		}
		if (f) continue;
		
		x=false;o=false;d=false;
		for (j=0; j<4; ++j) {
			if (board[j][j]=='X') {
				x = true;
			} else if (board[j][j]=='O') {
				o = true;
			} else if (board[j][j]=='.') {
				d = true;
			}
		}
		if (!d && !x && o) {
			cout << "Case #" << (i+1) <<": "<<"O won"<<endl;
			f = true;
		} else if (!d && !o && x) {
			cout << "Case #" << (i+1) <<": "<<"X won"<<endl;
			f = true;
		}
		if (f) continue;
		
		x=false;o=false;d=false;
		for (j=0; j<4; ++j) {
			if (board[j][3-j]=='X') {
				x = true;
			} else if (board[j][3-j]=='O') {
				o = true;
			} else if (board[j][3-j]=='.') {
				d = true;
			}
		}
		if (!d && !x && o) {
			cout << "Case #" << (i+1) <<": "<<"O won"<<endl;
			f = true;
		} else if (!d && !o && x) {
			cout << "Case #" << (i+1) <<": "<<"X won"<<endl;
			f = true;
		}
		if (f) continue;
		
		if(dt) cout << "Case #" << (i+1) <<": "<<"Game has not completed"<<endl;
		else cout << "Case #" << (i+1) <<": "<<"Draw"<<endl;
	}
	
	return 0;
}