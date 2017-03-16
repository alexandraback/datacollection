#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <functional>

using namespace std;

struct attack {
	int d, w, e, s;
	bool operator<(const attack &rhs) const { return d < rhs.d; }
	bool operator>(const attack &rhs) const { return d > rhs.d; }
};

void doit(int casenum) {
	int N;
	cin >> N;
	priority_queue<attack, vector<attack>, greater<attack> > q;
	
	for (int i = 0; i < N; ++i) {
		int d, n, w, e, s, dd, dp, ds;
		cin >> d >> n >> w >> e >> s >> dd >> dp >> ds;
		for (int j = 0; j < n; ++j) {
			attack a;
			a.d = d + j * dd;
			a.w = w + j * dp;
			a.e = e + j * dp;
			a.s = s + j * ds;
			q.push(a);
		}
	}
	
	vector<int> curwall(401);
	vector<int> needwall(401);
	
	int lastd = -1;
	int lost = 0;
	while (!q.empty()) {
		attack cur = q.top();
		q.pop();
		if (lastd == -1) lastd = cur.d;
		if (lastd != cur.d) {
			curwall = needwall;
			lastd = cur.d;
		}
		
		bool lostthis = false;
		for (int i = 200 + cur.w; i < 200 + cur.e; ++i) {
			needwall[i] = max(needwall[i], cur.s);
			if (curwall[i] < cur.s) lostthis = true;
		}
		if (lostthis) lost++;
		//cerr << cur.d << ' ' << cur.w << ' ' << cur.e << ' ' << cur.s << ' ' << (lostthis ? "lost" : "won") << endl;
	}
	int ans = lost;

	cout << "Case #" << casenum << ": " << ans << endl;
}

int main() {
	int t;
	cin >> t;
	cin.get();
	for (int i = 1; i <= t; ++i) doit(i);
	return 0;
}