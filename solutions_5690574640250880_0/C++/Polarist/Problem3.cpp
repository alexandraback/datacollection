#include "Problem3.h"

#include <fstream>
#include <iostream>
#include <string>
#include <assert.h>
#include <cstdlib>
#include <algorithm>

using namespace std;


int main(int argc, char ** argv){
	ifstream in("problem3.in");
	ofstream out("problem3.out");
	int count;
	in >> count;

	for (int i = 0; i < count; i++){
		
		int rows, columns, mines;
		buf_t *buffer = 0;

		in >> rows >> columns >> mines;

		cout << "Case #" << i + 1 << ": (" << rows << ", " << columns << ", " << mines << ")" << endl;

		buffer = (buf_t *)malloc(sizeof(int)*rows*columns);
		clearbuffer(rows, columns, buffer);


		//// create buffer for game board
		//buffer = new int*[rows];
		//for (int j = 0; j < rows; j++){
		//	buffer[j] = new int[columns];
		//}
		
		//out << "Case #" << i + 1 << ":";
		out << "Case #" << i + 1 << ":" << endl;
		//if (problem3(rows, columns, mines, buffer)){
		if (answer2(rows, columns, mines, buffer)){
			assert(buffer);
			for (int j = 0; j < rows; j++){
				for (int k = 0; k < columns; k++){
					switch (buffer[columns*j+k]){
					case 0:
					case 3:
						out << '.';
						break;
					case 1:
						out << '*';
						break;
					case 2:
						out << 'c';
						break;
					default:
						//buf_t temp = buffer[columns*j + k];
						//out << '-';
						assert(0);
					}
				}
				out << endl;
			}
			//out << endl;
		}
		else {
			out << "Impossible" << endl;
		}

		free(buffer);
		buffer = nullptr;


	}
	
	return 0;
}

//
//int problem3(int r, int c, int m, int buf[60][60]){
//	int curmines;
//	// how many cols to prefill
//	for (int i = 0; i <= c; i++){
//		clearbuffer(r, c, buf);
//
//		curmines = m;
//
//		// fill in columns
//		for (int j = 0; j < i; j++){
//			if (curmines == 0) break;
//			for (int k = 0; k < r; k++){
//				if (curmines == 0) break;
//				buf[k][j] = 1;
//				curmines--;
//			}
//		}
//
//		// fill in rows until no mines
//		for (int j = 0; j < r; j++){
//			if (curmines == 0) break;
//			for (int k = 0; k < c; k++){
//				if (curmines == 0) break;
//				if (buf[j][k] == -1){
//					buf[j][k] = 1; // Add mine on board
//					curmines--;
//				}
//			}
//		}
//
//		// Mines don't fit on gameboard
//		if (curmines != 0){
//			return false;
//		}
//
//		// Number of mines greater than or equal to game board (nowhere to click)
//		if (r*c <= m){
//			return false;
//		}
//
//
//		if (checkBoard(r, c, buf)){
//			return true;
//		}
//	}
//	return false;
//}

bool checkWithMinesInRow(int r, int c, int m, buf_t *minesInRow, buf_t *buffer){
	// construct buffer
	clearbuffer(r, c, buffer);
	int curMines;
	for (int i = 0; i < r; i++){
		curMines = minesInRow[i];
		if (curMines == 0) break;
		for (int j = 0; j < c; j++){
			if (curMines == 0) break;
			buffer[c*i + j] = 1;
			curMines--;
		}
	}

	if (checkBoard(r, c, buffer)){
		return true;
	}

	return false;
}

