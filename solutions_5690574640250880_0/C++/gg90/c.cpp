#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cassert>
#include <utility>

using namespace std;

#define fori(i, n) for (int i = 0; i < int(n); i++)
#define forv(i, a) for (int i = 0; i < int(a.size()); i++)
#define fors(i, a) for (int i = 0; i < int(a.length()); i++)

#define output cout
//#define output outFile
//Minesweeper Master
int main(int argc, char** argv) {
	fstream file("qualification/files/inputCsmall.txt");
	/*	fstream outFile("qualification/outputC.txt",
	 ios_base::out | ios_base::trunc);*/
	int testCases;
	file >> testCases;
	int testCase = 1;
	while (testCases--) {
		int M, R, C;
		file >> R;
		file >> C;
		file >> M;
		int free = C * R - M;
		int requiredFree = 4;
		bool error = false;
		int** board = new int*[R];
		fori(i, R) {
			board[i] = new int[C];
			fori(z,C)
				board[i][z] = 2; //MINE
		}
		if (R == 1 && C == 1) {
			if (M == 1) {
				error = true;
			} else {
				board[0][0] = 1;
			}
		} else if (R == 1) {
			if (free == 0) {
				error = true;
			} else {
				fori(i, (C - M)) {
					board[0][i] = 0;
				}
				board[0][0] = 1;
			}
		} else if (C == 1) {
			if (free == 0) {
				error = true;
			} else {
				fori(i, (R - M)) {
					board[i][0] = 0;
				}
				board[0][0] = 1;
			}
		} else if (free == 1) {
			board[0][0] = 1;
		} else {
			if (free < 4 || free == 5 || free == 7) {
				error = true;
			} else {
				int tempFree = free - 4;
				board[0][0] = 1;
				board[1][1] = 0;
				board[1][0] = 0;
				board[0][1] = 0;
				int canBePutDown = (R - 2) * 2;
				if (tempFree) {
					if ((tempFree < canBePutDown && tempFree % 2 == 1)
							|| (tempFree - canBePutDown) == 1) {
						if (C < 3) {
							error = true;
						} else {
							tempFree -= 3;
							board[0][2] = 0;
							board[1][2] = 0;
							board[2][2] = 0;
							for (int i = 2; i < R; i++) {
								board[i][0] = 0;
								board[i][1] = 0;
								tempFree -= 2;
								if (tempFree == 0) {
									break;
								}
							}
						}
					} else if (tempFree <= canBePutDown) {
						for (int i = 2; i < R; i++) {
							board[i][0] = 0;
							board[i][1] = 0;
							tempFree -= 2;
							if (tempFree == 0) {
								break;
							}
						}
					} else {
						for (int i = 2; i < R; i++) {
							board[i][0] = 0;
							board[i][1] = 0;
							tempFree -= 2;
							if (tempFree == 0) {
								break;
							}
						}
						int currColumn = 2;
						while (tempFree) {
							if (tempFree == 3 && R == 2) {
								error = true;
								break;
							} else if (tempFree == R + 1) {
								fori(i, R - 1) {
									board[i][currColumn] = 0;
									tempFree--;
								}
								board[0][currColumn + 1] = 0;
								board[1][currColumn + 1] = 0;
								break;
							} else {
								fori(i, R) {
									board[i][currColumn] = 0;
									tempFree--;
									if (tempFree == 0) {
										break;
									}
								}
							}
							currColumn++;
						}
					}
				}

			}
		}
		output << "Case #" << testCase << ":" << endl;
		if (error) {
			output << "Impossible" << endl;
		} else {
			fori(y, R) {
				fori(x, C) {
					if (board[y][x] == 1) {
						output << "c";
					} else if (board[y][x] == 0) {
						output << ".";
					} else {
						output << "*";
					}
				}
				output << endl;
			}
		}

		testCase++;
	}
	return 0;
}
