/* 
 * File:   B.cpp
 * Author: bgd
 *
 * Created on April 9, 2016, 1:22 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
	ifstream fin("B-large.in");
	ofstream fout("B.large.out");
	ostream & out = fout;

	int T;
	string S;

	fin >> T;
	for (int t = 1; t <= T; ++t) {
		fin >> S;
		bool flipped = 0;
		int cnt = 0;
		for (int i = S.size() - 1; i >= 0; --i) {
			if (S[i] == '+' && flipped && (i == 0 || S[i-1] == '-')) {
				flipped ^= 1;
				cnt++;
			}
			if (S[i] == '-' && !flipped && (i == 0 || S[i-1] == '+')) {
				flipped ^= 1;
				cnt++;
			}
		}
		out << "Case #" << t << ": " << cnt << endl;
	}
	return 0;
}

