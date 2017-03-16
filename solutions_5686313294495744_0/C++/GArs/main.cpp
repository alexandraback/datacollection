#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const double EPS = 1e-9;
const ll INF = 1e17;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("file.in", "r", stdin);
	freopen("file.out", "w", stdout);

	int t;
	cin >> t;

	for (int num = 1; num <= t; num++) {
		int n;
		cin >> n;

		vector<pair<string, string> > a(n);

		for (int i = 0; i < n; i++) {
			cin >> a[i].first >> a[i].second;
		}

		int ans = 0;

		cerr << num << "\n";

		for (int msk = 0; msk < (1 << n); msk++) {
			map<string, bool> side1, side2;
			int nowAns = 0;

			vector<pair<string, string> > firstly, secondly;

			for (int i = 0; i < n; i++) {
				if ((msk >> i) & 1) {
					secondly.push_back(a[i]);
				} else {
					firstly.push_back(a[i]);
				}
			}

			for (int i = 0; i < (int)firstly.size(); i++) {
				if (side1[firstly[i].first] && side2[firstly[i].second]) {
					nowAns++;
				}

				side1[firstly[i].first] = 1;
				side2[firstly[i].second] = 1;
			}

			for (int i = 0; i < (int)secondly.size(); i++) {
				if (side1[secondly[i].first] && side2[secondly[i].second]) {
					nowAns++;
				}

				side1[secondly[i].first] = 1;
				side2[secondly[i].second] = 1;
			}

			ans = max(ans, nowAns);
		}

		cout << "Case #" << num << ": " << ans << "\n";
	}

	return 0;
}
