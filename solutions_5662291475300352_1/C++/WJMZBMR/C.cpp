#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

typedef long long int64;

struct Hiker {
	int64 T;
	int64 M;
	Hiker(int64 T, int64 M) :
			T(T), M(M) {
	}

	int64 calc(int64 x) {
		if (x <= T)
			return 1;
		x -= T;
		return x / M;
	}
};

int main() {
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		int n;
		cin >> n;
		vector<Hiker> hikers;
		for (int i = 0; i < n; ++i) {
			int64 d, h, m;
			cin >> d >> h >> m;

			for (int j = 0; j < h; ++j) {
				int64 T = 1LL * (360 - d) * 2 * (m + j);
				int64 M = 1LL * 360 * 2 * (m + j);
				hikers.push_back(Hiker(T, M));
			}
		}

		vector<int64> is;
		is.push_back(1);
		for (int i = 0; i < hikers.size(); ++i) {
			for (int j = 0; j <= hikers.size(); ++j) {
				for (int s = -1; s <= 1; ++s) {
					int64 x = hikers[i].T + hikers[i].M * j + s;
					if (x <= 0)
						continue;
					is.push_back(x);
				}
			}
		}

		int64 ans = 1 << 20;
		for (int i = 0; i < is.size(); ++i) {
			int64 cur = 0;
			for (int j = 0; j < hikers.size(); ++j) {
				cur += hikers[j].calc(is[i]);
			}
			ans = min(ans, cur);
		}
		printf("Case #%d: %lld\n", nc, ans);
	}
}
