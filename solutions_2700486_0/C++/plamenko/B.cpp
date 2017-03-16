#define _CRT_SECURE_NO_DEPRECATE
//#define _CRT_RAND_S

//#include <windows.h>
//#include <tchar.h>
//#include <atlbase.h>
//#include <winerror.h>

#include <stdint.h>
#include <climits>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <string>
#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int under(const pii &p, const pii &q) {
	return (q.second <= q.first + p.second - p.first) && (q.second <= -q.first + p.second + p.first);
}

vector<pii> add(const vector<pii> &t, int i) {
	vector<pii> r;
	if (i == 0) {
		// has only right hill
		pii p(t[i].first - t[i].second - 2, 0);
		r.push_back(p);
		for (int j = 0; j < (int) t.size(); j++) r.push_back(t[j]);
	}
	else if (i >= (int) t.size()) {
		// has only left hill
		pii p(t[i-1].first + t[i-1].second + 2, 0);
		for (int j = 0; j < (int) t.size(); j++) r.push_back(t[j]);
		r.push_back(p);
	}
	else {
		// has both hills
		pii p((t[i-1].first + t[i].first + t[i-1].second - t[i].second) / 2,
			  (t[i-1].first - t[i].first + t[i-1].second + t[i].second) / 2 + 2);
		for (int j = 0; j < i-1; j++) r.push_back(t[j]);
		if (!under(p, t[i-1])) r.push_back(t[i-1]);
		r.push_back(p);
		if (!under(p, t[i])) r.push_back(t[i]);
		for (int j = i+1; j < (int) t.size(); j++) r.push_back(t[j]);
	}
	return r;
}

double calc(int n, int x, int y) {
	map<vector<pii>, double> m;
	vector<pii> t0; t0.push_back(pii(0, 0)); m[t0] = 1;
	for (int k = 1; k < n; k++) {
		map<vector<pii>, double> mn;
		for (auto it = m.begin(); it != m.end(); it++) {
			const vector<pii> &t = it->first;
			int i;
			for (i = 0; i < (int) t.size(); i++) {
				if (t[i].first >= 0) break;
			}
			if (i < (int) t.size() && t[i].first == 0) {
				// hits top
				mn[add(t, i)] += it->second / 2;
				mn[add(t, i + 1)] += it->second / 2;
			}
			else {
				mn[add(t, i)] += it->second;
			}
		}
		m.swap(mn);
	}
	double prob = 0;
	for (auto it = m.begin(); it != m.end(); it++) {
		for (int i = 0; i < (int) it->first.size(); i++) {
			if (under((it->first)[i], pii(x, y))) { prob += it->second; break; }
		}
	}
	return prob;
}

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int n, x, y; scanf("%d %d %d", &n, &x, &y);
		double p = calc(n, x, y);
		printf("Case #%d: %.10lf\n", t, p);
	}
	return 0;
}
