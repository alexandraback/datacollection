#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

struct attack {
	int l, r;
	long long s;

	attack( int _l, int _r, int _s) {
		l = _l;
		r = _r;
		s = _s;
	}
};

vector< long long > s_init, delta_s;
vector< int > l_init, r_init;
vector< int > delta_x;
vector< int > delta_d;
vector< int > first_day;
vector< int > attack_count;

map< int, vector< attack > > A;
map< int, long long > wall_height;

int n;

void solve() {
	cin >> n;
	attack_count.resize(n);
	first_day.resize(n);
	delta_x.resize(n);
	delta_d.resize(n);
	l_init.resize(n);
	r_init.resize(n);
	s_init.resize(n);
	delta_s.resize(n);
	wall_height.clear();
	A.clear();

	for (int i = 0; i < n; i++) {
		cin >> first_day[i] >> attack_count[i] >> l_init[i] >> r_init[i];
		cin >> s_init[i];
		cin >> delta_d[i];
		cin >> delta_x[i];
		cin >> delta_s[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < attack_count[i]; j++) {
			int l = l_init[i] + j * delta_x[i];
			int r = r_init[i] + j * delta_x[i];
			long long s = s_init[i] + j * delta_s[i];
			int day = first_day[i] + j * delta_d[i];

			A[day].push_back(attack(l, r, s));
		}
	}

	long long ans = 0;
	map< int, vector< attack > >::iterator it = A.begin();
	for (; it != A.end(); it++) {
		for (int i = 0; i < it->second.size(); i++) {
			bool ok = false;
			for (int x = it->second[i].l; x < it->second[i].r && !ok; x++)
				if (wall_height[x] < it->second[i].s)
					ok = true;

			ans += ok;
		}

		for (int i = 0; i < it->second.size(); i++) {
			for (int x = it->second[i].l; x < it->second[i].r; x++)
				wall_height[x] = max(wall_height[x], it->second[i].s);
		}
	}

	cout << ans << endl;

	return;
}

int main() {
#ifdef OFFLINE
	freopen("C_input.txt","r", stdin);
	freopen("C_output.txt","w", stdout);
#endif
	int t;
	scanf("%d\n", &t);
	for (int testnum = 0; testnum < t; testnum++) {
		printf("Case #%d: ", testnum + 1);
		solve();
	}
}
