#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct event {
	int d, w, e, s, t;
	event(int _d, int _w, int _e, int _s, int _t):d(_d), w(_w), e(_e), s(_s), t(_t) {}
	bool operator<(const event& b) const {
		return d < b.d || (d == b.d && (w < b.w || (w == b.w && (e < b.e || (e == b.e && (s < b.s || (s == b.s && (t < b.t))))))));
	}
};
vector<int> wall(10000);
vector<int> ld_attack(10000);
void test(int num) {
	cout << "Case #" << num << ": ";
	int n;
	cin >> n;
	set<event> q;
	for (int i = 0; i < n; i++) {
		int d, tn, w, e, s, dd, dp, ds;
		cin >> d >> tn >> w >> e >> s >> dd >> dp >> ds;
		for (int j = 0; j < tn; j++)
			q.insert(event(d + dd * j, w + dp * j, e + dp * j, s + ds * j, i));
	}
	wall.assign(10000, 0);
	ld_attack.assign(10000, 0);
	int cur_day = 0;
	int max_s_ld = 0;
	int result = 0;
	for (set<event>::iterator p = q.begin(); p != q.end(); p++) {
		event ev = *p;
		if (p->d != cur_day) {
			for (int i = 0; i < 10000; i++)
				wall[i] = max(wall[i], ld_attack[i]);
			cur_day = p->d;
		}
		bool sf = false;
		for (int i = p->w; i < p->e; i++) {
			if( wall[i + 5000] < p->s) sf = true;
			ld_attack[5000+i] = max(ld_attack[5000+i],p->s);
		}
		if(sf) result++;
	}
	cout << result << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		test(i+1);
}
