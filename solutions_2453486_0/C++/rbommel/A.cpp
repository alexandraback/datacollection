#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("A.in");
ofstream fout("A.out");

bool finished;
int N, winner;
string s;
char bord[4][4];

int main() {
	fin >> N;
	
	for (int i = 0; i < N; i++) {
	
	// Read board
		finished = true;
		winner = 0;
		for (int j = 0; j < 4; j++) {
			fin >> s;
			for (int k = 0; k < 4; k++) {
				bord[j][k] = s[k];
				if (s[k] == '.')
					finished = false;			
			}
		}
		
	// Check rows
		for (int j = 0; j < 4; j++) {
			if (((bord[j][0] == 'X') or (bord[j][0] == 'T')) and
				((bord[j][1] == 'X') or (bord[j][1] == 'T')) and
				((bord[j][2] == 'X') or (bord[j][2] == 'T')) and
				((bord[j][3] == 'X') or (bord[j][3] == 'T')))
				winner = 1;
			if (((bord[j][0] == 'O') or (bord[j][0] == 'T')) and
				((bord[j][1] == 'O') or (bord[j][1] == 'T')) and
				((bord[j][2] == 'O') or (bord[j][2] == 'T')) and
				((bord[j][3] == 'O') or (bord[j][3] == 'T')))
				winner = 2;				
		}
		
	// Check columns
		for (int j = 0; j < 4; j++) {
			if (((bord[0][j] == 'X') or (bord[0][j] == 'T')) and
				((bord[1][j] == 'X') or (bord[1][j] == 'T')) and
				((bord[2][j] == 'X') or (bord[2][j] == 'T')) and
				((bord[3][j] == 'X') or (bord[3][j] == 'T')))
				winner = 1;
			if (((bord[0][j] == 'O') or (bord[0][j] == 'T')) and
				((bord[1][j] == 'O') or (bord[1][j] == 'T')) and
				((bord[2][j] == 'O') or (bord[2][j] == 'T')) and
				((bord[3][j] == 'O') or (bord[3][j] == 'T')))
				winner = 2;				
		}
		
	// Check diagonals
			if (((bord[0][0] == 'X') or (bord[0][0] == 'T')) and
				((bord[1][1] == 'X') or (bord[1][1] == 'T')) and
				((bord[2][2] == 'X') or (bord[2][2] == 'T')) and
				((bord[3][3] == 'X') or (bord[3][3] == 'T')))
				winner = 1;
			if (((bord[0][0] == 'O') or (bord[0][0] == 'T')) and
				((bord[1][1] == 'O') or (bord[1][1] == 'T')) and
				((bord[2][2] == 'O') or (bord[2][2] == 'T')) and
				((bord[3][3] == 'O') or (bord[3][3] == 'T')))
				winner = 2;				
			if (((bord[0][3] == 'X') or (bord[0][3] == 'T')) and
				((bord[1][2] == 'X') or (bord[1][2] == 'T')) and
				((bord[2][1] == 'X') or (bord[2][1] == 'T')) and
				((bord[3][0] == 'X') or (bord[3][0] == 'T')))
				winner = 1;
			if (((bord[0][3] == 'O') or (bord[0][3] == 'T')) and
				((bord[1][2] == 'O') or (bord[1][2] == 'T')) and
				((bord[2][1] == 'O') or (bord[2][1] == 'T')) and
				((bord[3][0] == 'O') or (bord[3][0] == 'T')))
				winner = 2;				
		
		
	// Output winner
		fout << "Case #" << i+1 << ": ";
		if (winner == 1)
			fout << "X won\n";
		if (winner == 2)
			fout << "O won\n";
		if (winner == 0) {
			if (finished) {
				fout << "Draw\n"; }
			else {
				fout << "Game has not completed\n"; }
			}			
	}

	return 0;
}
