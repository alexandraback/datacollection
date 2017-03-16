#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <strings.h>

using namespace std;

int minV, maxV;
int R, C, M;
const int MAX_SIZE = 5;
char board[MAX_SIZE + 2][MAX_SIZE + 2];//[R][C]
int countN[MAX_SIZE + 2][MAX_SIZE + 2];
vector<char> boardRaw;

void printBoard(){
	for (int i = 1; i <= R; i++){
		for (int j = 1; j <= C; j++){
			cout << board[i][j];
		}
		cout << endl;
	}
}

void resetBoard(){
	for (int i = 0; i < MAX_SIZE + 2; i++){
		for (int j = 0; j < MAX_SIZE + 2; j++){
			board[i][j] = '.';
			countN[i][j] = -10000000;
		}
	}
}

int reach(int R, int C){
	if (countN[R][C] == 0){
		int newCount = 0;
		countN[R][C] = -100;
		for (int i = -1; i <= 1; i++){
			for (int j = -1; j <= 1; j++){
				newCount += reach(R + i, C + j);
			}
		}
		return 1 + newCount;
	} else {
		if (countN[R][C] > 0){
			countN[R][C] = -100;
			return 1;
		} else {
			return 0;//out of bounds
		}
	}
}


int main(){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		cout << "Case #" << (i + 1) << ": " << endl; 
		cin >> R >> C >> M;
		boardRaw.clear();
		for (int j = 0; j < M; j++){
			boardRaw.push_back('*');
		}
		boardRaw.push_back('c');
		while(boardRaw.size() != R * C){
			boardRaw.push_back('.');
		}
		sort(boardRaw.begin(), boardRaw.end());
		bool found = false;
		do {
			resetBoard();
			for (int j = 1; j <= R; j++){
				for (int k = 1; k <= C; k++){
					countN[j][k] = 0;
				}
			}
			int c = 0;
			int clickR, clickC;
			for (int j = 1; j <= R; j++){
				for (int k = 1; k <= C; k++){
					board[j][k] = boardRaw[c];
					if (boardRaw[c] == 'c'){
						clickR = j;
						clickC = k;
					}
					c++;
				}
			}
			for (int j = 1; j <= R; j++){
				for (int k = 1; k <= C; k++){
					if (board[j][k] == '*'){
						for (int dj = -1; dj <= 1; dj++){
							for (int dk = -1; dk <= 1; dk++){
								countN[j+dj][k+dk]++;
							}
						}
						countN[j][k] = -100;
					}
				}
			}
			if ((countN[clickR][clickC] != 0) && (M != R * C - 1)){//not valid
				continue;
			}
			int reached = reach(clickR, clickC);
			if (reached == R * C - M){
				found = true;
				printBoard();
				break;
			} 
		} while(next_permutation(boardRaw.begin(), boardRaw.end()));
		if (!found){
			cout << "Impossible" << endl;
		}
	}
}
