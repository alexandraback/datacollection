#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int n;
		cin >> n;
		set<double> a, b;
		for (int i = 0; i < n; ++i) {
			double w;
			cin >> w;
			a.insert(w);
		}
		for (int i = 0; i < n; ++i) {
			double w;
			cin >> w;
			b.insert(w);
		}

		set<double> a1 = a, b1 = b;
		int war = 0;
		for (int i = 0; i < n; ++i) {
			double w = *a.begin();
			a.erase(a.begin());
			set<double>::iterator it = b.lower_bound(w);
			if (it == b.end()) {
				++war;
				b.erase(b.begin());
			} else {
				b.erase(it);
			}
		}

		a = a1; b = b1;
		int dec = 0;
		for (int i = 0; i < n; ++i) {
			if (*a.begin() > *b.begin()) {
				++dec;
				a.erase(a.begin());
				b.erase(b.begin());
			} else {
				a.erase(a.begin());
				set<double>::iterator it = b.end();
				--it;
				b.erase(it);
			}
		}

		cout << "Case #" << test << ": " << dec << " " << war << endl;
	}
}
