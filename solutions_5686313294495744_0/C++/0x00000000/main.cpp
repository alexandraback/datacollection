#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string>
#include <tuple>
#include <queue>
#include <utility>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <limits>
#include <new>
#include <functional>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main(void) {
	cin.tie(nullptr);
	cin.sync_with_stdio(false);

	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		int N;
		cin >> N;
		vector<pair<string, string>> data(N);
		map<string, int> mp1, mp2;
		for (int i = 0; i < N; i++) {
			cin >> data[i].first >> data[i].second;
			if (!mp1.count(data[i].first)) {
				mp1.insert(make_pair(data[i].first, 1));
			}
			else {
				mp1[data[i].first]++;
			}
			if (!mp2.count(data[i].second)) {
				mp2.insert(make_pair(data[i].second, 1));
			}
			else {
				mp2[data[i].second]++;
			}
		}
		queue<int> cand;
		set<string> s1, s2;
		for (int i = 0; i < data.size(); i++) {
			pair<string, string>& x = data[i];
			if (mp1[x.first] > 1 && mp2[x.second] > 1) {
				cand.push(i);
			}
			else {
				if (!s1.count(x.first)) s1.insert(x.first);
				if (!s1.count(x.second)) s2.insert(x.second);
			}
		}
		int counter = 0;
		while (!cand.empty()) {
			int val = cand.front();
			cand.pop();
			if (s1.count(data[val].first) && s2.count(data[val].second)) {
				counter++;
			}
			else {
				pair<string, string>& x = data[val];
				if (!s1.count(x.first)) s1.insert(x.first);
				if (!s1.count(x.second)) s2.insert(x.second);
			}
		}
		
		cout << "Case #" << k + 1 << ": ";
		cout << counter;
		cout << endl;
	}

	return 0;
}