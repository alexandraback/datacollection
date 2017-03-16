#include <iostream>
#include <fstream>
#include <stack>
#include <algorithm>
using namespace std;

ifstream inFile;
ofstream outFile;
char **grid;
int R, C, M;
int curMines;

int connect[8][2] = {
	{ 0, 1 },
	{ 1, 1 },
	{ 1, 0 },
	{ 1,-1 },
	{ 0,-1 },
	{-1,-1 },
	{-1, 0 },
	{-1, 1 }
};

void printGrid(){
	for (int r = 0; r < R; ++r){
		for (int c = 0; c < C; ++c){
			outFile << grid[r][c];
		}
		outFile << "\n";
	}
}

int solve(int x, int y){
	unsigned int nearbyMines = 0;
	if(x<0 || x>=R || y<0 || y>=C) return 0;

	for (int i = 0; i < 8; ++i){
		int tx = x+connect[i][0];
		int ty = y+connect[i][1];
		if(tx<0 || tx>=R || ty<0 || ty>=C) continue;

		if(grid[tx][ty]=='*'){
			curMines--;
			grid[tx][ty] = '.';
			nearbyMines |= 1<<i;
		}
	}

	if(nearbyMines == 0) return 0;

	if(curMines == M) return 1;
	else if(curMines > M){
		for (int i = 0; i < 8; ++i){
			if(solve( x+connect[i][0], y+connect[i][1] )) return 1;
		}
	}

	for (int i = 0; i < 8; ++i){
		int tx = x+connect[i][0];
		int ty = y+connect[i][1];
		if(tx<0 || tx>=R || ty<0 || ty>=C) continue;

		if( nearbyMines&(1<<i) ){
			curMines++;
			grid[tx][ty] = '*';
		}
	}

	return 0;
}

int main(int argc, char const *argv[]){
	if(argc != 2){
		cout<<"Error in Input"<<endl;
		return 0;
	}
	inFile.open(argv[1]);
	outFile.open("output.txt", ios::trunc | ios::out);
	if(!(inFile.is_open() && outFile.is_open()) ){
		cout << "can't open files"<<endl;
		return 0;
	}

	int N;
	inFile >> N;
	cout << "Running through " << N << " Iterations" << endl;
	for(int count=0; count<N; count++){
		inFile >> R;
		inFile >> C;
		inFile >> M;

		curMines = R*C;
		grid = new char*[R];
		for(int r = 0; r < R; ++r){
		    grid[r] = new char[C];
		    for (int c = 0; c < C; ++c){
		    	grid[r][c] = '*';
		    }
		}

		outFile << "Case #" << count+1 << ":\n";

		bool answer = false;
		for (int i = 0; i < R; ++i){
			for (int j = 0; j < C; ++j){
				grid[i][j] = '.';
				curMines--;
				if(curMines == M) {
					grid[i][j] = 'c';
					printGrid();
					answer = true;
					break;
				} else if(solve(i,j)){
					grid[i][j] = 'c';
					printGrid();
					answer = true;
					break;
				}
				grid[i][j] = '*';
				curMines++;
			}
		}

		if(!answer) outFile << "Impossible" << std::endl;

		cout << "#Done#" << std::endl;
		delete[] grid;
	}

	inFile.close();
	outFile.close();
	return 0;
}
