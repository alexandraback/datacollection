#include <iostream>
#include <set>
using namespace std;

int main() {
	int testcases,N;
	set<double> ken, naomi, ken2, naomi2;
	cin >> testcases;
	for (int tc = 1; tc <= testcases; tc++) {
		cin >> N;

		double val;
		naomi.clear();
		ken.clear();
		for (int n = 0; n < N; n++) {
			cin >> val;
			naomi.insert(val);
		}
		for (int n = 0; n < N; n++) {
			cin >> val;
			ken.insert(val);
		}
		ken2 = ken;
		naomi2 = naomi;

		int dw_points = 0;
		while (!naomi.empty()) {
			auto ks = ken.begin();
			auto ns = naomi.upper_bound(*ks);
			if (ns != naomi.end()) {
				ken.erase(ks);
				naomi.erase(ns);
				dw_points++;
				continue;
			}
			ns = naomi.begin();
			ks = ken.end();
			ks--;
			ken.erase(ks);
			naomi.erase(ns);
		}

		int w_points = 0;
		while (!naomi2.empty()) {
			auto ns = naomi2.begin();
			auto ks = ken2.upper_bound(*ns);
			if (ks == ken2.end()) {
				w_points++;
				ks = ken2.begin();
			}
			naomi2.erase(ns);
			ken2.erase(ks);
		}

		cout << "Case #" << tc << ": " << dw_points << ' '
			<< w_points << endl;
	}
}
