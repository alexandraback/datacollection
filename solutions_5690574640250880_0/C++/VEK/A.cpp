#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

int min(int a, int b) {return (a<b)?a:b;}
int max(int a, int b) {return (a>b)?a:b;}

using namespace std;

unsigned int tesztDB;
unsigned w, h, mineNum, vacantNum;
char board[50][50];

int main(int argc, char **argv) {
	unsigned int i;
	ifstream ifile("C-small-attempt2.in");
	FILE *ofile = fopen("out.txt", "w");
	ifile >> tesztDB;
	for (i = 0; i < tesztDB; i++) {
		ifile >> h;
		ifile >> w;
		ifile >> mineNum;
		vacantNum = w*h-mineNum;
		if (w == 1) {
			board[0][0] = 'c';
			for (unsigned j = 1; j < h-mineNum; j++) board[0][j] = '.';
			for (unsigned j = h-mineNum; j < h; j++) board[0][j] = '*';
		} else if (h == 1) {
			board[0][0] = 'c';
			for (unsigned j = 1; j < w-mineNum; j++) board[j][0] = '.';
			for (unsigned j = w-mineNum; j < w; j++) board[j][0] = '*';
		} else if (vacantNum == 1) {
			for (unsigned x = 0; x < w; x++) {
				for (unsigned y = 0; y < h; y++) {
					board[x][y] = '*';
				}
			}
			board[0][0] = 'c';
		} //else if (vacantNum <= 3) board[0][0] = 'X';
		else {
			bool found = false;
			for (unsigned rWidth = min(w, vacantNum); rWidth >= 2; rWidth--) {
				for (unsigned rHeight = 2; rWidth*rHeight <= vacantNum && rHeight <= h; rHeight++) {
					//unsigned rHeight = vacantNum/rWidth;
					//if (i == 0) cout << rWidth << " " << rHeight << " " << vacantNum << endl;
					//if (rHeight > h) continue;
					unsigned rem = vacantNum-rWidth*rHeight;
					//if (rem+2 > rWidth+rHeight) continue;
					for (unsigned remY = 0; remY <= rem; remY++) {
						unsigned remX = rem-remY;
						if (remX >= rWidth || remY >= rHeight) continue;
						//if ((remX > 0 || remY > 0) && (rWidth < 2 || rHeight < 2)) continue;
						if (remX == 1 || remY == 1) continue;
						if (remX > 0 && rHeight == h) continue;
						if (remY > 0 && rWidth == w) continue;
						found = true;
						//if (i == 0) cout << rWidth << " " << rHeight << " " << remX << " " << remY << endl;
						for (unsigned x = 0; x < w; x++) {
							for (unsigned y = 0; y < h; y++) {
								if (x == 0 && y == 0) board[x][y] = 'c';
								else if (x < rWidth && y < rHeight) board[x][y] = '.';
								else if (y == rHeight && x < remX) board[x][y] = '.';
								else if (x == rWidth && y < remY) board[x][y] = '.';
								else board[x][y] = '*';
							}
						}
						goto loopEnd;
					}
				}
			}
			loopEnd:
			/*if (!found) {
				for (unsigned rHeight = min(h, vacantNum); rHeight >= 1; rHeight--) {
					unsigned rWidth = vacantNum/rHeight;
					//if (i == 0) cout << "|" << rWidth << " " << rHeight << " " << vacantNum << endl;
					if (rWidth > w) continue;
					unsigned rem = vacantNum-rWidth*rHeight;
					if (rem > 0 && (rWidth < 2 || rHeight < 2)) continue;
					if (rem == 1 || (rem > 0 && rWidth == w)) continue;
					found = true;
					for (unsigned x = 0; x < w; x++) {
						for (unsigned y = 0; y < h; y++) {
							if (x == 0 && y == 0) board[x][y] = 'c';
							else if (x < rWidth && y < rHeight) board[x][y] = '.';
							else if (x == rWidth && y < rem) board[x][y] = '.';
							else board[x][y] = '*';
						}
					}
					break;
				}
			}*/
			if (!found) board[0][0] = 'X';
		}
		fprintf(ofile, "Case #%d:\n", i+1);
		if (board[0][0] == 'X') fprintf(ofile, "Impossible\n");
		else {
			for (unsigned j = 0; j < h; j++) {
				for (unsigned k = 0; k < w; k++) fprintf(ofile, "%c", board[k][j]);
				fprintf(ofile, "\n");
			}
		}
	}
	ifile.close();
	fclose(ofile);
	return 0;
}
