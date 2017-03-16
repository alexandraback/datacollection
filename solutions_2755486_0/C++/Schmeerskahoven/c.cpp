#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct tribe {
	ssize_t dday;
	ssize_t nattacks;
	ssize_t w,e;
	ssize_t s;
	ssize_t dd,dp,ds;
	tribe(){}
	tribe(istream& in) {
		in >> dday >> nattacks >> w >> e >> s >> dd >> dp >> ds;
	}
	ssize_t strength (ssize_t day) {
		return max(s + ds * (day-dday)/dd,(ssize_t)0);
	}
	ssize_t right(ssize_t day) {
		return e + dp * (day-dday)/dd;

	}
	ssize_t left(ssize_t day) {
		return w + dp * (day-dday)/dd;

	}
	bool attacks(ssize_t day) {
		if (day < dday) return false;
		return (day-dday) % dd == 0 and day < dday+dd*nattacks;
	}
};

int solve(int n) {
	vector<tribe> tribes(n);
	ssize_t max_last_day = 0;
	for (int i = 0; i < n; ++i) {
		tribes[i] = tribe(cin);
		max_last_day = max(tribes[i].dday + (tribes[i].nattacks-1)*tribes[i].dd, max_last_day);
	}
	map<ssize_t, ssize_t> wall;	
	map<ssize_t, ssize_t> prev;
	ssize_t acc = 0;
	for (ssize_t d = 0; d <= max_last_day; ++d) {
		prev = wall;
		for (int t = 0; t < n; ++t) {
			if (!tribes[t].attacks(d)) continue;
			ssize_t w = tribes[t].left(d);
			ssize_t e = tribes[t].right(d);
			ssize_t s = tribes[t].strength(d);
			
		bool success = false;
			//cerr << "Tribe " <<(1+t) << " Attacks on day " << d << " at the range " << w << ", " << e << " with strength " << s;
			for (ssize_t p = 2*w; p <= 2*e; ++p) {
				if (!success and prev[p] < s) {
					++acc;
				//	cerr << " attack succeeds at position " << (float)p/2.0 << endl;
					success = true;
					for (ssize_t q = 2*w; q < p; ++q ) {
						wall[q] = max(wall[q],s);
					}
				}
				if (success) {
					wall[p] = max(wall[p], s);

				}
			}
//			if (!success) cerr  << " attack failed ";
					//cerr << endl;
		}
	}
	return acc;
	
}

int main() {
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) {
		int n; cin >> n;
		cerr << "case " << i << endl;
		cout << "Case #" << i << ": " << solve(n) << endl;
	}
}

