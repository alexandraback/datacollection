#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <set>
#include <cassert>

using namespace std;

ifstream fin ("bsmall.in");
ofstream fout ("bsmall.out");

int T;
int X;
int Y;

int main () {
	fin >> T;
	for (int i = 1; i <= T; i++) {
		fout << "Case #" << i << ": ";
		fin >> X >> Y;
		while (X < 0) {
			fout << "EW";
			X++;
		}
		while (X > 0) {
			fout << "WE";
			X--;
		}
		while (Y < 0) {
			fout << "NS";
			Y++;
		}
		while (Y > 0) {
			fout << "SN";
			Y--;
		}
		fout << '\n';		
	}
	
	return 0;
}
