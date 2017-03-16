#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// length, complexity, my tiles
int k, c, s;

ll convert(vector<int>& tile) {
	ll ans = 0;
	for (int i = 0; i < tile.size(); ++i) {
		ans *= k;
		ans += tile[i];
	}
	return ans + 1; // 1-index!
}

int main() {
	int t; cin >> t;
	for (int test = 1; test <= t; ++test) {
		cin >> k >> c >> s;
		if (c * s < k) {
			cout << "Case #" << test << ": IMPOSSIBLE" << endl;
			continue;
		}

		vector<vector<int> > tiles((k + c - 1) / c);
		for (int i = 0; i < tiles.size(); ++i) {
			tiles[i].resize(c);
			for (int j = 0; j < c; ++j) {
				int result = c * i + j;
				if (result < k) tiles[i][j] = result;
				else tiles[i][j] = 0;
			}
		}
		
		cout << "Case #" << test << ":";
		for (int i = 0; i < tiles.size(); ++i) {
			//cout << "(";
			//for (int j = 0; j < tiles[i].size(); ++j) {
			//	cout << tiles[i][j] << " ";
			//}
			//cout << ") ";
			cout << " " << convert(tiles[i]);
		}
		cout << endl;
	}
	return 0;
}