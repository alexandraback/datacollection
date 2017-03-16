#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <utility> 
#include <algorithm>

using namespace std;

void searchNeighbor(int & state, bool ** usedMap, char ** saveMap, 
	const int clickX, const int clickY, int & num, const int & numSafe, const int & R, const int & C) {
	if (state == 1)	return;
	
	// add 8 neighbors
	int addNum(0);
	int neX[8];
	int neY[8];
	vector<int> addIdx;

	neX[0] = min(clickX+1, R-1);
	neX[1] = min(clickX+1, R-1);
	neX[2] = min(clickX+1, R-1);
	neX[3] = clickX;
	neX[4] = clickX;
	neX[5] = max(clickX-1, 0);
	neX[6] = max(clickX-1, 0);
	neX[7] = max(clickX-1, 0);

	neY[0] = min(clickY+1, C-1);
	neY[1] = max(clickY-1, 0);
	neY[2] = clickY;
	neY[3] = min(clickY+1, C-1);
	neY[4] = max(clickY-1, 0);
	neY[5] = min(clickY+1, C-1);
	neY[6] = clickY;
	neY[7] = max(clickY-1, 0);
	
	bool flagFill(true);
	for(int i = 0; i < 8; ++i) {
		if (usedMap[neX[i]][neY[i]] && saveMap[neX[i]][neY[i]] == '*') {
			flagFill = false;
			break;
		}
	}

	if (flagFill) {
		for(int i = 0; i < 8; ++i) {
			if (!usedMap[neX[i]][neY[i]]) {
				usedMap[neX[i]][neY[i]] = true;
				saveMap[neX[i]][neY[i]] = '.';
				addIdx.push_back(i);
				addNum++;
			}
		}
	}
	else {
		usedMap[clickX][clickY] = true;
		return;
	}
	
	if (0 == addNum)	return;
	num += addNum;
	
	if (num > numSafe) {
		// back tracking
		num -= addNum;
		
		while(!addIdx.empty()) {
			int tmpIdx = addIdx.back();
			usedMap[neX[tmpIdx]][neY[tmpIdx]] = false;
			saveMap[neX[tmpIdx]][neY[tmpIdx]] = '*';
			addIdx.pop_back();
		}
		usedMap[clickX][clickY] = true;
	}
	else if (num == numSafe) {
		state = 1;
	}
	else {
		for(int i = 0; i < 8; ++i)
			searchNeighbor(state, usedMap, saveMap, neX[i], neY[i], num, numSafe, R, C);
	}
	
	return;
}

void constructMap(int & state, char ** saveMap, const int & M, const int & R, const int & C) {	
	int num(0), numSafe(R*C-M);

	if (numSafe == 1) {
		for (int m = 0; m < R; ++m)
			for (int n = 0; n < C; ++n) 
				saveMap[m][n] = '*';

		saveMap[0][0] = 'c';
		state = 1;
		return;
	}

	if (numSafe == R*C) {
		for (int m = 0; m < R; ++m)
			for (int n = 0; n < C; ++n) 
				saveMap[m][n] = '.';

		saveMap[0][0] = 'c';
		state = 1;
		return;
	}

	bool ** usedMap = new bool * [R];
	for (int i = 0; i < R; ++i)
		usedMap[i] = new bool [C];

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			num = 0;
			state = 0;
			for (int m = 0; m < R; ++m) {
				for (int n = 0; n < C; ++n) {
					usedMap[m][n] = false;
					saveMap[m][n] = '*';
				}
			}
			
			int clickX(i), clickY(j);
			num++;
			usedMap[clickX][clickY] = true;
			saveMap[clickX][clickY] = 'c';
			searchNeighbor(state, usedMap, saveMap, clickX, clickY, num, numSafe, R, C);
			
			if (state)	break;
		}
		if (state)	break;
	}

	for (int i = 0; i < R; ++i)	delete[] usedMap[i];
}


int main() {
	string basePath = "../data/2014_QR/";
	string baseName = "C-small-attempt1";
	string inFile = basePath + "/" + baseName + ".in";
	string outFile = basePath + "/" + baseName + "-out.txt";
	ifstream ifs(inFile.c_str(), ifstream::in);
	ofstream ofs(outFile.c_str(), ofstream::out);

	int numTest(0), idxTest(1), state(0);
	ifs >> numTest;	

	while(idxTest <= numTest) {
		int R, C, M, state(0);
		ifs >> R >> C >> M;

		char ** saveMap = new char * [R];
		for (int i = 0; i < R; ++i)
			saveMap[i] = new char [C];

		constructMap(state, saveMap, M, R, C);

		// output
		if (state) {
			ofs << "Case #" << idxTest << ":" << endl;
			for (int i = 0; i < R; ++i) {
				for (int j = 0; j < C; ++j) {
					ofs << saveMap[i][j];
				}
				ofs << endl;
			}
		}
		else
			ofs << "Case #" << idxTest << ":" << endl << "Impossible" << endl;
		
		for (int i = 0; i < R; ++i)	delete[] saveMap[i];
		cout << "Finish " << idxTest++ << "th case!" << endl;
	}

	ifs.close();
	ofs.close();
	getchar();
	return 0;
}