#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
using namespace std;


int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int N;
		scanf("%d", &N);
		vector<double> A(N), B(N);
		for (auto& x : A) scanf("%lf", &x);
		for (auto& x : B) scanf("%lf", &x);
		B.push_back(1.1);
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		int y = 0;
		auto b = B.begin();
		for (auto x : A) if (x > *b) {
				y++;
				b++;
		}
		set<double> S;
		B.pop_back();
		copy(B.begin(), B.end(), inserter(S, S.begin()));
		int z = 0;
		for (auto& x: A) {
			auto t = S.upper_bound(x);
			if (t == S.end()) z++;
			else S.erase(t);
		}

		printf("Case #%d: %d %d\n", t+1, y, z);
	}
	return 0;
}
