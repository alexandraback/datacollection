#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

struct hiker {
	int d, m;
	double speed;
	hiker() {}
	hiker(int d, int m) : d(d), m(m) {
		speed = 360.0 / m;
	}
	bool operator < (const hiker &pt) const {
		return d == pt.d ? m > pt.m : d < pt.d;
	}
};
int n;
vector<hiker> vec;
void solve() {
	// Same Speed
	bool same_speed = true;
	for (int i = 0; i < n - 1; i++) {
		if (vec[i].m != vec[i + 1].m) {
			same_speed = false;
			break;
		}
	}
	if (same_speed) {
		cout << 0 << endl;
		return;
	}
	
	// 1 hiker
	if (n == 1) {
		cout << 0 << endl;
		return;
	}
	
	// 2 hikers
	if (n == 2) {
		// hiker1 is faster
		if (vec[0].m < vec[1].m) {
			LL s1 = (vec[0].d == vec[1].d) ? 720 : vec[1].d - vec[0].d + 360, s2 = 360 - vec[1].d;
			if (s1 * vec[0].m <= s2 * (vec[1].m - vec[0].m)) {
				cout << 1 << endl;
			} else {
				cout << 0 << endl;
			}
		} else { // hiker2 is faster
			LL s1 = 360 - vec[1].d + vec[0].d, s2 = 360 - vec[0].d;
			if (s1 * vec[1].m <= s2 * (vec[0].m - vec[1].m)) {
				cout << 1 << endl;
			} else {
				cout << 0 << endl;
			}
		}
		return;
	}
}
int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	for (int cas = 1; cas <= ts; cas++) {
		printf("Case #%d: ", cas);
		int group;
		cin >> group;
		vec.clear();
		for (int i = 0; i < group; i++) {
			int d, h, m;
			cin >> d >> h >> m;
			for (int j = 0; j < h; j++) {
				vec.PB(hiker(d, m + j));
			}
		}
		n = vec.size();
		sort(vec.begin(), vec.end());
		solve();
	}
	return 0;
}

