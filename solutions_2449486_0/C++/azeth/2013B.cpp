// 2013B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

bool test(int n, int m, int **board);
bool check(int x, int n, int *line);

int _tmain(int argc, _TCHAR* argv[])
{
	ios_base::sync_with_stdio(false);

	ifstream in("B.in");
	ofstream out("B.out");

	int t;
	in >> t;

	for (int c = 1; c <= t; c++) {
		int n, m;
		in >> n >> m;

		int **board = new int*[n];
		for (int i = 0; i < n; i++) {
			board[i] = new int[m];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				in >> board[i][j];
			}
		}

		bool res = test(n, m, board);

		out << "Case #" << c << ": ";
		if (res == true) {
			out << "YES";
		} else {
			out << "NO";
		}
		out << endl;

		for (int i = 0; i < n; i++) {
			delete [] board[i];
		}
		delete [] board;
	}

	return 0;
}

bool test(int n, int m, int **board)
{
	int **row_res = new int*[n];
	for (int i = 0; i < n; i++) {
		row_res[i] = new int[m];
	}

	int **col_res = new int*[n];
	for (int i = 0; i < n; i++) {
		col_res[i] = new int[m];
	}

	for (int i = 0; i < n; i++) {
		// prepare row to check
		int *row = new int[m];
		for (int j = 0; j < m; j++) {
			row[j] = board[i][j];
		}

		// check row
		for (int j = 0; j < m; j++) {
			row_res[i][j] = check(j, m, row);
		}
	}

	for (int i = 0; i < m; i++) {
		// prepare col to check
		int *col = new int[n];
		for (int j = 0; j < n; j++) {
			col[j] = board[j][i];
		}

		// check col
		for (int j = 0; j < n; j++) {
			col_res[j][i] = check(j, n, col);
		}
	}

	bool res = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!(row_res[i][j] == true || col_res[i][j] == true)) {
				res = false;
				break;
			}
		}

		if (res == false) {
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		delete [] col_res[i];
	}
	delete [] col_res;

	for (int i = 0; i < n; i++) {
		delete [] row_res[i];
	}
	delete [] row_res;

	return res;
}

bool check(int x, int n, int *line)
{
	// check left
	int e = line[x];
	for (int i = x-1; i >= 0; i--) {
		if (line[i] > e) {
			return false;
		}
	}

	// check right
	for (int i = x+1; i < n; i++) {
		if (line[i] > e) {
			return false;
		}
	}

	return true;
}
