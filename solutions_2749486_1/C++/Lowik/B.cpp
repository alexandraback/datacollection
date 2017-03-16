#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

#define EAST	0
#define NORTH	1
#define WEST	2
#define SOUTH	3

static char dirName[4] = {'E', 'N', 'W', 'S'};

static int dx[4] = {1, 0, -1, 0};
static int dy[4] = {0, 1, 0, -1};

void findSolution(int X, int Y, vector<char>& solution) {
	for(int i = 0; i < 100000000; i++) {
		if(Y == 0 && X == 0) {
			return;
		}
		else if(abs(X) < i+1 && abs(Y) < i+1) {
			int xtimes = (int)sqrt((double)abs(X));
			int ytimes = (int)sqrt((double)abs(Y));
			if(X < 0) {
				for(int k = 0; k < xtimes; k++) {
					solution.push_back('E');
				}
				for(int k = 0; k < xtimes; k++) {
					solution.push_back('W');
				}
				X += xtimes*xtimes;

				for(int j = 0; j < X; j++) {
					solution.push_back('E');
					solution.push_back('W');
					X += 1;
				}
			}
			else if(X > 0) {
				for(int k = 0; k < xtimes; k++) {
					solution.push_back('W');
				}
				for(int k = 0; k < xtimes; k++) {
					solution.push_back('E');
				}
				X -= xtimes*xtimes;
				for(int j = 0; j < X; j++) {
					solution.push_back('W');
					solution.push_back('E');
					X -= 1;
				}
			}
			else {

			}

			if(Y < 0) {
				for(int k = 0; k < ytimes; k++) {
					solution.push_back('N');
				}
				for(int k = 0; k < ytimes; k++) {
					solution.push_back('S');
				}
				Y += ytimes * ytimes;
				for(int j = 0; j < Y; j++) {
					solution.push_back('N');
					solution.push_back('S');
					Y += 1;
				}
			}
			else if(Y > 0) {
				for(int k = 0; k < ytimes; k++) {
					solution.push_back('S');
				}
				for(int k = 0; k < ytimes; k++) {
					solution.push_back('N');
				}
				Y -= ytimes * ytimes;

				for(int j = 0; j < Y; j++) {
					solution.push_back('S');
					solution.push_back('N');
					Y -= 1;
				}
			}
			else {
				
			}
		}
		else if(abs(Y) > abs(X) && abs(X) >= i+1) {
			if(X > 0) {
				solution.push_back('E');
				X -= (i+1);
			}
			else if(X < 0) {
				solution.push_back('W');
				X += (i+1);
			}
		}
		else if(abs(Y) > abs(X) && abs(X) < i+1) {
			if(Y > 0) {
				solution.push_back('N');
				Y -= (i+1);
			}
			else {
				solution.push_back('S');
				Y += (i+1);
			}
		}
		else if(abs(X) >= abs(Y) && abs(Y) >= i+1) {
			if(Y > 0) {
				solution.push_back('N');
				Y -= (i+1);
			}
			else {
				solution.push_back('S');
				Y += (i+1);
			}	
		}
		else if(abs(X) >= abs(Y) && abs(Y) < i+1) {
			if(X > 0) {
				solution.push_back('E');
				X -= (i+1);
			}
			else if(X < 0) {
				solution.push_back('W');
				X += (i+1);
			}
		}
		else {
			cout << "Strange!" << endl;
		}
	}
	cout << "Can't find solution!" << endl;
}

int main(int argc, char* argv[]) {
	string inTestName, outTestName;

	cout << "Enter the in test file name : " << endl;
	cin >> inTestName;
	cout << endl;

	size_t found = inTestName.find_last_of(".");
	outTestName = inTestName.substr(0, found) + ".out";

	/* Open file */
	ifstream inFile(inTestName.c_str());
	if(!inFile.is_open()) {
		cout << "Can't open input file" << endl;
		system("PAUSE");
		return 1;
	}

	ofstream outFile(outTestName.c_str());
	if(!outFile.is_open()) {
		cout << "Can't open output file" << endl;
		system("PAUSE");
		return 1;
	}

	int T; /*number of tests */
	inFile >> T;

	cout << "Start : "<< endl;
	for(int t = 0; t < T; t++) {
		cout << "\rProcess test " << t << " out of " << T;
		int X, Y;
		inFile >> X >> Y;

		vector<char> solution;
		findSolution(X, Y, solution);

		outFile << "Case #" << t + 1 << ": ";
		for(size_t i = 0; i < solution.size(); i++) {
			outFile << solution[i];
		}
		outFile << endl;
	}
	outFile.close();
	inFile.close();

	cout << endl << "Stop" << endl;

	system("PAUSE");
	return 0;
}