bool minecheck2(int r, int c, int m, buf_t *minesInRow, buf_t *buffer, int curRow, int curMax, int remainingMines){
	


	// if remaining mines used up
	if (remainingMines == 0){
		// fill rest of buffer with 0s and check
		for (int i = curRow; i < r; i++){
			minesInRow[i] = 0;
		}
		if (checkWithMinesInRow(r, c, m, minesInRow, buffer)){
			return true;
		}
		else {
			return false;
		}
	}

	// if mines left after last row, return false;
	if (curRow >= r){
		return false;
	}

	for (int i = curMax; i >= 0; i--){
		if (remainingMines >= i){
			minesInRow[curRow] = i;

			// recurse
			if (minecheck2(r, c, m, minesInRow, buffer, curRow + 1, i, remainingMines - i)){
				return true;
			}
		}
	}
	return false;
}
//
//bool minecheck(int r, int c, int m, buf_t *minesInRow, buf_t *buf){
//	cout << "checking mine layout: ";
//	for (int i = 0; i < r; i++){
//		cout << (int)minesInRow[i] << " ";
//	}
//	cout << endl;
//	int answerFound = 0;
//	// construct board and check if solution
//
//	clearbuffer(r, c, buf);
//	int curMines;
//	for (int i = 0; i < r; i++){
//		curMines = minesInRow[i];
//		if (curMines == 0) break;
//		for (int j = 0; j < c; j++){
//			if (curMines == 0) break;
//			buf[c*i + j] = 1;
//			curMines--;
//		}
//	}
//	if (checkBoard(r, c, buf)){
//		answerFound = true;
//	}
//	// check if
//
//	if (!answerFound){
//		buf_t *newMines = (buf_t *)malloc(sizeof(buf_t)*r);
//		for (int i = 0; i<r; i++){
//			// Check if row is distributable (not last row, greater than 1, and wont make smaller than next row)
//			if (i < r - 1 && (minesInRow[i] > 1 && minesInRow[i] - 1 >= minesInRow[i + 1])){
//				//distribute
//				// special case first spot
//				if (minesInRow[i + 1] + 1 <= minesInRow[i] - 1) {
//					//create new minesinrow
//					memcpy(newMines, minesInRow, sizeof(buf_t)*r);
//					newMines[i]--;
//					newMines[i + 1]++;
//					//recurse
//					if (minecheck(r, c, m, newMines, buf, max(i-1, 0))) {
//						// since answer found, copy newmines over and free
//						memcpy(minesInRow, newMines, sizeof(buf_t)*r);
//						answerFound = true;
//					}
//				}
//
//				if (!answerFound) // if no answer, continue
//				for (int j = i + 2; j < r; j++){
//					if (minesInRow[j] + 1 <= minesInRow[j - 1]){
//						assert(minesInRow[j] + 1 <= c);
//						//create new minesinrow
//						memcpy(newMines, minesInRow, sizeof(buf_t)*r);
//						newMines[i]--;
//						newMines[j]++;
//						//recurse
//						if (minecheck(r, c, m, newMines, buf)) {
//							// since answer found, copy newmines over and free
//							memcpy(minesInRow, newMines, sizeof(buf_t)*r);
//							answerFound = true;
//							break;
//						}
//					}
//				}
//			}
//
//			// If answer found, no need to keep distributing
//			if (answerFound) break;
//		}
//	}
//	if (answerFound) return true;
//	else return false;
//}

bool findAnswer(int r, int c, int m, buf_t *minesInRow, buf_t *buf){
	// create max mines helper structure
	return minecheck2(r, c, m, minesInRow, buf, 0, c, m);
	//minecheck(r, c, m, minesInRow, buf, maxMines);
}

int answer2(int r, int c, int m, buf_t *buf){

	buf_t *minesInRow = (buf_t *)malloc(sizeof(buf_t)*r);
	//initialize to 0;
	for (int i = 0; i < r; i++){
		minesInRow[i] = 0;
	}

	// distribute mines across the top
	int curMines = m;
	for (int i = 0; i<r; i++){
		if (curMines == 0){
			break;
		}

		if (curMines >= c){
			minesInRow[i] = c;
			curMines -= c;
		}
		else {
			minesInRow[i] = curMines;
			curMines = 0;
		}
	}

	// Mines don't fit on gameboard
	if (curMines != 0){
		return false;
	}

	// Number of mines greater than or equal to game board (nowhere to click)
	if (r*c <= m){
		return false;
	}

	
	bool answer = findAnswer(r, c, m, minesInRow, buf);
	// reconstruct game board
	free(minesInRow);
	return answer;

}

int checkBoard(int r, int c, buf_t *buf){
	assert(buf[c*(r - 1) + (c - 1)] == -1); // should always be a spot at bottom right;
	
	fillBoard(r - 1, c - 1, r, c, buf);
	buf[c*(r-1) + (c-1)] = 2; // Add clickspot on board

	if (isBoardFull(r, c, buf)){
		return true;
	}
	else {
		return false;
	}

}

// recursively fill board from position
int dirs[][2] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };
int numdirs = 8;
int filldirs[][2] = { { -1, -1 }, { -1, 0 }, { 0, -1 } };
int numfilldirs = 3;

void fillBoard(int x, int y, int r, int c, buf_t *buf){
	int minesFound = 0;
	// check for mines
	for (int i = 0; i < numdirs; i++){
		// bounds check
		if (dirs[i][0] + x < 0 || dirs[i][0] + x >= r) continue;
		if (dirs[i][1] + y < 0 || dirs[i][1] + y >= c) continue;

		if (buf[c*(dirs[i][0] + x)+(dirs[i][1] + y)] == 1) minesFound++;
	}

	// if no mines, recurse
	if (minesFound == 0){
		buf[c*x + y] = 0;
		for (int i = 0; i < numdirs; i++){
			// bounds check
			if (dirs[i][0] + x < 0 || dirs[i][0] + x >= r) continue;
			if (dirs[i][1] + y < 0 || dirs[i][1] + y >= c) continue;

			// check if fresh
			if (buf[c*(dirs[i][0] + x)+ (dirs[i][1] + y)] == -1){
				fillBoard(dirs[i][0] + x, dirs[i][1] + y, r, c, buf);
			}
			
		}
	} else {
		// if mines found end
		buf[c*x+y] = 3;
	}
}

void clearbuffer(int r, int c, buf_t *buf){
	memset(buf, -1, sizeof(buf_t)*r*c);
	//for (int i = 0; i < r; i++){
	//	for (int j = 0; j < c; j++){
	//		buf[c*i + j] = -1;
	//	}
	//}
}

int isBoardFull(int r, int c, buf_t *buf){
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (buf[c*i + j] == -1){
				return false;
			}
		}
	}
	return true;
}
