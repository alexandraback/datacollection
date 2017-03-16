#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

ofstream fout ("Csmall.out");
ifstream fin ("Csmall.in");

int T;
int r,c,m;
char b[55][55];

void print() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) fout << b[i][j];
		fout << '\n';
	}
}

int main() {
	fin >> T;
	for (int tc = 1; tc <= T; tc++) {
		fout << "Case #" << tc << ":\n";
		fin >> r >> c >> m;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) b[i][j] = '*';
		
		if (m == r*c - 1) {
			b[0][0] = 'c';
			print();
			continue;
		}
		
		int ct = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (i == r-1 && j == c-1) b[i][j] = 'c';
				else if (ct >= m) b[i][j] = '.';
				else if (i >= r-2 && j >= c-2) b[i][j] = '.';
				else ct++;
			}
		}
		if (ct >= m) print();
		else fout << "Impossible\n";
	}
    return 0;
}