#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main() {
	freopen("A.in", "r", stdin);
	freopen("A1.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int n;
		cin >> n;
		vector<pair<string, string>> v;
		
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			string A, B;
			cin >> A >> B;
			v.push_back(make_pair(A, B));
		}

		for (int i = 0; i < (1 << n); ++i) {
			map<string, int> m1;
			map<string, int> m2;
			for (int j = 0; j < n; ++j) 
				if (((i >> j) & 1) == 0) {
					m1[v[j].first]++;
					m2[v[j].second]++;
				}

			bool ok = true;
			int cnt = 0;
			for (int j = 0; j < n; ++j)
				if (((i >> j) & 1) == 1) {
					if (!(m1.find(v[j].first) != m1.end() && m2.find(v[j].second) != m2.end())) {
						ok = false;
						break;
					}
					cnt++;

				}

			if (ok == true && ans < cnt)
				ans = cnt;

		}
		cout << "Case #" << t + 1 << ": " << ans << endl;
	}
}