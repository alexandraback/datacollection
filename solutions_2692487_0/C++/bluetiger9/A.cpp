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
#define FoR(i, a, b) for(int i = (a); i < (b); ++i)
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
		int A, N;
		list<int> m;

		in >> A >> N;
		FOR(i, N) {
			int x;
			in >> x;
			m.push_back(x);
		}

		m.sort();

		auto it = m.begin();
		while ((it != m.end()) && (*it < A)) {
			A += *it;
			it = m.erase(it);
		}

		if (A == 1) {
			out << "Case #" << tt << ": " << m.size() << endl; continue;
		}

		int best = m.size();
		int step = 0;
		int i = 0;
		for (int x : m) {
			i++;
			while (x >= A)
				A = 2 * A - 1, step++;
			A += x;

			if (step + m.size() - i < best)
				best = step + m.size() - i;
		}

		out << "Case #" << tt << ": " << best << endl;
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
