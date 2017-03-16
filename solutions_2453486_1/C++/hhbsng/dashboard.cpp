#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	int tstNum, tstCount;
	int pos;
	int b[4][4];
	char c;
	bool finish;

	ifstream fin("dashboard.in", ios::in);
	
	fin >> tstNum;
	tstCount = tstNum;
	while(tstCount--) {
		pos = 0; finish = true;
		while(fin.get(c) && pos < 16) {
			switch (c) {
				case 'X':
					b[pos / 4][pos % 4] = 2; ++pos;
					break;
				case 'O':
					b[pos / 4][pos % 4] = 100; ++pos;
					break;
				case 'T':
					b[pos / 4][pos % 4] = 1; ++pos;
					break;
				case '.':
					b[pos / 4][pos % 4] = 0; ++pos;
					finish = false;
					break;
			}
		}

		bool flag = false; bool xwin = false;
		int point;
		for(int i = 0; i < 4 && !flag; ++i) {
			point = 0;
			for(int j = 0; j < 4; ++j) point += b[i][j];
			if(point == 301 || point == 400) {
				flag = true; xwin = false;
			} else if(point == 7 || point == 8) {
				flag = true; xwin = true;
			}
		}

		for(int i = 0; i < 4 && !flag; ++i) {
			point = 0;
			for(int j = 0; j < 4; ++j) point += b[j][i];
			if(point == 301 || point == 400) {
				flag = true; xwin = false;
			} else if(point == 7 || point == 8) {
				flag = true; xwin = true;
			}
		}

		if(!flag) {
			point = 0;
			for(int j = 0; j < 4; ++j) point += b[j][j];
			if(point == 301 || point == 400) {
				flag = true; xwin = false;
			} else if(point == 7 || point == 8) {
				flag = true; xwin = true;
			}
		}

		if(!flag) {
			point = 0;
			for(int j = 0; j < 4; ++j) point += b[j][3 - j];
			if(point == 301 || point == 400) {
				flag = true; xwin = false;
			} else if(point == 7 || point == 8) {
				flag = true; xwin = true;
			}
		}

		ofstream fout("dashboard.out", ios::app);
		fout << "Case #" << tstNum - tstCount << ": ";
		if(flag) {
			if(xwin) fout << "X won" << endl;
			else fout << "O won" << endl;
		} else {
			if(finish) fout << "Draw" << endl;
			else fout << "Game has not completed" << endl;
		}
		fout.close();
	}
	fin.close();
	return 0;
}
