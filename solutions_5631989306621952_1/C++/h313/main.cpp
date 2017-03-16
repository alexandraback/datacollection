#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;


int main() {
	ifstream fin("test.in");
	ofstream fout("test.out");
	int cases;
	fin >> cases;
	for(int c = 1; c <= cases; c++) {
		deque<char> best;
		char a;
		string b;
		fin >> b;
		best.push_back(b[0]);
		for(int i = 1; i < b.size(); i++) {
			if((int)best.front() > (int)b[i]) {
				best.push_back(b[i]);
			}
			else {
				best.push_front(b[i]);
			}
		}
		fout << "Case #" << c << ": ";
		for(int i = 0; i < best.size(); i++) {
			fout << best[i];
		}
		fout << endl;
	}
}