#include <iostream>
#include <vector>
using namespace std;


int main() {
	freopen("D-large.in", "r", stdin);
	freopen("D-large.out", "w", stdout);
	int T;
	cin >> T;
	
	for (int t = 1; t <= T; ++t) {
		int k, c, s;
		cin >> k >> c >> s;
		vector<long long> ans;

		int j = 0;
		for (int i = 0; i < s && j < k; ++i) {
			long long x = 0, v = 0;
			while (x < c && j + x < k) {
				v = v*k + x + j;
				x++;
			}

			j = j + x;
			ans.push_back(v+1);
		}

		if (j < k){
			cout << "Case #" << t << ": IMPOSSIBLE\n";
		}
		else {
			cout << "Case #" << t << ":";
			for (int i = 0; i < ans.size(); ++i)
				cout << " " << ans[i];

			cout << endl;
		}
	}
}