#include <iostream>
#include <fstream>

#define LIM_R 51

#define UNKNOWN -2
#define MINE -1
#define CLICK 0

using namespace std;

class Board {
	int grid[LIM_R][LIM_R];	
	int r, c, mines, reqdMines;
	
public:
	Board(int r, int c, int m): r(r), c(c), reqdMines(m) {
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
				grid[i][j] = MINE;
		mines = r * c;
	}
	
	bool isIn(int x, int y) {
		return x >= 0 && x < r && y >= 0 && y < c;
	}
	
	bool isMine(int x, int y) {
		return isIn(x, y) && grid[x][y] == MINE;
	}
	
	int getNeighbours(int x, int y, int nbours[][2]) {
		int count = 0;
		
		for(int i = x - 1; i <= x + 1; i++) {
			for(int j = y - 1; j <= y + 1; j++) {
				if(i == x && j == y) continue;
				if(isIn(i, j)) {
					if(nbours != NULL) {
						nbours[count][0] = i;
						nbours[count][1] = j;
					}
					count++;
				}
			}
		}
		
		return count;
	}

	int getNeighbourMines(int x, int y, int nbours[][2]) {
		int count = 0;
		
		for(int i = x - 1; i <= x + 1; i++) {
			for(int j = y - 1; j <= y + 1; j++) {
				if(i == x && j == y) continue;
				if(isMine(i, j)) {
					if(nbours != NULL) {
						nbours[count][0] = i;
						nbours[count][1] = j;
					}
					count++;
				}
			}
		}
		
		return count;
	}
	
	void removeNeighbourMines(int x, int y) {
		int nb[8][2], mcount;
		mcount = getNeighbourMines(x, y, nb);
		for(int i = 0; i < mcount; i++) remMine(nb[i][0], nb[i][1]);
	}
	
	void update(int x, int y) {
		if(!isMine(x, y)) {
			int nb[8][2], count;
			count = getNeighbours(x, y, nb);
			
			grid[x][y] = 0;
			for(int i = 0; i < count; i++)
				if(isMine(nb[i][0], nb[i][1])) grid[x][y]++;
		}
	}
	
	void updateNeighbours(int x, int y) {
		int nb[8][2], count;
		count = getNeighbours(x, y, nb);
		for(int i = 0; i < count; i++) update(nb[i][0], nb[i][1]);
	}
	
	void putMine(int x, int y) {
		if(!isMine(x, y)) {
			grid[x][y] = MINE;
			updateNeighbours(x, y);
			mines++;
		}
	}
		
	bool adjustToReqdMines(int startX, int startY) {
		if(mines < reqdMines) return false;
		if(mines == reqdMines) return true;

		int frontier[r * c][2], flength;
		
		remMine(startX, startY);
		flength = 1; frontier[0][0] = startX; frontier[0][1] = startY;
		
		while(mines > reqdMines) {
//			print();
			int bestX, bestY, minX, minY, minMines = 9;
			minX = minY = 0;
			bestX = bestY = -1;
			flength = 0;
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < c; j++) {
					if(grid[i][j] > 0) {
						frontier[flength][0] = i;
						frontier[flength][1] = j;
						flength++;
					}
				}
			}
			
			for(int i = 0; i < flength; i++) {
				int cx = frontier[i][0],
					cy = frontier[i][1];
				if(mines - grid[cx][cy] == reqdMines) {
					bestX = cx;
					bestY = cy;
					break;
				}
				
				if(grid[cx][cy] < minMines) {
					minX = cx;
					minY = cy;
					minMines = grid[cx][cy];
				}
			}
			
			if(bestX >= 0) {
				removeNeighbourMines(bestX, bestY);
//				cout << "Found solution!" << endl;
			}
			else if(mines - minMines < reqdMines) return false;
			else {
//				cout << "Minimum mines at (" << minX << ", " << minY << "): " << grid[minX][minY] << endl;
				removeNeighbourMines(minX, minY);
			}
		}
				
		return mines == reqdMines;
	}
	
	void remMine(int x, int y) {
		if(isMine(x, y)) {
			grid[x][y] = 0;
			update(x, y);
			updateNeighbours(x, y);
			mines--;
		}
	}
	
	
	
	void print() {
		cout << "Mines: " << mines << endl;
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				if(grid[i][j] == MINE)		 cout << "*";
				else if(grid[i][j] == CLICK) cout << "c";
				else						 cout << grid[i][j];
			}
			cout << endl;
		}
	}
	
	void printSolution(ofstream &cout) {
		int zerox = -1, zeroy = -1;
		int clickx = -1, clicky = -1;
		
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				if(grid[i][j] == 0) {
					zerox = i;
					zeroy = j;
				}
				if(grid[i][j] > 0) {
					clickx = i;
					clicky = j;
				}
			}
			if(zerox > 0) break;
		}
		
		if(isIn(zerox, zeroy)) {
			clickx = zerox;
			clicky = zeroy;
		}
		
		
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				if(grid[i][j] == MINE)				cout << "*";
				else if(clickx == i && clicky == j) cout << "c";
				else								cout << ".";
			}
			cout << endl;
		}
	}
};

int main() {
	ifstream cin;
	ofstream cout;
	cin.open("C-large.in");
	cout.open("C-large.out");

	int testCases, r, c, m;
	cin >> testCases;
	
	for(int tcase = 1; tcase <= testCases; tcase++) {
		cin >> r >> c >> m;
		
		cout << "Case #" << tcase << ":" << endl;

		bool found = false;
		for(int i = 0; i < r && !found; i++) {
			for(int j = 0; j < c && !found; j++) {
				Board board(r, c, m);
				found = board.adjustToReqdMines(i, j);
				if(found) board.printSolution(cout);
			}
		}		
		if(!found) cout << "Impossible" << endl;
	}
	
	cin.close();
	cout.close();
	return 0;
}