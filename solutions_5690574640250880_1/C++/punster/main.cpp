#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>
#include "stdlib.h"
using namespace std;

#define mine '*'
#define clr '.'
#define clk 'c'

void print_board(char** board, int R, int C) {
	for (int i=0; i<R; ++i) {
		for (int j=0; j<C; ++j) {
			cout << board[i][j];
		}
		cout << endl;
	}
}
void nope() {
	cout << "Impossible" << endl;
}

void do_something() {
	int R,C,M;
//	char board [5][5];
	char **board;
	int empties;
	cin >> R >> C >> M;
	board = new char*[R];
	for (int i=0; i<R; ++i) {
		board[i] = new char[C];
	}
	empties = (R*C)-M;
	if ((R > 1) && (C > 1) && (empties > 1)) {
		if ((empties == 2) || (empties == 3) || (empties == 5) || (empties == 7)) {
			nope();	return;
		}
		if (((R==2) || (C==2)) && (empties & 0x1)) {
			nope(); return;
		}
	}
/*	if ((empties == 9) && (R>2) && (C>2)) {
		for (int i=0; i<R; ++i) {
			for (int j=0; j<C; ++j) {
				if ((i==0) && (j==0)) { board[i][j] = clk; continue;}
				if ((i<4) && (j<4)) { board[i][j] = clr; }
				else { board[i][j] = mine; }
			}
		}
	} else {*/
		for (int i=0; i<R; ++i) {
			int leave = 0;
			if ((i != (R-1)) && (M == (C-1))) { leave = 2; }
			if ((i == (R-3)) && (empties & 0x1) && (empties != 0x1)) { leave = 3; }
			if (i == (R-2)) { leave = empties/2; }
			for (int j=0; j<C; ++j) {
				if ((M == 0) || ((C-j) <= leave)) { 
					board[i][j] = clr; --empties;
				} else {
					board[i][j] = mine; --M;
				}
			}
		}
		board[R-1][C-1] = clk;
		if (M || empties) { cout << "ERROR: M=" << M << ";empties=" << empties << endl; } 
//	}
	
	print_board(board,R,C);
}

int main(int argc, char **argv)
{
	int tests;
	cin >> tests;

	for (int i=1; i <= tests; ++i) {
	  cout << "Case #" << i << ":\n";
	  do_something();
	}
	return 0;
}
