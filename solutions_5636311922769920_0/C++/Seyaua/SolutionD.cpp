#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
#include <cstdio>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

void fractiles(long long k, long long c, long long s) {
	set<long long> rems;
	for (long long i = 0; i < k; ++i) {
		rems.insert(i);
	}

	set<long long> ans;

	while (!rems.empty()) {
		long long curvalue = 0;
		for (int i = 0; i < c; ++i) {
			long long crem = rems.empty() ? 0 : *rems.begin();
			if (!rems.empty()) {
				rems.erase(rems.begin());
			}
			curvalue *= k;
			curvalue += crem;
		}
		ans.insert(curvalue);
	}
	if (ans.size() > s) {
		cout << " IMPOSSIBLE" << endl;
	} else {
		for (const auto& x : ans) {
			cout << " " << x + 1;
		}
		cout << endl;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		long long k, c, s;
		cin >> k >> c >> s;
		cout << "Case #" << i + 1 << ":";
		fractiles(k, c, s);
	}

	return 0;
}