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

void solveAA() {
	ifstream myfile("A-small-attempt0.in");
	ofstream outfile("A-small-attempt0.out");
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
		long long N;
		ssline >> N;
		vector<bool> dic(10, false);
		long long times = 0;
		long long res = -1;
		while(1) {
			++times;
			long long M = N * times;
			long long tmp = M;
			while(tmp) {
				int digit = tmp % 10;
				tmp /= 10;
				dic[digit] = true;
			}
			bool isEnd = true;
			for(int j = 0; j < 10; j++) {
				if(!dic[j]) {
					isEnd = false;
					break;
				}
			}
			if(isEnd) {
				res = M;
				break;
			}
			if(times > 1 && M == N) {
				break;
			}
		}
		if(res == -1) {
			outfile << "INSOMNIA" << endl;
		}else{
			outfile << res << endl;
		}
	}
	outfile.close();
	myfile.close();
}

int main() {
	solveAA();
}
