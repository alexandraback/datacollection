#include <bits/stdc++.h>
using namespace std;

int T[4][4][4] = {
	{
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1},
	},
	{
		{0,1,0,1},
		{1,1,1,1},
		{0,1,0,1},
		{1,1,1,1},
	},
	{
		{0,0,0,0},
		{0,0,1,0},
		{0,1,1,1},
		{0,0,1,0},
	},
	{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,1},
		{0,0,1,1},
	},
};

struct Solver {
	int X, R, C;
	Solver() {
		cin >> X >> R >> C;
	}
	void run() {
	}
	int tt_;
	void output() {
		cout << "Case #" << tt_ << ": ";
		cout << (T[X-1][R-1][C-1] ? "GABRIEL" : "RICHARD") << endl;
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
