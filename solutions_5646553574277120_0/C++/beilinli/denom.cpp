#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

#define LL long long

bool sub(vector <int> v, int s) {
	int n = v.size();
	for (int mask = 0; mask < (1 << n); mask++) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (mask & (1 << i))
				sum += v[i];
		}
		if (sum == s) return true;
	} return false;
}

int main(void) {
	freopen("C-small-attempt3.in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T, C, D, V;
	cin >> T;

	int p[] = {1, 2, 4, 8, 16};

	for (int t = 1; t <= T; t++) {
		cin >> C >> D >> V;
		int d[D];
		for (int i = 0; i < D; i++) cin >> d[i];

		set <int> s;
		for (int i = 0; i < D; i++) s.insert(d[i]);
		for (int i = 0; i < 5 && p[i] <= V; i++) s.insert(p[i]);

		/*for (int mask = 0; mask < (1 << N); mask++) {
			set <int> s;
			int b = 0;
			for (int i = 0; i < D; i++) s.insert(d[i]);
			for (int i = 0; i < N; i++) {
				if (mask & (1 << i)) {
					s.insert(p[i]);
					b++;
				}
			}

			vector <int> sv(s.begin(), s.end());
			int c = 0;
			for (int i = 1; i <= V; i++) {
				if (sub(sv, i))
					c++;					
			}
			if (c == V) minc = min(minc, (int) s.size());
		}*/

		vector <int> v(s.begin(), s.end());
		//for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
		//cout << '\n';
		printf("Case #%d: %d\n", t, (int) s.size() - D);
	}
	return 0;
}
