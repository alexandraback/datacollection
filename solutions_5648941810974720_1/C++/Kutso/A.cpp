#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

const int NMAX = 100100;

pair <int, string> P[10];

int main() {
	P[0] = make_pair<int, string>(0, "ZERO");
	P[1] = make_pair<int, string>(2, "TWO");
	P[2] = make_pair<int, string>(6, "SIX");
	P[3] = make_pair<int, string>(8, "EIGHT");
	P[4] = make_pair<int, string>(4, "FOUR");
	P[5] = make_pair<int, string>(1, "ONE");
	P[6] = make_pair<int, string>(3, "THREE");
	P[7] = make_pair<int, string>(5, "FIVE");
	P[8] = make_pair<int, string>(7, "SEVEN");
	P[9] = make_pair<int, string>(9, "NINE");

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		printf("Case #%d: ", test);
		string s;
		cin >> s;
		int n = s.size();
		vector <int> cnt(26);
		vector <int> ans;

		for (int i = 0; i < n; i++)
			cnt[s[i] - 'A']++;

		while (1) {
			bool found = false;
			for (int i = 0; i < 10; i++) {
				bool valid = true;
				for (int k = 0; k < P[i].second.size(); k++) {
					char c = P[i].second[k];
					if (cnt[c-'A'] == 0) {
						valid = false;
						break;
					}					
				}
				if (valid) {
					found = true;
					ans.push_back(P[i].first);
					for (int k = 0; k < P[i].second.size(); k++)
						cnt[P[i].second[k] - 'A']--;
					break;
				}
			}
			if (!found)
				break;
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
			printf("%d", ans[i]);

		printf("\n");
	}


	return 0;
}