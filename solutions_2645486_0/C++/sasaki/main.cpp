#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

int E;

int64_t calc(size_t i, int rE, int R, const vector<int> &v) {
	if (i == v.size())
		return 0;
	int64_t c = 0;
	for (int e = 0; e <= rE; ++e) {
		c = max(c, e * v[i] + calc(i + 1, min(E, rE - e + R), R, v));
	}
	return c;
}

void solve(istream &in, ostream &out) {
	int T;
	in >> T;

	for (int t = 1; t <= T; ++t) {
		int R, N;
		in >> E >> R >> N;
		vector<int> v(N);
		for (int i = 0; i < N; ++i)
			in >> v[i];

		out << "Case #" << t << ": " << calc(0, E, R, v) << endl;
	}
}

int main() {
	solve(cin, cout);
	return 0;
}

