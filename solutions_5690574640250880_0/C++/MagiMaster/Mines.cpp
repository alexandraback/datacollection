#include <iostream>
using namespace std;

class Mines {
public:
	void go(istream &in, ostream &out) {
		int t, r, c, m;

		in >> t;

		for (int i = 1; i <= t; ++i) {
			out << "Case #" << i << ":" << endl;

			in >> r >> c >> m;
			
			int b = r*c - m;

			if (r == 1 || c == 1) {
				for (int j = 0; j < b; ++j) {
					if (j == 0)
						out << "c";
					else
						out << ".";
					if (c == 1)
						out << endl;
				}
				for (int j = 0; j < m; ++j) {
					out << "*";
					if (c == 1)
						out << endl;
				}
				if (c != 1)
					out << endl;
			} else {
				if (b == 1) {
					for (int y = 0; y < r; ++y) {
						for (int x = 0; x < c; ++x) {
							if (x == 0 && y == 0)
								out << "c";
							else
								out << "*";
						}
						out << endl;
					}
				} else if (b == 2 || b == 3 || b == 5 || b == 7 || (b % 2 == 1 && (r == 2 || c == 2))) {
					out << "Impossible" << endl;
				} else if(b < 2*c + 2) {
					int last = (b % 2 == 1 ? 3 : 0);
					int rest = (b - last) / 2;

					for (int y = 0; y < r; ++y) {
						for (int x = 0; x < c; ++x) {
							if (y < r - 3) {
								out << "*";
							} else if (y == r - 3) {
								if (x < last)
									out << ".";
								else
									out << "*";
							} else {
								if (x == 0 && y == r - 1)
									out << "c";
								else if (x < rest)
									out << ".";
								else
									out << "*";
							}
						}
						out << endl;
					}
				} else {
					int off = 0;
					if (b % c == 1)
						off = 1;

					int n = 0;
					for (int y = 0; y < r; ++y) {
						for (int x = 0; x < c; ++x) {
							if (n < m - off) {
								out << "*";
								++n;
							} else if (n < m && x == 0) {
								out << "*";
								++n;
							} else if (x == c - 1 && y == r - 1) {
								out << "c";
							} else {
								out << ".";
							}
						}
						out << endl;
					}
				}
			}
		}
	}
};