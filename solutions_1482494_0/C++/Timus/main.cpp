#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int tests;
	cin >> tests;
	for (int testnum = 1; testnum <= tests; ++testnum) {
		int N;
		cin >> N;
		vector<int> col;
		vector<pair<int, int> > z;
//		a.resize(N);
//		b.resize(N);
		z.resize(N);
		col.resize(N);
		for (int i = 0; i < N; ++i)
			cin >> z[i].first >> z[i].second;
		int bsteps = 1e9;
		bool ans = false;
		for (int it = 0; it < 1e4; ++it) {
		random_shuffle(z.begin(), z.end());
		col.clear();
		col.resize(N);

		int tekcol = 0;
		int best = 0, besti = -1;
		int steps = 0;
		while (1) {
			best = 0, besti = -1;
			for (int i = 0; i < N; ++i) {
				if (col[i] == 2)
					continue;
				if (z[i].second <= tekcol)
					if (best < 2 - col[i])
						best = 2 - col[i], besti = i;
				if (z[i].first <= tekcol)
					if (best < 1 - col[i])
						best = 1 - col[i], besti = i;
			}
			if (best == 0)
				break;
			col[besti] += best;
			tekcol += best;
			++steps;
//			for (int i = 0; i < N; ++i)
//				cerr << col[i] << " ";
//			cerr << endl;
		}
			if (tekcol == N * 2)
				ans = true;
			bsteps = min(bsteps, steps);
		}
//		cerr << "@" << endl)
		if (ans)
			cout << "Case #" << testnum << ": " << bsteps << endl;
		else cout << "Case #" << testnum << ": Too Bad" << endl;
	}
}
