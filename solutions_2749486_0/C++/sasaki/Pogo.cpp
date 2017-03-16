
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <bitset>
#include <map>
#include <set>
using namespace std;

string calc(int X, int Y) {
	string s;
	if (X > 0)
		for (int i = 0; i < X; ++i)
			s += "WE";
	else if (X < 0)
		for (int i = 0; i < -X; ++i)
			s += "EW";
	if (Y > 0)
		for (int i = 0; i < Y; ++i)
			s += "SN";
	else if (Y < 0)
		for (int i = 0; i < -Y; ++i)
			s += "NS";
	return s;
}

void solve(istream &in, ostream &out) {
	int T;
	in >> T;

	for (int t = 1; t <= T; ++t) {
		int X, Y;
		in >> X >> Y;

		out << "Case #" << t << ": " << calc(X, Y) << endl;
	}
}

int main() {
	solve(cin, cout);
	return 0;
}
