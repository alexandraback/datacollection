// -------------------------------------
// Gherman Alin
// Google code jam 2014
// Minesweeper Master
// https://code.google.com/codejam/contest/2974486/dashboard#s=p2
//
// IDE: VC++ 2010
// OS Windows 7
// -------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#if defined WIN32 && defined _DEBUG
#include <cassert>
#define ASSERT(x) assert(x)
#define FAIL()    assert(false)
#else
#define ASSERT(x) 
#define FAIL()
#endif

typedef long long ll;

template<typename T> void swap( T& a, T& b ) { T temp = a; a = b; b = temp; }

int cmpIntsAsc(const void * a, const void * b) { return ( *(int*)a - *(int*)b ); }
int cmpIntsDesc(const void * a, const void * b) { return ( *(int*)b - *(int*)a ); }

inline void qsortIntsAsc(int* values, int n) { qsort(values, n, sizeof(int), cmpIntsAsc); }
inline void qsortIntsDesc(int* values, int n) { qsort(values, n, sizeof(int), cmpIntsDesc); }

void solve();

#define N 51
char matrix[N][N];

#ifdef _DEBUG
char matrixCheck[N][N];
#endif

FILE *f, *g, *g2;

int main(int argc, char** argv) {
	f = fopen("input.txt", "rt");
	g = fopen("output.txt", "wt");
	//g = stdout;

	g2 = fopen("impossible.txt", "wt");

	solve();

	fclose(f);
	fclose(g);
	fclose(g2);

	return 0;
}

void printSolution(int r, int c, int solutionRows, int solutionCols, int extraRow, int extraCol) {
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			matrix[i][j] = '*';
		}
		matrix[i][c] = '\0';
	}

	for(int i=0; i<solutionRows; i++) {
		for(int j=0; j<solutionCols; j++) {
			matrix[i][j] = '.';
		}
	}
	matrix[0][0] = 'c';

	// --------------------- Extra column ------------------
	if(extraCol == 1) {
		matrix[0][0] = '*';
		matrix[0][1] = '.';
		matrix[0][2] = 'c';
		matrix[0][solutionCols] = '.';
		matrix[1][solutionCols] = '.';
	}
	else if(extraCol > 1) {
		for(int j=0; j<extraCol; j++) {
			matrix[j][solutionCols] = '.';
		}		
	}
	// ------------- Extra row ---------------------
	else if(extraRow == 1) {
		matrix[0][0] = '*';
		matrix[solutionRows-1][0] = 'c';
		matrix[solutionRows][0] = '.';
		matrix[solutionRows][1] = '.';
	}
	else if(extraRow > 1) {
		for(int i=0; i<extraRow; i++) {
			matrix[solutionRows][i] = '.';
		}
	}
}

inline bool isBomb(int x, int y) {
	return matrix[x][y] == '*';
}

void sweep(int r, int c, int x, int y) {
	if(matrixCheck[x][y] == '.' || x < 0 || y < 0 || x >= r || y >= c)
		return;

	bool canSweep = true;
	if(x > 0 && y > 0) {
		if(isBomb(x - 1, y - 1))
			canSweep = false;
	}
	if(x > 0) {
		if(isBomb(x - 1, y))
			canSweep = false;
	}
	if(y > 0) {
		if(isBomb(x, y - 1))
			canSweep = false;
	}
	if(x < r - 1 && y < c - 1) {
		if(isBomb(x + 1, y + 1))
			canSweep = false;
	}
	if(x < r - 1) {
		if(isBomb(x + 1, y))
			canSweep = false;
	}
	if(y < c - 1) {
		if(isBomb(x, y + 1))
			canSweep = false;
	}
	if(x > 0 && y < c - 1) {
		if(isBomb(x - 1, y + 1))
			canSweep = false;
	}
	if(x < r - 1 && y > 0) {
		if(isBomb(x + 1, y - 1))
			canSweep = false;
	}
	
	if(!isBomb(x, y)) {
		matrixCheck[x][y] = '.';
	}
	if(canSweep) {
		sweep(r, c, x - 1, y - 1);
		sweep(r, c, x - 1, y);
		sweep(r, c, x, y - 1);
		sweep(r, c, x + 1, y + 1);
		sweep(r, c, x + 1, y);
		sweep(r, c, x, y + 1);
		sweep(r, c, x - 1, y + 1);
		sweep(r, c, x + 1, y - 1);
	}

}

