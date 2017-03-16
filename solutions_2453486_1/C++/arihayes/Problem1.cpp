#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char ** argv) {
	unsigned char field[4][4];
	int numCases;
	
	cin >> numCases;
	for(int c = 0; c < numCases; c++) {
		bool filled = true;
		bool xwon = false;
		bool ywon = false;
		char state;
		
		for(int x = 0; x < 4; x++) {
			cin >> field[x][0];
			state = field[x][0];
			if(field[x][0] == '.') {
				filled = false;
			}
			
			for(int y = 1; y < 4; y++) {
				cin >> field[x][y];
				if(field[x][y] == '.') {
					filled = false;
					state = '.';
				}
				else if(state != '.') {
					if(state == 'T') {
						state = field[x][y];
					}
					else if(field[x][y] == 'T') {
						//nothing to do
					}
					else if(state != field[x][y]) {
						state = '.';
					}
				}
			}
			
			if(state == 'x' || state == 'X') {
				xwon = true;
			}
			else if(state == 'o' || state == 'O') {
				ywon = true;
			}
		}
		
		if(!(ywon || xwon)) {
			for(int y = 0; y < 4; y++) {
				state = field[0][y];
				
				for(int x = 1; x < 4; x++) {
					if(field[x][y] == '.') {
						state = '.';
					}
					else if(state != '.') {
						if(state == 'T') {
							state = field[x][y];
						}
						else if(field[x][y] == 'T') {
							//nothing to do
						}
						else if(state != field[x][y]) {
							state = '.';
						}
					}
				}
			
				if(state == 'x' || state == 'X') {
					xwon = true;
				}
				else if(state == 'o' || state == 'O') {
					ywon = true;
				}
			}
			
			state = field[0][0];
			for(int x = 1; x < 4; x++) {
				if(field[x][x] == '.') {
					state = '.';
				}
				else if(state != '.') {
					if(state == 'T') {
						state = field[x][x];
					}
					else if(field[x][x] == 'T') {
						//nothing to do
					}
					else if(state != field[x][x]) {
						state = '.';
					}
				}
			}
			if(state == 'x' || state == 'X') {
				xwon = true;
			}
			else if(state == 'o' || state == 'O') {
				ywon = true;
			}
			
			state = field[0][3];
			for(int x = 1; x < 4; x++) {
				if(field[x][3-x] == '.') {
					state = '.';
				}
				else if(state != '.') {
					if(state == 'T') {
						state = field[x][3-x];
					}
					else if(field[x][3-x] == 'T') {
						//nothing to do
					}
					else if(state != field[x][3-x]) {
						state = '.';
					}
				}
			}
			if(state == 'x' || state == 'X') {
				xwon = true;
			}
			else if(state == 'o' || state == 'O') {
				ywon = true;
			}
		}
		
		cout << "Case #" << (c+1) << ": ";
		if(xwon) {
			cout << "X won\n";
		}
		else if(ywon) {
			cout << "O won\n";
		}
		else if(filled) {
			cout << "Draw\n";
		}
		else {
			cout << "Game has not completed\n";
		}
	}
}
