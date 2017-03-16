#include <bits/stdc++.h>
using namespace std;

const int T[8][3] = {{1,2,3},{4,3,6},{7,4,1},{2,5,4},{5,6,7},{0,7,2},{3,0,5},{6,1,0}};

struct Solver {
	long L, X;
	string s;
	Solver() {
		cin >> L >> X >> s;
	}
	int f() {
		int x = 0;
		for (int j = 0; j < L; ++ j) {
			x = T[x][s[j]-'i'];
		}
		return x;
	}
	bool solve() {
		int p = f();
		if (p == 0) {
			return false;
		} else if (p == 4) {
			if (X % 2 != 1) return false;
		} else {
			if (X % 4 != 2) return false;
		}
		vector<bool> visited(8*L);
		int x = 0, y = 0;
		for (int i = 0; i < X; ++ i) {
			for (int j = 0; j < L; ++ j) {
				x = T[x][s[j]-'i'];
				if (visited[x + 8*j]) return false;
				visited[x + 8*j] = true;
				if (y == 0 && x == 1) {
					y = 1;
					visited = vector<bool>(8*L);
				} else if (y == 1 && x == 3) {
					return true;
				}
			}
		}
		return false;
	}
	bool r;
	void run() {
		r = solve();
	}
	int tt_;
	void output() {
		cout << "Case #" << tt_ << ": ";
		cout << (r ? "YES" : "NO") << endl;
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
