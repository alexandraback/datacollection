#include "sstream"
#include "iostream"
#include "cstdio"
#include "cstring"
#include "cmath"
#include "algorithm"
#include "vector"
#include "map"
#include "set"
#include "queue"
#include "deque"
#include "list"
#include "string"
#include "cassert"

using namespace std;

struct Triple
{
	int d, w, e, s;
	Triple(int _d, int _w, int _e, int _s) {
		d = _d;
		w = _w;
		e = _e;
		s = _s;
	}

	bool operator < (const Triple &that) const {
		return d < that.d;
	}
};

int main()
{
	const int BASE = 200;
	int T, t = 1;
	for (scanf("%d", &T); T--; ) {
		printf("Case #%d: ", t++);
		vector<Triple> vt;
		int n;
		for (scanf("%d", &n); n--; ) {
			int di, ni, wi, ei, si, ddi, dpi, dsi;
			scanf("%d%d%d%d%d%d%d%d", &di, &ni, &wi, &ei, &si,
				&ddi, &dpi, &dsi);
			for (int k = 0; k < ni; k++) {
				vt.push_back(Triple(di, wi + BASE, ei + BASE, si));
				di += ddi;
				wi += dpi;
				ei += dpi;
				si += dsi;
			}
		}
		sort(vt.begin(), vt.end());
		int wall[BASE*3] = {0}, att[BASE*3] = {0};
		int ans = 0;
		for (int i = 0; i <= vt.size(); i++) {
			/*
			cout<<vt[i].w<<" "<<vt[i].e<<" "<<vt[i].s<<endl;
			for (int j = 0; j < BASE; j++) {
				cout<<wall[j];
			}
			cout<<endl;
			*/
			if (i == vt.size() || i > 0 && vt[i].d > vt[i-1].d) {
				//attack finish
				//build wall
				for (int j = 0; j < BASE*3; j++) {
					wall[j] = max(att[j], wall[j]);
				}
				fill(att, att + BASE*3, 0);
			}
			if (i < vt.size()) {
				//try to attack
				int succ = 0;
				for (int x = vt[i].w; x < vt[i].e; x++) {
					if (wall[x] < vt[i].s) {
						succ = 1;
					}
					att[x] = max(att[x], vt[i].s);
				}
				ans += succ;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

