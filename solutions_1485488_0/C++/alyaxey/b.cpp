#include <iostream>
#include <cassert>
#include <string>
#include <cstdio>
#include <sstream>
#include <set>
#include <cmath>
#include <iomanip>

using namespace std;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : abs(x);
}

int sqr(int x) {
	return x * x;
}

#define Mas(x, p) (x)[(p).first][(p).second]

int h1[110][110];
int h2[110][110];
int times[110][110];

set<pair<int, pair<int, int> > > timesSet;

void setTime(pair<int, int> p, int t) {
	if (t < Mas(times, p)) {
		timesSet.erase(make_pair(Mas(times, p), p));
		Mas(times, p) = t;
		timesSet.insert(make_pair(Mas(times, p), p));
	}
}

void solve(int test) {
	int n, m, h;
	cin >> h >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> h2[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> h1[i][j];

	int inf = 1000000000;
	timesSet.clear();
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			times[i][j] = inf;
	setTime(make_pair(0, 0), 0);
	while (!timesSet.empty()) {
		pair<int, int> p = timesSet.begin()->second;
		timesSet.erase(timesSet.begin());
		int moveX[] = { 1, -1, 0, 0 };
		int moveY[] = { 0, 0, 1, -1 };
		for (int i = 0; i < 4; ++i) {
			pair<int, int> q(p.first + moveX[i], p.second + moveY[i]);
			if (!(0 <= q.first && q.first < n && 0 <= q.second && q.second < m
					&& Mas(h2, q) - Mas(h1, p) >= 50
					&& Mas(h2, p) - Mas(h1, q) >= 50
					&& Mas(h2, q) - Mas(h1, q) >= 50))
				continue;
			int time = max(Mas(times, p), h - Mas(h2, q) + 50);
			if (time > 0)
				time += h - time - Mas(h1, p) >= 20 ? 10 : 100;
			setTime(q, time);
		}
	}
	cout << fixed << setprecision(1);
	cout << "Case #" << test << ": " << times[n - 1][m - 1] * 0.1 << endl;
}

void pre() {
}

int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	ios::sync_with_stdio(false);
	pre();
	int n;
	cin >> n;
	string tmp;
	getline(cin, tmp);
	for (int i = 1; i <= n; ++i) {
		solve(i);
	}
	return 0;
}
