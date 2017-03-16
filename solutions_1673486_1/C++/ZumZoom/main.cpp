#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int A, B;
		cin >> A >> B;
		vector <double> C(A);
		for(int i = 0; i < A; ++i)
			cin >> C[i];
		double ans = B + 2, prob = 1;
		for(int i = 0; i < A; ++i)
			prob *= C[i];
		ans = min(ans, (1 - prob) * (2 * B - A + 2) + prob * (B - A + 1));
		for(int i = 1; i <= A; ++i) {
			prob /= C[A - i];
			ans = min(ans, (1 - prob) * (2 * B - A + 2 + 2 * i) + prob * (B - A + 1 + 2 * i));
		}
		cout << "Case #" << t << ": ";
		printf("%.6lf\n", ans);
	}

	return 0;
}