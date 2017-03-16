#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	
	ifstream fin;
	fin.open("A-small-attempt1.in");
	ofstream fout;
	fout.open("A-small-attempt1.out");
	
	int T;
	fin >> T;
	
	for (int i = 1; i <= T; i++) {
		int R, C, W;
		fin >> R >> C >> W;
		fout << "Case #" << i << ": " << (R - 1) * (C / W) + (C / W - 1) + (W + (C % W ? 1 : 0)) << endl;
	}
	
	return 0;
}
