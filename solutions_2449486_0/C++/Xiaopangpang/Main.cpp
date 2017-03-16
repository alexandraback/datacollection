#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

typedef vector<vector<int>> Lawn;

bool CanBeCut(const Lawn &lawn, const unsigned row, const unsigned col, const unsigned height) {
	for(unsigned i = 0; i < lawn[row].size(); ++i) {
		if(height != lawn[row][i])
			break;
		if(i == lawn[row].size() - 1)
			return true;
	}

	for(unsigned i = 0; i < lawn.size(); ++i) {
		if(height != lawn[i][col])
			return false;
	}
	return true;
}

bool CanBeCut(const Lawn &lawn, const unsigned height) {
	for(unsigned i = 0; i < lawn.size(); ++i) {
		for(unsigned j = 0; j < lawn[i].size(); ++j){
			if(lawn[i][j] == height && !CanBeCut(lawn, i, j, height))
				return false;
		}
	}
	return true;
}

void FillLawn(Lawn &lawn, const unsigned height, const unsigned newHeight) {
	for(unsigned i = 0; i < lawn.size(); ++i) {
		for(unsigned j = 0; j < lawn[i].size(); ++j){
			if(lawn[i][j] == height)
				lawn[i][j] = newHeight;
		}
	}
}

bool CanBeCut(Lawn &lawn) {
	set<unsigned> heights;

	for(unsigned i = 0; i < lawn.size(); ++i) {
		for(unsigned j = 0; j < lawn[i].size(); ++j){
			heights.insert(lawn[i][j]);
		}
	}

	while(heights.size() > 1) {
		unsigned height = *(heights.begin());
		if(!CanBeCut(lawn, height))
			return false;
		heights.erase(height);
		FillLawn(lawn, height, *heights.begin());
	}
	return CanBeCut(lawn, *heights.begin());
}

int main(int argc, char *argv[]) {
	fstream infile(argv[1]);
	if(!infile.is_open()) {
		cerr << "Could not open file " << argv[0] << endl;
		return -1;
	}

	string line;
	getline(infile, line);
	unsigned testCase = atoi(line.c_str());
	for(unsigned i = 1; i <= testCase; ++i) {
		cout << "Case #" << i << ": ";
		getline(infile, line);
		stringstream ss(line);
		int N, M;
		ss >> N >> M;
		Lawn lawn;
		for(int i = 0; i < N; ++i) {
			getline(infile, line);
			stringstream ss(line);
			vector<int> row;
			for(int j = 0; j < M; ++j) {
				int height;
				ss >> height;
				row.push_back(height);
			}
			lawn.push_back(row);
		}
		cout <<	(CanBeCut(lawn) ? "YES" : "NO") << endl;
	}

	return 0;
}