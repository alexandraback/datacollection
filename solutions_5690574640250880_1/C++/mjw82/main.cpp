#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

//#define DEBUG

#ifdef DEBUG
#define DEBUG_PRINT(...) fprintf (stdout, __VA_ARGS__)
#else
#define DEBUG_PRINT(...)
#endif

#define MINE 10


void PrintMinefield(short pMinefield[50][50], short NbRows, short NbCols, bool covered) {
	
	for (short j = 0; j < NbRows; j++) {
		for (short i = 0; i < NbCols; i++) {		
			
			if (pMinefield[i][j] >= MINE) {
				cout << "*";
			} else {
				
				if (covered) {
					if (i == 0 && j == 0) {
						cout << "c";
					} else {
						cout << ".";					
					}
				} else {
					cout << pMinefield[i][j];
				}				
			}			
		}
		
		cout << endl;
		
	}
	
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		cerr << argv[0] << "filename" << endl;
		return 1;
	}
	
	ifstream InputFile (argv[1]);
	
	int NbTestCases = 0;
	
	if (!InputFile.is_open()) {
		cerr << "Could not open input file" << endl;
		return 1;
	}
	
	InputFile >> NbTestCases;
	
	DEBUG_PRINT("NbTestCases = %d\n", NbTestCases);
	
	short Minefield[50][50];
	
	short NbRows = 0;
	short NbColumns = 0;
	short NbMines = 0;
	short NbRemainingRows = 0;
	short NbRemainingColumns = 0;
	short NbRemainingMines = 0;

	for (int CurTestCase = 0; CurTestCase < NbTestCases; CurTestCase++) {
		
		cout << "Case #" << (CurTestCase+1) << ":" << endl;

		memset(Minefield, 0, sizeof(short) * 50 * 50);
		
		InputFile >> NbRows >> NbColumns >> NbMines;
		
		// Sanity checks:
		
		if (NbMines >= NbRows * NbColumns) {
			cout << "Impossible" << endl;
			continue;
		}

				
		// First phase: systematically reduce minefield
		
		NbRemainingRows = NbRows;
		NbRemainingColumns = NbColumns;
		NbRemainingMines = NbMines;
		
		while (NbRemainingMines >= min(NbRemainingColumns, NbRemainingRows)) {
			
			if (NbRemainingColumns < NbRemainingRows) {
				
				// more rows than columns. remove one row by putting mines. this needs nb columns mines.
				
				NbRemainingRows--;
				NbRemainingMines -= NbRemainingColumns;
				
				for (int cell = 0; cell < NbRemainingColumns; cell++) {
					Minefield[cell][NbRemainingRows] = MINE;
				}
				
			} else {
				
				// more columns than rows. remove one column by putting mines. this needs nb rows mines.
				
				NbRemainingColumns--;
				NbRemainingMines -= NbRemainingRows;
				
				for (int cell = 0; cell < NbRemainingRows; cell++) {
					Minefield[NbRemainingColumns][cell] = MINE;
				}
			}			
		}
		
		#ifdef DEBUG2
		cout << "AFTER PHASE 1:" << endl;
		DEBUG_PRINT("Number remaining mines   = %d (initial %d)\n", NbRemainingMines, NbMines);
		DEBUG_PRINT("Number remaining columns = %d (initial %d)\n", NbRemainingColumns, NbColumns);
		DEBUG_PRINT("Number remaining rows    = %d (initial %d)\n", NbRemainingRows, NbRows);
		PrintMinefield(Minefield, NbRows, NbColumns, false);
		#endif
		
		
		// Second phase: fill one remainder row/column (shorter of both) with max. possible number of mines
				
		if (NbRemainingMines >= 1) {
			if (NbRemainingColumns < NbRemainingRows) {
				
				NbRemainingRows--;
				
				for (int cell = NbRemainingColumns-1; cell > 1; cell--) {
					
					if (NbRemainingMines <= 0) {
						break;
					}
					NbRemainingMines--;
					
					Minefield[cell][NbRemainingRows] = MINE;						
				}
				
				
			} else {
				
				NbRemainingColumns--;
				
				for (int cell = NbRemainingRows-1; cell > 1; cell--) {
					
					if (NbRemainingMines <= 0) {
						break;
					}
					NbRemainingMines--;
					
					Minefield[NbRemainingColumns][cell] = MINE;						
				}
				
			}
		}
		
		#ifdef DEBUG2
		cout << "AFTER PHASE 2:" << endl;		
		DEBUG_PRINT("Number remaining mines   = %d (initial %d)\n", NbRemainingMines, NbMines);
		DEBUG_PRINT("Number remaining columns = %d (initial %d)\n", NbRemainingColumns, NbColumns);
		DEBUG_PRINT("Number remaining rows    = %d (initial %d)\n", NbRemainingRows, NbRows);
		PrintMinefield(Minefield, NbRows, NbColumns, false);
		#endif
		
		
		// Third phase: we now have at maximum 1 (!) mine left.
		
			
		if (NbRemainingMines == 1) {
			
			if (NbRemainingColumns == 2 || NbRemainingRows == 2) {
		#ifdef DEBUG
		cout << "FINAL:" << endl;
		DEBUG_PRINT("Number remaining mines   = %d (initial %d)\n", NbRemainingMines, NbMines);
		DEBUG_PRINT("Number remaining columns = %d (initial %d)\n", NbRemainingColumns, NbColumns);
		DEBUG_PRINT("Number remaining rows    = %d (initial %d)\n", NbRemainingRows, NbRows);
		PrintMinefield(Minefield, NbRows, NbColumns, false);
		#endif
				cout << "Impossible" << endl;
				continue;
			}
						
			if (NbRemainingColumns < NbRemainingRows) {
				
				NbRemainingMines--;
				Minefield[NbRemainingColumns-1][NbRemainingRows-1] = MINE;
				
			} else if (NbRemainingColumns > 1) {
				NbRemainingMines--;
				Minefield[NbRemainingColumns-1][NbRemainingRows-1] = MINE;					
			}			
		} 
		
		#ifdef DEBUG
		cout << "FINAL:" << endl;
		DEBUG_PRINT("Number remaining mines   = %d (initial %d)\n", NbRemainingMines, NbMines);
		DEBUG_PRINT("Number remaining columns = %d (initial %d)\n", NbRemainingColumns, NbColumns);
		DEBUG_PRINT("Number remaining rows    = %d (initial %d)\n", NbRemainingRows, NbRows);
		PrintMinefield(Minefield, NbRows, NbColumns, false);
		#endif
		
		// Last step: per construction, the cell (1,1) must be a 0.
		// If it is not, this means that the test case is impossible.
		
		if ( (NbRemainingMines > 0) || 
		((NbMines + 1 < NbColumns*NbRows) &&
		   (Minefield[0][0] >= MINE || Minefield[0][1] >= MINE || Minefield[1][0] >= MINE || Minefield[1][1] >= MINE) ) ) {
			cout << "Impossible" << endl;
		} else {
			PrintMinefield(Minefield, NbRows, NbColumns, true);
		}

	}
	
	
	
	return 0;
}
