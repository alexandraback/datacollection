/* 
 * File:   A.cpp
 * Author: bgd
 *
 * Created on April 9, 2016, 12:32 AM
 */

#include <cstdlib>
#include<iostream>
#include <vector>
#include<fstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
	int T, N;
	ifstream fin("A-small-attempt0.in");
	ofstream fo("A.small.out");
	fin >> T;
	for (int t = 1; t <= T; ++t) {
		fin >> N;
		int maxx = 1;
		while (maxx <= N) maxx *= 10;
		maxx *= 9;
		int seen = 0;
		for (int i = 1; i <= maxx; ++i) {
			int n = N * i;
			while (n > 0) {
				seen |= (1 << (n % 10));
				n /= 10;
			}
			if (seen == ((1 << 10) - 1)) {
				fo << "Case #" << t << ": " << (N * i) << endl;
				goto next;
			}
		}
		fo << "Case #" << t << ": " << "INSOMNIA" << endl;
next:
		continue;
	}

	return 0;
}

