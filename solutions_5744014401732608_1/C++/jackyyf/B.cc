#include <bits/stdc++.h>

using namespace std;

long mp[64][64];

int main(void) {
	assert(sizeof(long) == 8);
	long T;
	cin >> T;
	for(long t = 1; t <= T; ++ t) {
		cout << "Case #" << t << ": ";
		int64_t B, M;
		cin >> B >> M;
		if ((1 << (B - 2)) < M) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			cout << "POSSIBLE" << endl;
			memset(mp, 0, sizeof mp);
			for(long i = 1; i < B - 1; ++ i) {
				for(long j = i + 1; j < B - 1; ++ j) {
					mp[i][j] = 1;
				}
			}
			for(long i = 1; i < B - 1; ++ i) {
				mp[i][B - 1] = 1;
			}
			if (M == (1 << (B - 2))) {
				mp[0][B - 1] = 1;
				-- M;
			}
			long now = B - 2;
			while(M > 0) {
				mp[0][now] = (M & 1);
				M >>= 1;
				-- now;
			}
			for (long i = 0; i < B; ++ i) {
				for (long j = 0; j < B; ++ j) {
					cout << mp[i][j];
				}
				cout << endl;
			}
		}
	}

}
