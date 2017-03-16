#include <algorithm>
#include <cstdint>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>

using namespace std;

bool solve(int X, int R, int C) {
	if (X >= 7)
		return true;

	if ((R * C) % X != 0)
		return true;

	if (X > R && X > C)
		return true;

	if ((X + 1) / 2 > min(R, C))
		return true;

	if (X == 4 && min(R, C) == 2)
		return true;

	if (X == 6 && min(R, C) == 3)
		return true;

	return false;
}

int main(int argc, char** argv)
{

	ifstream input("./D-large.in");
	ofstream output("./out.txt");

	int T;
	input >> T;

	for (int i = 1; i <= T; ++i) {
		int x, r, c;
		input >> x >> r >> c;

		output << "Case #" << i << ": ";
		output << (solve(x, r, c) ? "RICHARD" : "GABRIEL") << endl;
	}

	return 0;
}
