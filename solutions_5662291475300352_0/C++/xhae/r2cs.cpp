#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <sstream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

double EPS = 1e-12;
bool EQ(double a, double b) { return abs(a - b) < EPS; }

struct Hiker {
	double d;
	double speed;

	bool operator < (const Hiker &a) {
		if(!EQ(d, a.d)) return d < a.d;
		if(!EQ(speed, a.speed)) return speed < a.speed;
		return false;
	}
} hikers[10];

int n;

int main(void) {
	int T;
	cin >> T;
	for(int kase = 1; kase <= T; kase++) {
		int _n;
		n = 0;
		cin >> _n;
		while(_n--) {
			int d, h, m;
			cin >> d >> h >> m;
			for(int i = 0; i < h; i++) {
				hikers[n].d =  (double)d / 360.0;
				hikers[n].speed = 1 / (double)(m + i);
				n++;
			}
		}

		int cur = 0;
		for(int i = 1; i < n; i++) if(hikers[i] < hikers[cur]) cur = i;
		int ans = 0;
		while(true) {
//			printf("%lf, %d\n", hikers[cur].d, cur);
			double nextTime = -1;
			for(int i = 0; i < n; i++) {
				if(EQ(hikers[i].speed, hikers[cur].speed)) continue;

				double sgap = abs(hikers[i].speed - hikers[cur].speed);
				double dgap;
				if(hikers[i].speed > hikers[cur].speed) dgap = hikers[cur].d - hikers[i].d;
				else dgap = hikers[i].d - hikers[cur].d;
				if(EQ(dgap, 0)) dgap = 1;
				if(dgap < 0) dgap += 1;

				double candTime = dgap / sgap;
				if(EQ(nextTime, -1) || nextTime > candTime) nextTime = candTime;
			}

			if(EQ(nextTime, -1)) break;
			
			double nextD = hikers[cur].d + hikers[cur].speed * nextTime;
			if(nextD > 1 && !EQ(nextD, 1)) break;
//			printf("\t%lf, ", nextD);

			int nextCand = cur;
			for(int i = 0; i < n; i++) {
				if(EQ(hikers[i].speed, hikers[cur].speed)) continue;

				double nextD2 = hikers[i].d + hikers[i].speed * nextTime;
				while(nextD2 > 1 && !EQ(nextD2, 1)) nextD2 -= 1;
				if(EQ(nextD, nextD2)) {
					if(hikers[i].speed > hikers[cur].speed) ans++;
					else {
						if(hikers[nextCand].speed > hikers[i].speed) nextCand = i;
					}
				}
			}

	//		printf("%d\n", ans);
			if(EQ(nextD, 1)) break;
			for(int i = 0; i < n; i++) {
				hikers[i].d += hikers[i].speed * nextTime;
				while(hikers[i].d > 1 && !EQ(hikers[i].d, 1)) hikers[i].d -= 1;
			}
			cur = nextCand;
			if(ans > 0) break;
		}

		if(ans > 1) ans = 1; // for small 1

		cout << "Case #" << kase << ": " << ans << "\n";
	}

	return 0;
}
