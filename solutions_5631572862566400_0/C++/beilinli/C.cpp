#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <sstream>
using namespace std;

int main(void) {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, N;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		int bff[N], maxGroup = 0;

		for (int i = 0; i < N; i++) {
			cin >> bff[i];
			bff[i]--;
		}
		
		for (int mask = 1; mask < (1 << N); mask++) {
			vector <int> curGroup;
			for (int i = 0; i < N; i++) {
				if (mask & (1 << i))
					curGroup.push_back(i);
			}

			do {
				int sz = curGroup.size(), good = 1;
				for (int i = 0; i < sz; i++) {
					if ((bff[curGroup[i]] != curGroup[(i + 1) % sz]) &&
					(bff[curGroup[i]] != curGroup[(i + sz - 1) % sz])) {
						good = 0;
						break;
					}
				}

				if (good)
					maxGroup = max(maxGroup, sz);
			} while (next_permutation(curGroup.begin(), curGroup.end()));
		}

		cout << "Case #" << t << ": " << maxGroup << '\n';
	}
	return 0;
}
