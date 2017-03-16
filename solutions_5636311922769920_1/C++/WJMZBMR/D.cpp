#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
using namespace std;

typedef long long int64;

int main() {
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		int K, C, S;
		cin >> K >> C >> S;
		if (S * C < K) {
			printf("Case #%d: %s\n", nc, "IMPOSSIBLE");
			continue;
		}
		set<int64> ans;
		for (int i = 0; i < K;) {
			int64 x = 0;
			for (int j = 0; j < C; ++j) {
				x = x * K;
				int d = i++;
				if (d >= K)
					d = 0;
				x += d;
			}
			ans.insert(x + 1);
		}
		printf("Case #%d: ", nc);
		for (set<int64>::iterator e = ans.begin(); e != ans.end(); ++e) {
			cout << " " << *e;
		}
		cout << endl;
	}
	return 0;
}
