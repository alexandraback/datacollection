#include <iostream>
#include <sstream>
#include <numeric>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>

#define isOn(S, j) (S & (1ll << j))

using namespace std;

bool hasSolution(int *solution, int nextSolutionIndex, int nextPositionIndex, vector<int> &validPositions, int solutionSize){
	if (solutionSize == nextSolutionIndex){
		return true;
	}
	for (int i = nextPositionIndex; i < validPositions.size(); i++){
		bool allOk = true;
		for (int j = 0; j < nextSolutionIndex; j++){
			if (validPositions[i] & solution[j]){
				allOk = false;
			}
		}
		if (allOk){
			solution[nextSolutionIndex] = validPositions[i];
			if (hasSolution(solution, nextSolutionIndex + 1, i, validPositions, solutionSize)){
				return true;
			}
		}
	}
	return false;
}

bool isNOmino(vector < vector < bool > > board, int n){
	int count = 0;
	int selectedi, selectedj;
	for (int i = 0; i < board.size(); i++){
		for (int j = 0; j < board.size(); j++){
			if (board[i][j]){
				selectedi = i;
				selectedj = j;
				count++;
			}
		}
	}
	if (count != n){
		return false;
	}
	//Check connected
	queue< pair<int, int> > pending;
	pending.push(make_pair(selectedi, selectedj));
	board[selectedi][selectedj] = false;
	count--;
	while(pending.size()){
		pair<int, int > next = pending.front();
		pending.pop();
		int di[] = {-1, 1, 0, 0};
		int dj[] = {0, 0, 1, -1};
		for (int k = 0; k < 4; k++){
			int pi = next.first + di[k];
			int pj = next.second + dj[k];
			if ((pi >= 0) && (pj >= 0) && (pi < board.size()) && (pj < board.size()) && (board[pi][pj])){
				count--;
				pending.push(make_pair(pi, pj));
				board[pi][pj] = false;
			}
		}
	}
	return (count == 0);
}

int moveUpLeft(vector<vector < bool > > &board){
	int left = board.size();
	int up = board.size();
	for (int i = 0; i < board.size(); i++){
		for (int j = 0; j < board.size(); j++){
			if ((board[i][j]) && (j < left)){
				left = j;
			}
			if ((board[i][j]) && (i < up)){
				up = i;
			}
		}
	}
	if (left != board.size()){
		for (int i = 0; i < board.size(); i++){
			for (int j = 0; j < board.size(); j++){
				if ((i + up >= board.size()) || (j + left >= board.size())){
					board[i][j] = false;
				} else {
					board[i][j] = board[i+up][j+left];
				}
			}
		}
	}
}

int boardRotate(vector<vector < bool > > &board){
	vector< vector< bool > > board2 = board;
	for (int i = 0; i < board.size(); i++){
		for (int j = 0; j < board.size(); j++){
			board[i][j] = board2[board.size()-j-1][i];
		}
	}
}

int boardReflect(vector<vector < bool > > &board){
	vector< vector< bool > > board2 = board;
	for (int i = 0; i < board.size(); i++){
		for (int j = 0; j < board.size(); j++){
			board[i][j] = board2[i][board.size()-j-1];
		}
	}
}

int boardToId(vector < vector < bool > > &board){
	int id = 0;
	for (int i = 0; i < board.size(); i++){
		for (int j = 0; j < board.size(); j++){
			if (board[i][j]){
				id = (id << 1) | 1;
			} else {
				id = (id << 1);	
			}
		}
	}
	return id;
}

int getRepresentativeId(vector < vector < bool > > board){
	moveUpLeft(board);
	int id = boardToId(board);
	for (int i = 0; i < 3; i++){
		boardRotate(board);
		moveUpLeft(board);
		id = min(id, boardToId(board));
	}
	boardReflect(board);
	for (int i = 0; i < 4; i++){
		boardRotate(board);
		moveUpLeft(board);
		id = min(id, boardToId(board));
	}
	return id;
}

void buildBoard(int b, vector < vector < bool > > &board){
	int bit = 0;
	for (int i = 0; i < board.size(); i++){
		for (int j = 0; j < board.size(); j++){
			board[i][j] = isOn(b, bit);
			bit++;
		}
	}
}

int main(){
	int tests;
	cin >> tests;
	for (int t = 0; t < tests; t++){
		int x, r, c;
		cin >> x >> r >> c;
		if ((r * c) % x != 0){
			cout << "Case #" << (t + 1) << ": RICHARD" << endl;
			continue;
		}
		if ((x == 4) && (min(r, c) < 2)){
			cout << "Case #" << (t + 1) << ": RICHARD" << endl;
			continue;
		}
		if ((x == 4) && (max(r, c) < 4)){
			cout << "Case #" << (t + 1) << ": RICHARD" << endl;
			continue;
		}

		if ((x == 3) && (min(r, c) < 2)){
			cout << "Case #" << (t + 1) << ": RICHARD" << endl;
			continue;
		}

		if ((x == 1) || (x == 2)){
			cout << "Case #" << (t + 1) << ": GABRIEL" << endl;
			continue;
		}
		//cout << "Checar" << endl;
		//cout << x << " " << r << " " << c << endl;

		vector<int> validPositions;
		vector < vector < bool > > board(4, vector<bool>(4, false));
		map<int, set<int> > ominoIdToPositions;
		for (int i = 0; i < (1 << (4 * 4)); i++){
			buildBoard(i, board);
			bool valid = true;
			for (int j = 0; j < board.size(); j++){
				for (int k = 0; k < board.size(); k++){
					if ((board[j][k]) && ((j >= r) || (k >= c))){
						valid = false;
					}
				}
			}
			if ((valid) && (isNOmino(board, x))){
				validPositions.push_back(i);
				ominoIdToPositions[getRepresentativeId(board)].insert(i);
			}
		}
		bool richardWins = false;
		for (map<int, set<int> >::iterator it = ominoIdToPositions.begin(); it != ominoIdToPositions.end(); it++){
			bool foundSolution = false;
			for (set<int>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++){
				int solution[r*c/x];
				solution[0] = (*it2);
				if (hasSolution(solution, 1, 0, validPositions, r*c/x)){
					foundSolution = true;
					break;
				} 
			}
			if (!foundSolution){
				richardWins = true;
			}
		}
		if (richardWins){
			cout << "Case #" << (t + 1) << ": RICHARD" << endl;
		} else {
			cout << "Case #" << (t + 1) << ": GABRIEL" << endl;
		}
	}
}
