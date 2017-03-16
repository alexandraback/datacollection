#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	fstream fin;
	fin.open("input.txt");
	int cases = 0;
	fin >> cases;
	for (int rnd = 0; rnd < cases; ++rnd) {
		// Do each case here
		string input;
		fin >> input;
		string res;
		res += input[0];
		for (int i = 1; i < input.length(); ++i) {
			if (input[i] < res[0]) {
				res += input[i];
			} else {
				res = input[i] + res;
			}
		}
		cout << "Case #" << rnd+1 << ": " << res << endl;
	}
	fin.close();
	return 0;
}