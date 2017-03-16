#include <bits/stdc++.h>
using namespace std;

struct Solver {
	int Smax;
	string S;
	Solver() {
		cin >> Smax >> S;
	}
	int r;
	void run() {
		int n = 0;
		r = 0;
		for (int i = 0; i < (int)S.length(); ++ i) {
			int x = S[i] - '0';
			if (x) r = max(r, i - n);
			n += x;
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
