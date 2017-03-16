#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef unsigned long long ull;

struct Hiker {
	ull s, r;
	Hiker(ull s, ull r):s(s),r(r){};
	Hiker(){};
};

void solve()
{
	ull n;
	cin >> n;
	vector<Hiker> hike;
	for (ull i=0; i<n; i++) {
		ull s, h, m;
		cin >> s >> h >> m;
		for (ull j=0; j<h; j++) {
			hike.push_back(Hiker(s, m+j));
		}
	}
	if (n <= 1) {
		cout << "0";
		return;
	}
	// n == 2
	ull t_goal0 = (360 - hike[0].s) * hike[0].r;
	ull t_goal1 = (360 - hike[1].s) * hike[1].r;
	double p_other0 = hike[0].s + t_goal1 / hike[0].r;
	double p_other1 = hike[1].s + t_goal0 / hike[1].r;
	if (t_goal0 <= t_goal1) {
		if (p_other0 >= 720) {
			cout << "1";
			return;
		} else {
			cout << "0";
			return;
		}
	} else {
		if (p_other1 >= 720) {
			cout << "1";
			return;
		} else {
			cout << "0";
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ull t;
	cin >> t;
	for (ull tn=1; tn<=t; tn++) {
		cout << "Case #" << tn << ": ";
		solve();
		cout << "\n";
	}
	return 0;
}
