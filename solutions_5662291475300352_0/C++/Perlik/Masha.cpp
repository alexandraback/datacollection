#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#pragma comment(linker, "/STACK:268435456")

using namespace std;
typedef long long ll;

const int INF = 1e9;

int solve(vector<pair<int, int> >& a) {
	if (a.size() <= 1)
		return 0;
	int pos1 = a[0].first, pos2 = a[1].first;
	int t1 = a[0].second, t2 = a[1].second;
	double speed1 = 360.0 / a[0].second, speed2 = 360.0 / a[1].second;
	if (pos1 > pos2) {
		swap(pos1, pos2);
		swap(speed1, speed2);
		swap(t1, t2);
	}
	if (t1 > t2) {
		double t = (360 - pos1) / speed1;
		double new_pos = pos2 + speed2 * t;
		int ans;
		if (new_pos >= 720)
			ans = 1;
		else
			ans = 0;
		if (!ans)
			return 0;
		t = t2;
		new_pos = pos1 + speed1 * t;
		if (new_pos <= 360)
			ans = 1;
		else
			ans = 0;
		return ans;
	}
	if (t1 == t2)
		return 0;
	double t = (pos2 - pos1) / (speed1 - speed2);
	double pos = t * speed1;
	if (pos >= 360)
		return 0;
	pos = pos1 + speed1 * t;
	double ost = (360 - pos) / speed2;
	double add = pos + ost * speed1;
	if (add >= 720)
		return 1;
	else
		return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		int n;
		vector<pair <int, int> > data;
		cin >> n;
		for (int j = 0; j < n; ++j) {
			int d, h, m;
			cin >> d >> h >> m;
			for (int q = 0; q < h; ++q)
				data.push_back(make_pair(d, m + q));
		}
		cout << "Case #" << i << ": " << solve(data) << "\n";
	}
	return 0;
}