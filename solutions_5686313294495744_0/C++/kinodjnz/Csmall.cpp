#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <string.h>

typedef long long ll;
using namespace std;

int solve(const vector<pair<string, string>> &topics_s) {
	int k = 0;
	map<string, int> words;
	vector<pair<int, int>> topics;
	for (auto j = topics_s.begin(); j != topics_s.end(); ++j) {
		int a, b;
		auto it = words.find(j->first);
		if (it != words.end()) {
			a = it->second;
		} else {
			a = k;
			words[j->first] = k;
			k++;
		}
		it = words.find(j->second);
		if (it != words.end()) {
			b = it->second;
		} else {
			b = k;
			words[j->second] = k;
			k++;
		}
		topics.emplace_back(a, b);
	}
	int n = topics.size();
	int ans = 0;
	for (int i = 0; i < (1<<n); i++) {
		set<int> dict_a;
		set<int> dict_b;
		for (int j = 0; j < n; j++) {
			if (i&(1<<j)) {
				dict_a.insert(topics[j].first);
				dict_b.insert(topics[j].second);
			}
		}
		bool found = true;
		for (int j = 0; j < n; j++) {
			if (!(i&(1<<j))) {
				if (!(dict_a.count(topics[j].first) && dict_b.count(topics[j].second))) {
					found = false;
					break;
				}
			}
		}
		if (found) {
			ans = max(ans, n - __builtin_popcount(i));
		}
	}
	return ans;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		vector<pair<string, string>> topics;
		for (int j = 0; j < n; j++) {
			string a, b;
			cin >> a >> b;
			topics.push_back(make_pair(a, b));
		}
		int ans = solve(topics);
		printf("Case #%d: %d\n", i+1, ans);
	}
}
