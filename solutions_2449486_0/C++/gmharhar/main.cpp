#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <iterator>
#include <cmath>
#include <string>
#include <set>
#include <algorithm>

#define MAX(a, b) ((a < b) ? b : a)
#define MIN(a, b) ((a < b) ? a : b)


using namespace std;

void printMap(int *dpArray[], int w, int h) {
	for (int i = 0 ; i < h; i ++) {
		for ( int j = 0 ; j < w; j ++) {
			cout << dpArray[i][j] << " ";
		}
		cout << endl;
	}
}

void printVector(vector<int> data) {
	for (int i = 0; i < data.size(); i++) {
		cout << data[i];
	}
}

bool checkRow(int* map[], int w, int value, int r) {
	bool pass = false;
	for ( int j = 0 ; j < w; j ++) {

		if (map[r][j] != value && map[r][j] != -1) {
			return false;
		} else if (map[r][j] == value) {
			//cout << map[r][j] << ":" << value << endl;
			pass = true;
		}
	}
	return pass;
}

bool checkCol(int* map[], int h, int value, int c) {
	bool pass = false;
	for ( int j = 0 ; j < h; j ++) {

		if (map[j][c] != value && map[j][c] != -1) {
			return false;
		} else if (map[j][c] == value) {
			//cout << map[j][c] << ":" << value << endl;
			pass = true;
		}
	}
	return pass;
}

void deleteRow(int* map[], int w, int r) {
	for ( int j = 0 ; j < w; j ++) {
		map[r][j] = -1;
	}
}

void deleteCol(int* map[], int h, int c) {
	for ( int j = 0 ; j < h; j ++) {
		map[j][c] = -1;
	}
}

bool deleteRows(int* map[], int w, int h, int value) {
	bool deleted = false;
	for (int i = 0 ; i < h; i ++) {
		if (checkRow(map, w, value, i)) {
			deleteRow(map, w, i);
			deleted = true;
		}
	}
	for (int i = 0 ; i < w; i ++) {
		if (checkCol(map, h, value, i)) {
			deleteCol(map, h, i);
			deleted = true;
		}
	}
	return deleted;
}

bool somethingremains(int* map[], int w, int h) {
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			if (map[j][i] != -1) {
				return true;
			}
		}
	}
	return false;
}

int main(int argc, char *argv[]) {
	
	int numberOfTests;
		
	ifstream input;
	input.open("B-small-attempt2.in", ios::in);
	input >> numberOfTests;
	
	//cout << numberOfTests << endl;
	
	for (int i = 0; i < numberOfTests; i++) {
		
		int sizeX, sizeY;
		input >> sizeY >> sizeX;
		
		int* map[sizeY];
		std::set<int> elements;
		for (int j = 0; j < sizeY; j++) {
			map[j] = new int[sizeX];
			for (int k = 0; k < sizeX; k++) {
				input >> map[j][k];
				elements.insert(map[j][k]);
			}
		} 
		std::vector<int> velements(elements.begin(), elements.end());
		std::sort(velements.begin(), velements.end());
		//printVector(velements);
		
		
		//printMap(map, sizeX, sizeY);
		bool isPossible = true;
		for (int j = 0; j < velements.size(); j++) {
			
			bool deleted = deleteRows(map, sizeX, sizeY, velements[j]);
			if (!deleted) {
				isPossible = false;
				break;
			}
		}
		
		if (somethingremains(map, sizeX, sizeY)) {
			isPossible = false;
		}
		
		cout << "Case #" << (i+1) << ": " << (isPossible ?  "YES" : "NO") << endl;

		//printMap(map, sizeX, sizeY);
		
		for (int j = 0; j < sizeY; j++) {
			delete [] map[j];
		}
		
	}
	
}