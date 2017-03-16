#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <unordered_map>
#include <vector>
#include <set>
#include <unordered_set>
#include <cmath>
#include <list>
#include <boost/format.hpp>

// =================== SOME USEFULL DEFINES ======================================
#define fi first
#define se second
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define FoR(i, a, b) for(int i = (a); i <= (b); ++i)
#define sqr(x) ((x)*(x))
#define pow2(x) (1 << (x))
#define btw(x, a, b) ((a <= x) && (x <= b))
#define hmap unordered_map
#define hset unordered_set
#define ll long long
#define ull unsigned long long
#define ld long double
// ===============================================================================

using namespace std;

istream& ioIN(int argc, const char **argv);
ostream& ioOUT(int argc, const char **argv);

int main(int argc, const char **argv) {
	istream &in = ioIN(argc, argv);
	ostream &out = ioOUT(argc, argv);

	int T;

	in >> T; //in.ignore();

	for (int tt = 1; tt <= T; ++tt) {
		int N, X, Y;
		in >> N >> X >> Y;
		X = abs(X);

		int i = 1, n = 1;
		while (N > n + 2 * i + 1)
			n += 2 * i + 1, i += 2;

		if (X + Y < i) {
			out << "Case #" << tt << ": " << 1.0 << endl;
		} else if (X + Y > i + 1) {
			out << "Case #" << tt << ": " << 0.0 << endl;
		} else {
			i += 2; N -= n;
			vector<double> p(i);
			double prob = 1.0;
			FOR(k, min(N, i - 1)) {
				n++;
				prob /= 2.0;
				FoR(j, 0, k)
					p[j] += prob;
			}
			FOR(k, min(N - i + 1, i - 1)) {
				FoR(j, 0, i - 2)
					p[j] += prob;
				prob *= 2.0;
			}

			out << "Case #" << tt << ": " << p[Y] << endl;
		}
	}

	return 0;
}

// ===============================================================================

istream& ioIN(int argc, const char **argv) {
	if (argc > 1)
		return *(new ifstream(argv[1]));
	return cin;
}

ostream& ioOUT(int argc, const char **argv) {
	if (argc > 2)
		return *(new ofstream(argv[2]));
	return cout;
}
