#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin ("D.in");
ofstream fout ("D.out");

// 1 x y: GABRIEL
// 2 x y: GABRIEL if and only if x>1 || y>1
// 3 x y: GABRIEL if and only if y > 1 and (x == 3 or y ==3) 
// 4 x y: x = 2, y = 2 then RICHARD
//	: x = 4, y = 2 then RICHARD
//	: x = 4, y = 3 then GABRIEL
//	: x = 4, y = 4 then GABRIEL

int main() {
	int T;
	fin >> T;
	string winner;
	int temp;
	for (int c = 1; c <= T; c++) {
		int X, x, y;
		fin >> X >> x >> y;
		if (x < y) {
			temp = x;
			x = y;
			y = temp;
		}
		if (X == 1) winner = "GABRIEL";
		if (X == 2) {
			if (x > 1 && (x % 2 == 0 || y % 2 == 0)) winner = "GABRIEL";
			else winner = "RICHARD";
		} 
		if (X == 3) {
			if (x != 3 && y !=3) winner = "RICHARD";
			else if (y == 1) winner = "RICHARD";
			else winner = "GABRIEL";
		}
		if (X == 4) {
			if (x == 4 && y > 2) winner = "GABRIEL";
			else winner = "RICHARD";
		}
		fout << "Case #" << c << ": " << winner << endl;
	}
}
