#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <fstream>
#include <sstream>

using namespace std;


int SolveTestCase(int testCase) {
	int n;
	cin >> n;
	vector<int> s(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		sum += s[i];
	}
	cout << "Case #" << testCase << ":" << endl;
	vector<int> prev(sum + 1, -1);
	prev[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < sum; j++) {
			if (prev[j] != -1) {
				if (prev[j + s[i]] != -1) {
					cout << s[i];
					int pos = j;
					while (pos != 0) {
						cout << " " << pos - prev[pos];
						pos = prev[pos];
					}
					cout << endl;
					pos = j + s[i];
					while (pos != 0) {
						cout << pos - prev[pos] << " ";
						pos = prev[pos];
					}
					cout << endl;
					return 0;
				}
			}
		}
		for (int j = sum - 1; j > -1; j--) {
				if (prev[j] != -1)
					prev[j + s[i]] = j;
			}
	}
	
	
	cout << "Impossible" << endl;
	return 0;
}

int main() {

	//freopen("input.txt", "r", stdin);
	freopen("small.in", "r", stdin);
	//freopen("large.in", "r", stdin);
	
	freopen("output.txt", "w", stdout);
	
	int numCases;
	cin >> numCases;

	for (int testCase = 1; testCase <= numCases; testCase++) {
		cerr << "Case #" << testCase << endl;
		SolveTestCase(testCase);
	}
	return 0;
}