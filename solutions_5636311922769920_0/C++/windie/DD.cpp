/*
 * https://code.google.com/codejam/contest/9214486/dashboard#s=p0
 * */

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <fstream>

using namespace std;

long long pow(long long base, long long p) {
	if(p == 0) {
		return 1;
	}
	long long sub = pow(base, p / 2);
	return p % 2 ? sub * sub * base : sub * sub;
}

void solveDD() {
	ifstream myfile("D-small-attempt0.in");
	ofstream outfile("D-small-attempt0.out");
	if (!myfile.is_open()) {
		return;
	}
	string line;
	getline(myfile, line);
	stringstream ssline(line);
	int num_case;
	ssline >> num_case;
	for (int i = 0; i < num_case; i++) {
		outfile << "Case #" << i + 1 << ": ";
		getline(myfile, line);
		stringstream ssline(line);
		int K, C, S;
		ssline >> K >> C >> S;
		long long gap = pow(K, C - 1);
		for(long long j = 0; j < K; j++) {
			if(j != 0) {
				outfile << " ";
			}
			outfile << 1 + j * gap;
		}
		outfile << endl;
	}
	outfile.close();
	myfile.close();
}

int main() {
	solveDD();
}
