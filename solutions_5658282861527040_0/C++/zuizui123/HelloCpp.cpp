#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define fi "B-small-attempt0.in"
#define fo "out.txt"
const int MAXN = 100 + 5;
const int INF = 1000000000;

int main() {
	freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);

	int T, A, B, K;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		cin >> A >> B >> K;
		int res = 0;
		for (int i = 0; i < A; ++i) {
			for (int k = 0; k < B; ++k) {
				int num = i & k;
				if (num < K) {
					++res;
				}
			}
		}
		cout << res << endl;
	}
}
