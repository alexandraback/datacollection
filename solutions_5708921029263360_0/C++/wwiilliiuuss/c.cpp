#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>

using namespace std;

const int S = 11;
const int CNT = S * S * S + 5;

typedef pair<int, pair<int, int>> iii;

int main() {
#ifdef _DEBUG
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";

		int j, p, s, k;
		cin >> j >> p >> s >> k;

		int cnt[CNT];
		memset(cnt, 0, CNT * sizeof(int));

		vector<vector<int> > v;

		for (int jj = 1; jj <= j; jj++) {
			int ss = jj;
			for (int pp = 1; pp <= p; pp++) {
				for (int kk = 0; kk < k; kk++) {
					int p[] = { jj, pp, ss };
					int o = jj + pp * S + ss * S * S;
					if (cnt[o] > 0) {
						break;
					}
					cnt[o]++;
					v.push_back(vector<int>(p, p + 3));
					ss = (ss - 1) % s + 1;
				}
			}
		}
		cout << v.size() << endl;
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < 3; j++) {
				cout << v[i][j] << ' ';
			}
			cout << endl;
		}

	}

	return 0;
}