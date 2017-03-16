#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

typedef long long ll;
typedef stringstream ss;

#define sz(v)		((int) v.size())
#define fv(v, i)	for (int i = 0; i < sz(v); ++i)
#define fn(n, i)	for (int i = 0; i < n; ++i)

#define FILENAME	"C-small-0"

void findSubsets(vector<int>& set, int& mask1, int& mask2) {
	map<int, int> m;
	fn((1 << 20), i) {
		int s = 0;
		fn(20, j) {
			if (i & (1 << j)) {
				s += set[j];
			}
		}
		if (m.find(s) != m.end()) {
			mask1 = i;
			mask2 = m[s];
			return;
		}
		m[s] = i;
	}
}

void printSubet(ofstream& out, vector<int>& set, int mask) {
	fn(20, i) {
		if (mask & (1 << i)) out << set[i] << ' ';
	}
	out << endl;
}

int main() {
	ifstream in(FILENAME ".in");
	ofstream out(FILENAME ".out");

	int T;
	in >> T;
	for (int test = 1; test <= T; ++test) {
		vector<int> m(20);
		in >> m[0];
		fn(20, i) {
			in >> m[i];
		}
		int first = 0, second = 0;
		findSubsets(m, first, second);

		out << "Case #" << test << ":" << endl;
		if (first == 0 && second == 0) {
			out << "Impossible" << endl;
		} else {
			printSubet(out, m, first);
			printSubet(out, m, second);
		}
	}

	return 0;
}
