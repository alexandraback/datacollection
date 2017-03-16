#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;


int computeNValue(string& name, int n) {
	int size = name.size();
	int result = 0;

	for(int s = 0; s <= size - 1; s++) {
		int score = 0;
		for(int i = s; i <= size-1; i++) {
			if(name[i] == 'a' || name[i] == 'e' ||name[i] == 'i' || name[i] == 'o' || name[i] =='u') {
				score = 0;
			}
			else {
				score++;
				if(score >= n) {
					/* from s to i, we have n consecutive cons */
					/* we have also at least n consecutive cons for all end between i + 1 and L-1 */
					result += size - 1 - i + 1;
					goto nextStart;
				}
			}
		}

		nextStart:;
	}
	return result;
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
		string name;
		int n;
		inFile >> name >> n;

		int result = computeNValue(name, n);
		
		outFile << "Case #" << t + 1 << ": " << result << endl;
	}
	outFile.close();
	inFile.close();

	cout << endl << "Stop" << endl;

	system("PAUSE");
	return 0;
}
