#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <map>

using namespace std;

int main() {
	fstream fin;
	fin.open("input.txt");
	int cases = 0;
	fin >> cases;
	for (int rnd = 0; rnd < cases; ++rnd) {
		// Do each case here
		int N;
		fin >> N;
		map<int, int> soldier_count;
		for (int i = 0; i < 2 * N - 1; ++i) {
			for (int j = 0; j < N; ++j) {
				int num;
				fin >> num;
				if (soldier_count.find(num) == soldier_count.end()) {
					soldier_count[num] = 1;
				} else {
					soldier_count[num]++;
				}
			}
		}
		cout << "Case #" << rnd+1 << ":";
		for (auto it = soldier_count.begin(); it != soldier_count.end(); ++it) {
			if (it->second % 2) { //Seen an odd number of times
				cout << " " << it->first ;
			}
		}
		cout << endl;
		// 
	}
	fin.close();
	return 0;
}