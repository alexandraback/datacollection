#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>

using namespace std;

int main () {
	int tests;
	int M, R, C;

	ifstream fin;
	ofstream fout;

	fin.open("C.in");
	fout.open("C.out");

	fin>>tests;

	char field[50][50];

	for (int i=0; i<50; i++){
		for (int j=0; j<50; j++){
			field[i][j] = '.';
		}
	}

	for (int test=1; test<=tests; test++) {
		fin>>R>>C>>M;

		if (R == 1) {
			fout<<"Case #"<<test<<":\n";
			for (int l=0; l<M; l++)
				fout<<"*";
			if (C-M>1) {
				for (int l=0; l<C-M-1; l++)
					fout<<".";
				fout<<"c\n";
			}
			else
				fout<<"c\n";
		}
		else if (C == 1) {
			fout<<"Case #"<<test<<":\n";
			for (int l=0; l<M; l++)
				fout<<"*\n";
			if (R-M>1) {
				for (int l=0; l<R-M-1; l++)
					fout<<".\n";
				fout<<"c\n";
			}
			else
				fout<<"c\n";
		}

		else {
			int minesLeft = M;
			int currentNRows = R;
			int currentNColumns = C;
			int currentRow = 0;
			int currentColumn = 0;

			bool solution = true;

			while (minesLeft>0 && solution) {
				bool rowMax = currentNRows>currentNColumns;

//				cout<<minesLeft<<" "<<currentNRows<<" "<<currentNColumns<<endl;

				if ((minesLeft == 1 || minesLeft == 2) && (currentNRows == 2 && currentNColumns == 2)) {
					solution = false;
				}
				else if (minesLeft == 1 && ((currentNRows == 2) || (currentNColumns == 2))){
					solution = false;
				}
				else if (minesLeft == 3 && (currentNRows == 2 && currentNColumns == 2)) {
					field[currentRow][currentColumn] = '*';
					field[currentRow][currentColumn+1] = '*';
					field[currentRow+1][currentColumn] = '*';
					field[currentRow+1][currentColumn+1] = 'c';
					minesLeft = 0;
				}
				else if (minesLeft == 2 && currentNRows == 3 && currentNColumns == 3) {
					solution = false;
				}
				else if (rowMax && minesLeft - currentNColumns>=0) {
					for (int i=0; i<currentNColumns; i++) {
						field[currentRow][currentColumn + i] = '*';
					}
					minesLeft -= currentNColumns;
					currentNRows--;
					currentRow++;
				}
				else if (!rowMax && minesLeft - currentNRows>=0) {
					for (int i=0; i<currentNRows; i++)
						field[currentRow + i][currentColumn] = '*';
					minesLeft -= currentNRows;
					currentNColumns--;
					currentColumn++;
				}
				else if (rowMax && minesLeft - currentNColumns<0) {
					if (currentNColumns - minesLeft > 1) {
						for (int i=0; i<minesLeft; i++) {
							field[currentRow][currentColumn + i] = '*';
						}
						minesLeft = 0;
					}
					else {
						if (currentNRows > 2) {
							for (int i=0; i<minesLeft-1; i++) {
								field[currentRow][currentColumn + i] = '*';
							}
							field[currentRow + 1][currentColumn] = '*';
							minesLeft = 0;
						}
						else {
							solution = false;
						}
					}
				}
				else if (!rowMax && minesLeft - currentNRows <0) {
					if (currentNRows - minesLeft > 1) {
						for (int i=0; i<minesLeft; i++)
							field[currentRow + i][currentColumn] = '*';
						minesLeft = 0;
					}
					else {
						if (currentNRows > 2) {
							for (int i=0; i<minesLeft - 1; i++)
								field[currentRow + i][currentColumn] = '*';
							field[currentRow][currentColumn + 1] = '*';
							minesLeft = 0;
						}
						else {
							solution = false;
						}
					}
				}
			}

			fout<<"Case #"<<test<<":"<<endl;
			if (solution) {

				field[R-1][C-1] = 'c';
				for (int i=0; i<R; i++) {
					for (int j=0; j<C; j++) {
						fout<<field[i][j];
					}
					fout<<endl;
				}
			}
			else {
				fout<<"Impossible"<<endl;
			}

			for (int i=0; i<50; i++)
				for (int j=0; j<50; j++)
					field[i][j] = '.';
		}
	}

	fin.close();
	fout.close();

	return 0;
}
