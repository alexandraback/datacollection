#include <iostream>
#include <vector>

using namespace std;

typedef long long int T;

struct testcase {
	T a, b, k;

	static testcase* read() {
		testcase *c = new testcase();

		cin >> c->a >> c->b >> c->k;

		return c;
	}
	void solve() {
		T count = 0;
		for (T j = 0; j < a; j++) {
			for (T l = 0; l < b; l++) {
				if ((j & l) < k) {
					count++;
				}
			}
		}
		cout << count << endl;
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
