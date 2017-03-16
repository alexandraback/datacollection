#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

const int NMAX = 10010;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		int n;
		cin >> n;
		vector <pair <int, int> > hikers;
		for (int i = 0; i < n; i++) {
			int start, num, time;
			cin >> start >> num >> time;
			for (int j = 0; j < num; j++)
				hikers.push_back(make_pair(start, time++));
		}

		//0
		int ans = 1;
		double time0 = ((360 - hikers[0].first) / 360.) * hikers[0].second;
		double time1 = ((360 - hikers[1].first) / 360.) * hikers[1].second;
		
		int cnt = 0;
		double diff = fabs(time0 - time1), times = 0.;
		if (time0 < time1) {
			times = diff / hikers[0].second;
		}
		else
			times = diff / hikers[1].second;

		if (times < 1)
			ans = 0;

		if (hikers.size() > 2)
			ans = -1;

		cout << "Case #" << test << ": " << ans << endl;
	}

	return 0;
}