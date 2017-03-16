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

void solveBB() {
	ifstream myfile("B-small-attempt0.in");
	ofstream outfile("B-small-attempt0.out");
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
		string s;
		ssline >> s;
		if(s.size() == 0) {
			outfile << 0 << endl;
			continue;
		}
		int cnt = 0;
		for(int i = 1; i < s.size(); i++) {
			if(s[i] != s[i-1]) {
				cnt++;
			}
		}
		if(cnt == 0 && s[0] == '+') {
			outfile << 0 << endl;
		}else if(cnt == 0 && s[0] == '-') {
			outfile << 1 << endl;
		}else if(cnt % 2 == 0 && s[0] == '+') {
			outfile << cnt << endl;
		}else if(cnt % 2 == 0 && s[0] == '-') {
			outfile << cnt + 1 << endl;
		}else if(cnt % 2 == 1 && s[0] == '+') {
			outfile << cnt + 1 << endl;
		}else {
			outfile << cnt << endl;
		}
	}
	outfile.close();
	myfile.close();
}

int main() {
	solveBB();
}
