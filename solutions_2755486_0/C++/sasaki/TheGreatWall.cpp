
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <bitset>
#include <map>
#include <set>
using namespace std;

struct Attack {
	int w, e, s;
	Attack(int w, int e, int s) :
			w(w), e(e), s(s) {
	}
};

struct Solver {
	map<int, vector<Attack> > _attacks;
	map<int, int> _heights;

	void push(int d, int n, int w, int e, int s, int delta_d, int delta_p,
			int delta_s) {
		for (int i = 0; i < n; ++i) {
			int day = d + delta_d * i;
			int p = delta_p * i;
			_attacks[day].push_back(Attack(w + p, e + p, s + delta_s * i));
		}
	}

	int calc() {
		int c = 0;
		for (const auto &p : _attacks) {
			for (auto &a : p.second)
				if (check(a))
					++c;
			for (auto &a : p.second)
				update(a);
		}
		return c;
	}

	bool check(const Attack &a) {
		for (int i = a.w; i < a.e; ++i) {
			if (_heights[i] < a.s)
				return true;
		}
		return false;
	}

	void update(const Attack &a) {
		for (int i = a.w; i < a.e; ++i)
			_heights[i] = max(_heights[i], a.s);
	}
};

void solve(istream &in, ostream &out) {
	int T;
	in >> T;

	for (int t = 1; t <= T; ++t) {
		int N;
		in >> N;

		Solver solver;
		for (int i = 0; i < N; ++i) {
			int d, n, w, e, s, delta_d, delta_p, delta_s;
			in >> d >> n >> w >> e >> s >> delta_d >> delta_p >> delta_s;
			solver.push(d, n, w, e, s, delta_d, delta_p, delta_s);
		}

		out << "Case #" << t << ": " << solver.calc() << endl;
	}
}

int main() {
	solve(cin, cout);
	return 0;
}
