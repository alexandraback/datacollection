#include <fstream>
using namespace std;

int board[50][50];

void clearBoard(int board[50][50]) {
	for (int i = 0; i < 50; i++)
		for (int j = 0; j < 50; j++)
			board[i][j] = 0;
}

void placeMines(int board[50][50], int rowTop, int colLeft, 
					int rowBot, int colRight, int mines) {
	int w = colRight - colLeft + 1;
	int h = rowBot - rowTop + 1;
	if ( w > h) {
		if (mines >= h) {
			for (int i = 0; i < h; i++)
				board[rowTop+i][colLeft] = -1;
			placeMines(board, rowTop, colLeft+1, rowBot, colRight, mines-h);
		} else {
			if (mines == w-1 && h > 1 && mines > 1) {
				for (int i = 0; i < mines-1; i++) 
					board[rowTop][colLeft+i] = -1;
				board[rowTop+1][colLeft] = -1;
			} else {
				for (int i = 0; i < mines; i++) 
					board[rowTop][colLeft+i] = -1;
			}
		}
	} else {
		if (mines >= w) {
			for (int i = 0; i < h; i++)
				board[rowTop][colLeft+i] = -1;
			placeMines(board,rowTop+1, colLeft, rowBot, colRight, mines-w);
		} else {
			if (mines == h-1 && w > 1 && mines > 1) {
				for (int i = 0; i < mines-1; i++)
					board[rowTop+i][colLeft] = -1;
				board[rowTop][colLeft+1] = -1;
			} else {
				for (int i = 0; i < mines; i++)
					board[rowTop+i][colLeft] = -1;
			}
		}
	}
}

void drawFrontier(int board[50][50], int R, int C) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == -1) {
				if ((i-1) >= 0) {
					if ((j-1) >= 0) {
						if (board[i-1][j-1] != -1)
							board[i-1][j-1] = 1;
					}
					if ((j+1) < C) {
						if (board[i-1][j+1] != -1)
							board[i-1][j+1] = 1;
					}
					// j
						if (board[i-1][j] != -1)
							board[i-1][j] = 1;
				}
				if (i+1 < R) {
					if ((j-1) >= 0) {
						if (board[i+1][j-1] != -1)
							board[i+1][j-1] = 1;
					}
					if ((j+1) < C) {
						if (board[i+1][j+1] != -1)
							board[i+1][j+1] = 1;
					}
					// j
						if (board[i+1][j] != -1)
							board[i+1][j] = 1;
				}
				// i
					if ((j-1) >= 0) {
						if (board[i][j-1] != -1)
							board[i][j-1] = 1;						
					}
					if ((j+1) < C) {
						if (board[i][j+1] != -1)
							board[i][j+1] = 1;						
					}
			}
		}
	}
}

bool drawClick(int board[50][50], int R, int C) {
	bool found = false;
	for (int i = 0; i < R && !found; i++) {
		for (int j = 0; j < C && !found; j++) {
			if (board[i][j] == 0) {
				board[i][j] = 2;
				found = true;
			}	
		}
	}
	return found;
}

bool checkIsolatedFrontier(int board[50][50], int R, int C) {
	bool result = false;
	for (int i = 0; i < R && !result; i++) {
		for (int j = 0; j < C && !result; j++) {
			if ( board[i][j] == 1 && 
				  ((i-1 < 0 || j-1 < 0) || (board[i-1][j-1] != 0 && board[i-1][j-1] != 2))
				&& ((i-1 < 0) 			 || (board[i-1][j]   != 0 && board[i-1][j] != 2))
				&& ((i-1 < 0 || j+1 >= C) || (board[i-1][j+1] != 0 && board[i-1][j+1] != 2))
				&& ((j-1 < 0) 				|| (board[i][j-1] != 0 && board[i][j-1] != 2))
				&& ((j+1 >= C) 			|| (board[i][j+1] != 0 && board[i][j+1] != 2))
				&& ((i+1 >= R || j-1 < 0) || (board[i+1][j-1] != 0 && board[i+1][j-1] != 2))
				&& ((i+1 >= R ) 			|| (board[i+1][j] != 0 && board[i+1][j] != 2))
				&& ((i+1 >= R || j+1 >= C) || (board[i+1][j+1] != 0 && board[i+1][j+1] != 2))
				)
				result = true;
		}
	}
	return result;
}

int main() {
	ifstream ifs("inputC.txt");
	if (ifs.is_open()) {
		ofstream ofs("outputC.txt");
		if (ofs.is_open()) {
			int T, R , C , M;
			ifs >> T;
			for (int n=1; n <= T; n++) {
				ifs >> R;
				ifs >> C;
				ifs >> M;
				ofs << "Case #" << n << ":" << endl;
				clearBoard(board);
				placeMines(board, 0, 0, R-1, C-1, M);
				drawFrontier(board, R, C);
				if ( (drawClick(board, R, C) && !checkIsolatedFrontier(board,R,C))
					|| M == (R*C -1)) {
					for (int i = 0; i < R; i++) {
						for (int j = 0; j < C; j++) {
							if (board[i][j]==-1) ofs << '*';
							else if(board[i][j] == 1 && M == (R*C -1)) ofs << 'c';
							else if(board[i][j] == 2) ofs << 'c';
							else ofs << '.';
						}
						ofs << endl;
					}
				} else {
					ofs << "Impossible" << endl;
				}
			}
			ofs.close();
		}
		ifs.close();
	}
	return 0;
}
