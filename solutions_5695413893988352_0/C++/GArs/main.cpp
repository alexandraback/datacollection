#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const double EPS = 1e-9;
const ll INF = 4e18;

string tmpc, tmpj;

ll toNum(string s) {
	ll num = 0;

	for (int i = 0; i < (int)s.size(); i++) {
		num *= 10;
		num += s[i] - '0';
	}

	return num;
}

ll getAns(string c, string j, int i) {
	bool less;

	if (i < (int)c.size() && c[i] < j[i]) {
		less = 1;
	} else if (i < (int)c.size()) {
		less = 0;
	}

	while (i < (int)c.size()) {
		if (c[i] == '?') {
			c[i] = (less ? '9' : '0');
		}

		if (j[i] == '?') {
			j[i] = (less ? '0' : '9');
		}

		i++;
	}

	tmpc = c;
	tmpj = j;

	return abs(toNum(c) - toNum(j));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("file.in", "r", stdin);
	freopen("file.out", "w", stdout);

	int n;
	cin >> n;

	for (int num = 1; num <= n; num++) {
		string c, j;
		cin >> c >> j;

		int i = 0;
		ll ans = INF;
		string cans, jans;

		while (i < (int)c.size() && (c[i] == '?' || j[i] == '?' || c[i] == j[i])) {
			if (c[i] == '?' && j[i] == '?') {
				c[i] = j[i] = '0';

				c[i] = '1';
				ll nowAns = getAns(c, j, i);

				if (nowAns < ans || (nowAns == ans && make_pair(cans, jans) > make_pair(tmpc, tmpj))) {
					ans = nowAns;
					cans = tmpc;
					jans = tmpj;
				}

				c[i] = '0';
				j[i] = '1';
				nowAns = getAns(c, j, i);

				if (nowAns < ans || (nowAns == ans && make_pair(cans, jans) > make_pair(tmpc, tmpj))) {
					ans = nowAns;
					cans = tmpc;
					jans = tmpj;
				}

				c[i] = j[i] = '0';
			} else if (c[i] == '?') {
				if (j[i] != '9') {
					c[i] = j[i] + 1;
					ll nowAns = getAns(c, j, i);

					if (nowAns < ans || (nowAns == ans && make_pair(cans, jans) > make_pair(tmpc, tmpj))) {
						ans = nowAns;
						cans = tmpc;
						jans = tmpj;
					}
				}

				if (j[i] != '0') {
					c[i] = j[i] - 1;
					ll nowAns = getAns(c, j, i);

					if (nowAns < ans || (nowAns == ans && make_pair(cans, jans) > make_pair(tmpc, tmpj))) {
						ans = nowAns;
						cans = tmpc;
						jans = tmpj;
					}
				}

				c[i] = j[i];
			} else {
				if (c[i] != '9') {
					j[i] = c[i] + 1;
					ll nowAns = getAns(c, j, i);

					if (nowAns < ans || (nowAns == ans && make_pair(cans, jans) > make_pair(tmpc, tmpj))) {
						ans = nowAns;
						cans = tmpc;
						jans = tmpj;
					}
				}

				if (c[i] != '0') {
					j[i] = c[i] - 1;
					ll nowAns = getAns(c, j, i);

					if (nowAns < ans || (nowAns == ans && make_pair(cans, jans) > make_pair(tmpc, tmpj))) {
						ans = nowAns;
						cans = tmpc;
						jans = tmpj;
					}
				}

				j[i] = c[i];
			}

			i++;
		}

		ll nowAns = getAns(c, j, i);

		if (nowAns < ans || (nowAns == ans && make_pair(cans, jans) > make_pair(tmpc, tmpj))) {
			ans = nowAns;
			cans = tmpc;
			jans = tmpj;
		}

		cout << "Case #" << num << ": " << cans << " " << jans << "\n";
	}

	return 0;
}