int check(int r, int c, int m) {
#ifdef _DEBUG

	int x, y;
	int nC = 0;
	int nO = 0;
	int nP = 0;
	int nS = 0;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(matrix[i][j] == '.')
				nP ++;
			else if(matrix[i][j] == '*')
				nS ++;
			else if(matrix[i][j] == 'c') {
				nC ++;
				x = i;
				y = j;
			}
			else
				nO ++;
		}
	}

	if(nC != 1 || nO > 0 || nS != m || (nC + nP != r * c - m)) {
		// Error
		FAIL();
		return -1;
	}

	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			matrixCheck[i][j] = '*';
		}
	}
	sweep(r, c, x, y);
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(isBomb(i, j) && matrixCheck[i][j] == '.') {
				FAIL();
			}
			else if(!isBomb(i, j) && matrixCheck[i][j] == '*') {
				FAIL();
			}
		}
	}
	
#endif
	return 0;
}

inline bool isValid4(int r, int c, int fillR, int fillC, int extraCellsR, int extraCellsC) {
	if(extraCellsR == 0 && extraCellsC == 0) {
		return fillR >= 2 && fillC >= 2;
	}
	else if(extraCellsR == 1) {
		return fillR < r && fillR > 3 && fillC > 2;
	}
	else if(extraCellsC == 1) {
		return fillC < c && fillR > 2 && fillC > 3;
	}
	else if(extraCellsR > 1) {
		return fillR < r && extraCellsR < fillC && fillR>= 2 && fillC >= 2;
	}
	else if(extraCellsC > 1) {
		return fillC < c && extraCellsC < fillR && fillR>= 2 && fillC >= 2;
	}
	FAIL();
}

inline int bestRectangle(int r, int c, int area, int& outR, int& outC) {
	outR = 2;
	outC = 2;
	int newArea = outC * outR;

	while(newArea < area && outR < r && outC < c) {
		if(outC < outR) {
			newArea += outC;
			outR++;
		}
		else {
			newArea += outR;
			outC++;
		}
	}

	if(newArea > area) {
		if(outC < outR) {
			newArea -= outC;
			outR--;
		}
		else {
			newArea -= outR;
			outC--;
		}
	}

	if(newArea != area) {
		int l = (int) floor(sqrt((float) area));
		int rest = area - l*l;
		if(l <= r && l <= c && rest < l) {
			outR = outC = l;
			newArea = l*l;
		}
	}
	
	return newArea;
}

