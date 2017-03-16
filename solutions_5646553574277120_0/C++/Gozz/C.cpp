#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int C, D, V;
		cin >> C >> D >> V;
		vector<int> ds;
		for (int i = 0; i < D; ++i) {
			int d;
			cin >> d;
			ds.push_back(d);
		}
		ds.push_back(V + 1);

		int nd = 0;
		int maxval = 0;
		int ind = 0;
		while (maxval < V) {
			if (maxval + 1 < ds[ind]) {
				maxval += C * (maxval + 1);
				++nd;
			} else {
				maxval += C * ds[ind++];
			}
		}

		cout << "Case #" << t << ": " << nd << endl;
	}
	return 0;
}
