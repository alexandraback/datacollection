#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <bitset>
#include <assert.h>
#include "combination.hpp"
using namespace std;

int N;
vector<pair<string, string>> L;
int result = 0;
int maxval;

bool check(int minval)
{
	std::vector<int> combi;
	for (int i = 0; i < maxval; i++) combi.push_back(i);
	do {
		set<string> s;
		for (int i = 0; i < minval; i++) {
			s.insert(L[combi[i]].first);
			s.insert(L[combi[i]].second);
		}
		set<int> n;
		for (int i = minval; i < maxval; i++) {
			n.insert(combi[i]);
		}
		while (!n.empty()) {
			bool found = false;
			for (auto i : n) {
				if (s.find(L[i].first) != s.end() && s.find(L[i].second) != s.end()) {
					n.erase(i);
					found = true;
					break;
				}
			}
			if (!found) break;
		}
		if (n.empty()) return true;
	} while(boost::next_combination(combi.begin(), combi.begin() + minval, combi.end()));
	return false;
}

void solve()
{
	maxval = (int) L.size();
	if (maxval <= 2) {
		result = 0;
		return;
	}

	int minval = 1;
	while (1 << minval < maxval) minval++;
	for (; minval <= maxval; minval++) {
		if (check(minval)) {
			break;
		}
	}
	if (minval > maxval) {
		result = 0;
	} else {
		result = maxval - minval;
	}
}

int main(int argc, char* argv[])
{
	if (argc >= 2) {
		FILE* fp = freopen(argv[1], "r", stdin);
	}

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		L.clear();
		cin >> N;
		while (N--) {
			string a, b;
			cin >> a >> b;
			L.push_back(make_pair(a, b));
		}
		solve();
		cout << "Case #" << i + 1 << ": ";
		cout << result << endl;
	}

	return 0;
}
