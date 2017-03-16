#include <bits/stdc++.h>
using namespace std;

struct Solver {
	int X, R, C;
	Solver() {
		cin >> X >> R >> C;
	}
	bool solve(int x, int y) {
		if (x * y % X != 0) return false;
		if (X == 1) return true;
		if (X == 2) return true;
		if (X == 3) return x >= 2;
		if (X == 4) return x >= 3;
		if (X == 5) return x >= 4 || (x == 3 && y >= 10);
		if (X == 6) return x >= 4;
		return false;
	}
	bool r;
	void run() {
		r = solve(min(R,C), max(R,C));
	}
	int tt_;
	void output() {
		cout << "Case #" << tt_ << ": ";
		cout << (r ? "GABRIEL" : "RICHARD") << endl;
	}
};

int main() {
	int T;
	cin >> T;
	vector<future<Solver*>> results;
	for (int tt = 1; tt <= T; ++ tt) {
		auto a = new Solver;
		a->tt_ = tt;
		results.push_back(async(
			launch::async, // async or deferred
			[](Solver* solver) {
				solver->run();
				return solver;
			},
			a
		));
	}
	for (auto& x : results) {
		auto a = x.get();
		a->output();
		delete a;
	}
}
