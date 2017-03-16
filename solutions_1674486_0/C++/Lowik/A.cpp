#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;


typedef unsigned __int64	u64 ;
typedef signed	 __int64	si64 ;
typedef unsigned int		u32 ;

bool AddReachable(const int n, vector<int>& reachable, const vector<int>& m, const vector< vector<int> >& father ) {
	vector<int> new_reach;
	for(size_t i = 0; i < m[n]; i++) {
		if(find(reachable.begin(), reachable.end(), father[n][i]) == reachable.end()) {
			reachable.push_back(father[n][i]);
			new_reach.push_back(father[n][i]);
		}
		else {
			return true;
		}
	}

	for(size_t i = 0; i < new_reach.size(); i++) {
		if(AddReachable(new_reach[i], reachable, m, father)) {
			return true;
		}
	}

	return false;
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
	for(int t = 0; t < T; t++) {
		u32 N = 0;
		inFile >> N;
		vector<int> m(N, 0);
		vector< vector<int> > father(N);
		for(int n = 0; n < N; n++) {
			inFile >> m[n];
			father[n] = vector<int>(m[n], 0);
			for(int i = 0; i < m[n]; i++) {
				inFile >> father[n][i];
				father[n][i] -= 1;
			}
		}
		
		bool result = false;
		
		for(int x = 0; x < N; x++) {
			vector<int> reacchable;
			if(AddReachable(x, reacchable, m, father)) {
				outFile << "Case #" << t+1 << ": " << "Yes" << endl;
				goto Next;
			}
		}
		outFile << "Case #" << t+1 << ": " << "No" << endl;
		Next:;
	}
	outFile.close();
	inFile.close();

	system("PAUSE");
	return 0;
}
