#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <utility>
#include <set>
using namespace std;

bool mark(vector<vector<int> >& minefield, int currR, int currC, int& currEmpty, int neededEmpty, vector<pair<int, int> >& exploredIndices) {
	int rows = minefield.size();
	int cols = minefield[0].size();
	bool stuffAdded = false;
	//vector<pair<int, int> > exploredIndices;
	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			if (i == 0 && j ==0) {
				continue;
			}
			if (currR + i < 0 || currR + i > rows - 1 || currC + j < 0 || currC + j > cols - 1) {
				continue;
			}
			if (minefield[currR + i][currC + j] == -1) {
				minefield[currR + i][currC + j] = 1;
				currEmpty++;
				exploredIndices.push_back(pair<int, int>(currR + i, currC + j));
				stuffAdded = true;
			}
		}
	}
	if (currEmpty > neededEmpty) {
		for (vector<pair<int, int> >::iterator itt = exploredIndices.begin(); itt != exploredIndices.end(); ++itt) {
			minefield[itt->first][itt->second] = -1;
			currEmpty--;
		}
		exploredIndices.clear();
		return false;
	}
	else {
		return stuffAdded;
	}
}

bool solve(vector<vector<int> >& minefield,  size_t mines, int startR, int startC, int caseNum) {
	int rows = minefield.size();
	int cols = minefield[0].size();
	int neededEmptySpaces = rows*cols - mines; 
	vector<vector<int> > tempmf = minefield;
	
	// 0 = click -1 = mine 1 = empty space
	// try corner
	int currR = startR;
	int currC = startC;
	int emptySpaces = 0;
	bool solution = false;
	// if there is nowhere to click
	if (neededEmptySpaces == 0) {
		return false;
	}
	vector<pair<int, int> > oldExploredIndices;
	if (neededEmptySpaces > 0) {
		minefield[currR][currC] = 0;
		emptySpaces++;
		vector<pair<int, int> > tempExploredIndices;
		if (!mark(minefield, currR, currC, emptySpaces, neededEmptySpaces, oldExploredIndices)) {

		}
		else {
			set<pair<int, int>> tabu_list;
			bool resetIndices = false;
			pair<int, vector<pair<int, int> > > backoutIndices = make_pair(-1, vector<pair<int, int>>());
			while (emptySpaces != neededEmptySpaces) {
				bool successfulAdd = false;
				bool allSuccessful = true;
				vector<pair<int, int> > exploredIndices;
				
				for (vector<pair<int, int> >::iterator it = oldExploredIndices.begin(); it != oldExploredIndices.end(); ++it) {
					vector<pair<int, int> > tempExploredIndices;
					if (mark(minefield, it->first, it->second, emptySpaces, neededEmptySpaces, tempExploredIndices)) {
						successfulAdd = true;
						for (int i = 0; i < tempExploredIndices.size(); ++i) {
							exploredIndices.push_back(tempExploredIndices[i]);
						}
						backoutIndices = make_pair(distance(oldExploredIndices.begin(), it), tempExploredIndices);
					}
					else {
						allSuccessful = false;
					}
					if (emptySpaces == neededEmptySpaces) {
						goto done;
					}
				}
				if (allSuccessful) {
					for (int i = 0; i < exploredIndices.size(); ++i) {
						oldExploredIndices.push_back(exploredIndices[i]);
					}
				}
				else {
					for (int i = 0; i < exploredIndices.size(); ++i) {
						oldExploredIndices.push_back(exploredIndices[i]);
					}
				}

				if (successfulAdd == false) {
					if (backoutIndices.second.size() != 0) {
						//minefield[oldExploredIndices[backoutIndices.first].first][oldExploredIndices[backoutIndices.first].second] = -1;
						oldExploredIndices.erase(oldExploredIndices.begin() + backoutIndices.first);
						tabu_list.insert(oldExploredIndices[backoutIndices.first]);
						for (vector<pair<int, int> >::iterator itt = backoutIndices.second.begin(); itt != backoutIndices.second.end(); ++itt) {
							--emptySpaces;
							minefield[itt->first][itt->second] = -1;
						}
						int backoutSize = backoutIndices.second.size();
						oldExploredIndices.erase(oldExploredIndices.end() - backoutSize, oldExploredIndices.end());
						// reset backout indices???
						backoutIndices = make_pair(-1, vector<pair<int, int>>());
						resetIndices = true;
					}
					if (oldExploredIndices.size() == 0) {
						break;
					}
				}
				if (backoutIndices.second.size() == 0 && resetIndices == false) {
					break;
				}
				resetIndices = false;
			}
		}
	}
done:
	return emptySpaces == neededEmptySpaces;
}


void printBoard(vector<vector<int> > minefield, int caseNum, bool success) {
	cout << "Case #" << caseNum << ":" << endl;
	if (success) {
		for (int i = 0; i < minefield.size(); ++i) {
			for (int j = 0; j < minefield[i].size(); ++j) {
				if (minefield[i][j] == 0) {
					cout << 'c';
				}
				else if (minefield[i][j] == -1) {
					cout << '*';
				}
				else {
					cout << '.';
				}
			}
			cout << endl;
		}
	}
	else {
		cout << "Impossible" << endl;
	}
}

int main(void){
	int numCases;
	cin >> numCases;
	for (int ii = 0; ii < numCases; ++ii) {
		size_t rows;
		size_t cols;
		size_t mines;
		cin >> rows;
		cin >> cols;
		cin >> mines;
		vector<vector<int> >  minefield(rows, vector<int>(cols, -1));
		bool success = solve(minefield, mines, 0, 0, ii+1);
		if (success) {
			printBoard(minefield, ii + 1, success);
		}
		else {
			minefield = vector<vector<int>>(rows, vector<int>(cols, -1));
			if (rows > 1) {
				printBoard(minefield, ii + 1, solve(minefield, mines, 1, 0, ii+1));
			}
			else {
				printBoard(minefield, ii + 1, success);
			}
		}
		
	}
	return 0;
}