void solve() {
	const char * impossible = "Impossible";

	int problemCount;

	int r, c, m;
	int area;
	int emptyCells;
	int extraCellsR, extraCellsC, fillR, fillC;
	int bestEmptyCells;
	bool canWin;
	
	fscanf(f,"%d", &problemCount);
	for(int problemIdx = 1; problemIdx <= problemCount; problemIdx++) {
		fscanf(f,"%d", &r);
		fscanf(f,"%d", &c);
		fscanf(f,"%d", &m);
		fprintf(g,"Case #%d:\n", problemIdx);

		area = r * c;
		emptyCells = area - m;
		canWin = false;
		bestEmptyCells = -1;
		
		if(m == 0) {
			canWin = true; // Can win
			printSolution(r, c, r, c, 0, 0);
		}
		else if(emptyCells == 1) {
			canWin = true; // Can win
			printSolution(r, c, 1, 1, 0, 0);
		}
		else if(r == 1 || c == 1) {
			// Special case 1
			canWin = true; // Can win
			if(r == 1) {
				printSolution(r, c, 1, emptyCells, 0, 0);
			}
			else {
				printSolution(r, c, emptyCells, 1, 0, 0);
			}
		}
		else if(r == 2 || c == 2) {
			// Special case 2
			if(emptyCells >= 4 && emptyCells % 2 == 0) {
				canWin = true; // Can win
				if(r == 2) {
					printSolution(r, c, 2, emptyCells / 2, 0, 0);
				}
				else {
					printSolution(r, c, emptyCells / 2, 2, 0, 0);
				}
			}
		}
		else {
			// The general case, r > 2 && c > 2
			if(emptyCells >= 4) {

				// This has to be changed for the general case (r,c ~ 50)
				if(m == 3 && r > 3 && c > 3) {
					canWin = true;
					printSolution(r, c, r, c, 0, 0);
					matrix[0][0] = '*';
					matrix[1][0] = '*';
					matrix[0][1] = '*';
					matrix[2][2] = 'c';
				}

				if(!canWin) {
					// Chech the fill factor for rows
					fillR = r;
					fillC = emptyCells / r;
					extraCellsR = 0;
					extraCellsC = emptyCells % r;
					if(isValid4(r, c, fillR, fillC, extraCellsR, extraCellsC)) {
						canWin = true; // Can win
						printSolution(r, c, fillR, fillC, extraCellsR, extraCellsC);
					}
				}

				if(!canWin) {
					// Check the fill factor for columns
					fillR = emptyCells / c;
					fillC = c;
					extraCellsR = emptyCells % c;
					extraCellsC = 0;
					if(isValid4(r, c, fillR, fillC, extraCellsR, extraCellsC)) {
						canWin = true; // Can win
						printSolution(r, c, fillR, fillC, extraCellsR, extraCellsC);
					}
				}

				if(!canWin) {
					// Chech the fill factor for rows
					bestEmptyCells = bestRectangle(r, c, emptyCells, fillR, fillC);

					extraCellsR = 0;
					extraCellsC = emptyCells - bestEmptyCells;
					if(isValid4(r, c, fillR, fillC, extraCellsR, extraCellsC)) {
						canWin = true; // Can win
						printSolution(r, c, fillR, fillC, extraCellsR, extraCellsC);
					}
					if(!canWin) {
						extraCellsR = emptyCells - bestEmptyCells;
						extraCellsC = 0;
						if(isValid4(r, c, fillR, fillC, extraCellsR, extraCellsC)) {
							canWin = true; // Can win
							printSolution(r, c, fillR, fillC, extraCellsR, extraCellsC);
						}
					}


				}
			}
		}

		if(!canWin && r > 3 && c > 3) {
			// This is how I should have implemented the entire stuff, 
			// but I already submited the small solution, so this will have to do as a "dirty" fix.
			fillR = fillC = (int)floor(sqrt((float)emptyCells));
			if(fillR < r && fillC < c) {
				// There is hope
				while(!canWin && fillC >= 3 && fillR >= 3) {
					bestEmptyCells = fillR * fillC;
					extraCellsR = emptyCells - bestEmptyCells;
					extraCellsC = 0;
					if(extraCellsR > bestEmptyCells) {
						// No hope
						break;
					}
					else if(extraCellsR < fillR) {
						canWin = true;
						// put all the elements on the side
						printSolution(r, c, fillR, fillC, extraCellsR, extraCellsC);
						break;
					}
					else {
						int reps = extraCellsR / fillR;
						int rest = extraCellsR % fillR;

						if(rest != 1 || reps > 0) {
							printSolution(r, c, fillR, fillC, 0, 0);
							while(reps > 0 && fillR < r) {
								for(int j=0; j<fillC; j++) {
									matrix[fillR][j] = '.';
								}
								fillR++;
								reps--;
							}
							if(rest > 1 && fillR < r) {
								for(int j=0; j<rest; j++) {
									matrix[fillR][j] = '.';
								}
								rest = 0;
							}
							else if(rest == 1) {
								// delete one and add it to the rest
								matrix[fillR - 1][fillC - 1] = '*';
								rest = 2;
							}
							fillR = fillC;
							while(reps > 0 && fillC < c) {
								for(int i=0; i<fillR; i++) {
									matrix[i][fillC] = '.';
								}
								fillC++;
								reps--;
							}
							if(rest > 1 && fillC < c) {
								for(int i=0; i<rest; i++) {
									matrix[i][fillC] = '.';
								}
								rest = 0;
							}
							fillC = fillR;

							if(reps == 0 && rest == 0) {
								canWin = true;
							}
						}
						break;
					}
					fillR --;
					fillC --;
				}
			}
			else {
				// The other cases are covered above, I don't have time to rewrite it in a better way...
			}
		}

		// Impossible
		if(!canWin) {
			fprintf(g,"%s\n", impossible);
			fprintf(g2, "Case #%d: %d %d %d\n", problemIdx, r, c, m);
		}
		else {
			for(int i=0; i<r; i++) {
				fprintf(g,"%s\n", matrix[i]);
			}
			//check(r, c, m);
		}
	}
	
}