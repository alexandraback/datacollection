#include <fstream>
#include <utility>

using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int T;
	in >> T;
	for (int test = 1; test <= T; test++) {
		int X, R, C;
		in >> X >> R >> C;
		if (R < C) { swap(R, C); }
		out << "Case #" << test << ": ";

		if ((R * C) % X) {
			out << "RICHARD" << endl;
			continue;
		}

		if (X >= 7) {
			out << "RICHARD";
		}
		else if (X == 6) {
			if (C <= 3) {
				out << "RICHARD";
			}
			else {
				out << "GABRIEL";
			}
		}
		else if (X == 5) {
			if (C <= 2) {
				out << "RICHARD";
			}
			else if (C == 3) {
				if (R == 5) {
					out << "RICHARD";
				}
				else {
					out << "GABRIEL";
				}
			}
			else {
				out << "GABRIEL";
			}
		}
		else if (X == 4) {
			if (C <= 2) {
				out << "RICHARD";
			}
			else {
				out << "GABRIEL";
			}
		}
		else if (X == 3) {
			if (C == 1) {
				out << "RICHARD";
			}
			else {
				out << "GABRIEL";
			}
		}
		else {
			out << "GABRIEL";
		}
		out << endl;
	}
	return 0;
}