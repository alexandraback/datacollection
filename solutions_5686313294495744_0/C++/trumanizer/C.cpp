#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#define max(a, b) ((a > b) ? a : b)
#define TEST

using namespace std;

void solve(int test) {
	int n;
	cin >> n;
	vector<pair<string, string> > topics(n);
	for (int i = 0; i < n; i++) 
		cin >> topics[i].first >> topics[i].second;

	int res = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		vector<pair<string, string> > fake, real;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if ((mask & (1 << i)) != 0) fake.push_back(topics[i]);
			else real.push_back(topics[i]);
		}

		bool ok = true;
		for (int i = 0; i < fake.size(); i++) {
			bool found = false;
			for (int j = 0; j < real.size(); j++) {
				if (fake[i].first == real[j].first) {
					found = true;
					break;
				}
			}
			if (!found) {
				ok = false;
				break;
			}
		}

		if (ok) {
			for (int i = 0; i < fake.size(); i++) {
				bool found = false;
				for (int j = 0; j < real.size(); j++) {
					if (fake[i].second == real[j].second) {
						found = true;
						break;
					}
				}
				if (!found) {
					ok = false;
					break;
				}
			}
		}

		if (ok) res = max(res, fake.size());
	}

	cout << "Case #" << test << ": " << res << endl;
}

int main()
{
	#ifndef TEST
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);
	int tt; cin >> tt;
	for (int i = 1; i <= tt; i++)
		solve(i);
}
