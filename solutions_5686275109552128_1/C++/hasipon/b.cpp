#include <bits/stdc++.h>
using namespace std;

struct Solver {
	int D;
	vector<int> P;
	Solver() {
		cin >> D;
		P.resize(D);
		for (int& x : P) cin >> x;
	}
	int r;
	void run() {
		r = 1<<30;
		for (int i = 1; i <= r; ++ i) {
			int rr = i;
			for (int x : P) rr += (max(x - i, 0) + i-1) / i;
			r = min(r, rr);
		}
		for (int i = 0; i < r; ++ i) {
			sort(P.begin(), P.end());
			r = min(r, P.back() + i);
			int x = P.back() / 2;
			P.back() -= x;
			P.push_back(x);
		}
	}
	int tt_;
	void output() {
		cout << "Case #" << tt_ << ": ";
		cout << r << endl;
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
