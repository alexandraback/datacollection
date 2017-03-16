#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <bitset>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

void solve(int tcase) {
	printf("Case #%d: ", tcase);
	int n;

	vector<pair<int, int> > vals;

	map<string, int> words;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s, t;
		cin >> s >> t;
		int ids = -1, idt = -1;
		if (words.count(s)) {
			ids = words[s];
		} else {
			words[s] = words.size();
			ids = words[s];
		}

		if (words.count(t)) {
			idt = words[t];
		} else {
			words[t] = words.size();
			idt = words[t];
		}

		vals.push_back(make_pair(ids, idt));
	}

	int res = 0;
	for (int i = 0; i < (1 << n); ++i) {
		set<int> havefirst;
		set<int> havesecond;

		vector<int> bad;
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				havefirst.insert(vals[j].first);
				havesecond.insert(vals[j].second);
			} else {
				bad.push_back(j);
			}
		}

		bool good = true;
		for (int j = 0; j < bad.size(); ++j) {
			if (havefirst.count(vals[bad[j]].first) &&
				havesecond.count(vals[bad[j]].second)) {
				continue;
			}
			good = false;
		}

		if (good) {
			res = max(res, (int)bad.size());
		}
	}
	cout << res << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		solve(i + 1);
	}


	return 0;
}
