#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream fin ("C-large.in");
ofstream fout ("C-large.out");

vector<string> fill(vector<string> grid, int row, int col){
	char adjacent = '0';
	if(row-1 >= 0 && grid.at(row-1).at(col) == '*') adjacent++;
	if(row+1 < grid.size() && grid.at(row+1).at(col) == '*') adjacent++;
	if(col-1 >= 0 && grid.at(row).at(col-1) == '*') adjacent++;
	if(col+1 < grid.at(0).size() && grid.at(row).at(col+1) == '*') adjacent++;
	if(row-1 >= 0 && col-1 >= 0 && grid.at(row-1).at(col-1) == '*') adjacent++;
	if(row-1 >= 0 && col+1 < grid.at(0).size() && grid.at(row-1).at(col+1) == '*') adjacent++;
	if(row+1 < grid.size() && col-1 >= 0 && grid.at(row+1).at(col-1) == '*') adjacent++;
	if(row+1 < grid.size() && col+1 < grid.at(0).size() && grid.at(row+1).at(col+1) == '*') adjacent++;
	grid.at(row).at(col) = adjacent;
	if(adjacent == '0'){
		if(row-1 >= 0 && grid.at(row-1).at(col) == '.') grid = fill(grid, row-1, col);
		if(row+1 < grid.size() && grid.at(row+1).at(col) == '.') grid = fill(grid, row+1, col);
		if(col-1 >= 0 && grid.at(row).at(col-1) == '.') grid = fill(grid, row, col-1);
		if(col+1 < grid.at(0).size() && grid.at(row).at(col+1) == '.') grid = fill(grid, row, col+1);
		if(row-1 >= 0 && col-1 >= 0 && grid.at(row-1).at(col-1) == '.') grid = fill(grid, row-1, col-1);
		if(row-1 >= 0 && col+1 < grid.at(0).size() && grid.at(row-1).at(col+1) == '.') grid = fill(grid, row-1, col+1);
		if(row+1 < grid.size() && col-1 >= 0 && grid.at(row+1).at(col-1) == '.') grid = fill(grid, row+1, col-1);
		if(row+1 < grid.size() && col+1 < grid.at(0).size() && grid.at(row+1).at(col+1) == '.') grid = fill(grid, row+1, col+1);
	}
	return grid;
}

bool isValid(vector<string> grid){
	grid = fill(grid, grid.size()-1, grid.at(0).size()-1);
	bool invalid = false;
	for(vector<string>::iterator it = grid.begin(); it != grid.end(); it++){
		if((*it).find('.') != string::npos){
			invalid = true;
		}
	}
	return !invalid;
}

void makemap(int R, int C, int M){
	int R0, C0;
	R0 = 0; C0 = 0;
	vector<string> grid;
	for(int r = 0; r < R; r++){
			string row (C, '.');
			grid.push_back(row);
		}
	while((M >= (C-C0) && R0 < R-2) || (M >= (R-R0) && C0 < C-2)){
		if((C-C0)<(R-R0)){
			if(M >= (C-C0) && R0 < R-2){
				for(int c = C0; c < C; c++) grid.at(R0).at(c) = '*';
				M -= (C-C0);
				R0++;
			}
			if(M >= (R-R0) && C0 < C-2){
				for(int r = R0; r < R; r++) grid.at(r).at(C0) = '*';
				M -= (R-R0);
				C0++;
			}
		}
		else{
			if(M >= (R-R0) && C0 < C-2){
				for(int r = R0; r < R; r++) grid.at(r).at(C0) = '*';
				M -= (R-R0);
				C0++;
			}
			if(M >= (C-C0) && R0 < R-2){
				for(int c = C0; c < C; c++) grid.at(R0).at(c) = '*';
				M -= (C-C0);
				R0++;
			}
		}		
	}
	while(M > 0){
		if(C0 >= C-1){
			fout << "Impossible" << endl;
			return;
		}
		for(int r = R0; r < R-2; r++){
			if(M == 0) break;
			grid.at(r).at(C0) = '*';
			M--;
		}
		C0++;
	}
	grid.at(R-1).at(C-1) = 'c';
	if(isValid(grid)) for(vector<string>::iterator it = grid.begin(); it != grid.end(); it++) fout << *it << endl;
	else fout << "Impossible" << endl;
}

int main(){
	int T; fin >> T;

	for(int t = 0; t < T; t++){
		int R, C, M; fin >> R >> C >> M;
		fout << "Case #" << t+1 << ":" << endl;
		if(M == R*C-1){
			for(int r = 0; r < R; r++){
				string row (C, '*');
				if(r == R-1) row.at(C-1) = 'c';
				fout << row << endl;
			}
		}
		else makemap(R,C,M);
	}

	return 0;
}