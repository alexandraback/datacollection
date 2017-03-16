#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <stdio.h>

using namespace std;

struct ordcompare {
	const vector<int> &ord;
	ordcompare(const vector<int> &o) : ord(o) {}

	bool operator() (int i, int j) {
		return ord[i] < ord[j] || (ord[i] == ord[j] && i < j);
	}
};

struct testcase {
	int N, M;
	vector<int> codes;
	vector<int> from;
	vector<int> to;

	static testcase* read() {
		testcase *c = new testcase();

		cin >> c->N >> c->M;

		for (int i = 0; i < c->N; i++) {
			int code;
			cin >> code;
			c->codes.push_back(code);
		}

		for (int i = 0; i < c->M; i++) {
			int a, b;
			cin >> a >> b;
			a--; b--;

			c->from.push_back(a);
			c->to.push_back(b);
			
			c->from.push_back(b);
			c->to.push_back(a);
		}
		c->M *= 2;
		assert(c->from.size() == c->to.size() && c->to.size() == c->M);

		return c;
	}
	void put(int i) {
		char x[10];
		sprintf(x, "%5d", i);
		cout << x;
	}
	bool can_visit_all(int begin) {
		cerr << "CVA(" << begin << ") = ";
		vector<bool> x(N, false);
		x[begin] = true;
		while (true) {
			bool u = false;
			for (int i = 0; i < M; i++) {
				if (x[from[i]] && !x[to[i]]) {
					x[to[i]] = true;
					u = true;
				}
			}
			if (!u) break;
		}
		bool r = true;
		for (int i = 0; i < N; i++) if (!x[i]) r = false;
		cerr << r << endl;
		return r;
	}

	string evaluate(const vector<int> &tree, int root) {
		char x[10];
		sprintf(x, "%5d", codes[root]);
		string s = x;

		vector<int> children;
		for (int i = 0; i < N; i++) {
			if (i == root) continue;
			if (tree[i] == root) children.push_back(i);
		}
		sort<vector<int>::iterator, ordcompare> (children.begin(), children.end(), ordcompare(codes));

		for (int i = 0; i < children.size(); i++) {
			s += evaluate(tree, children[i]);
		}
		return s;
	}

	void remove(vector<int> &tree, int root) {
		tree[root] = -1;
		for (int i = 0; i < N; i++) {
			if (tree[i] == root) remove(tree, i);
		}
	}

	void solve() {
		int min = -1;
		for (int i = 0; i < N; i++) {
			if (!can_visit_all(i)) continue;
			if (min == -1 || codes[i] < codes[min]) min = i;
		}

		assert(min != -1);
		assert(can_visit_all(min));

		vector<int> tree(N, -1);
		tree[min] = min;

		while (true) {
			bool u = false;
			for (int i = 0; i < M; i++) {
				if (tree[from[i]] != -1 && tree[to[i]] == -1) {
					tree[to[i]] = from[i];
					u = true;
				}
			}
			if (!u) break;
		}

		// Optimize!
		while (true) {
			bool u = false;
			for (int i = 0; i < N; i++) {
				if (i == min) continue;
				vector<int> rm_tree = tree;
				remove(rm_tree, i);

				vector<int> better_tree = tree;

				for (int j = 0; j < M; j++) {
					if (rm_tree[from[j]] != -1 && to[j] == i) {
						better_tree[i] = from[j];
						if (evaluate(better_tree, min) < evaluate(tree, min)) {
							tree = better_tree;
							u = true;
						}
					}
				}
			}
			if (!u) break;
		}

		cout << evaluate(tree, min) << endl;

	}
};

struct problem {
	int ncases;
	vector<testcase*> cases;

	void read() {
		cases.clear();
		cin >> ncases;
		for (int i = 0; i < ncases; i++) {
			cases.push_back(testcase::read());
		}
	}
	void solve() {
		for (int i = 0; i < ncases; i++) {
			cout << "Case #" << (i+1) << ": ";
			cases[i]->solve();
		}
	}
};

int main() {
	problem p;
	p.read();
	p.solve();

	return 0;
}
