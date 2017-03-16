#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits.h>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

#define rep(i,m) for(int i=0;i<(int)(m);++i)
#define sz(c) (int((c).size()))
#define fill(a,b) memset(a,b,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define mp make_pair

int C, D, V, d[101], have[101], ans;

bool haveAll() {
	for (int v = 1; v <= V; ++v) {
		if (!have[v]) return 0;
	}
	return 1;
}

void go(vi v) {
	if (sz(v) > 7) return;
	int h[101];
	for (int i = 1; i <= V; ++i) h[i] = have[i];
	rep(i, sz(v)) {
		int val = v[i];
		h[val] = 1;
		for (int j = 1; j <= V; ++j) {
			if (!h[j]) continue;
			if (j == val) continue;
			if (val + j > V) continue;
			h[val + j] = 1;
		}
	}
	bool ok = 1;
	vi cand;
	for (int v = 1; v <= V; ++v) {
		if (!h[v]) {
			ok = 0;
			cand.push_back(v);
		}
	}
	if (ok) {
		ans = min(ans, sz(v));
		return;
	} else {
		rep(i, sz(cand)) {
			v.push_back(cand[i]);
			go(v);
		}
	}
}

void solve(int cur_case) {
	cin >> C >> D >> V;
	fill(have, 0);
	ans = 1e9;
	rep(i, D) {
		cin >> d[i];
		have[d[i]] = 1;
		for (int v = 1; v <= V; ++v) {
			if (!have[v]) continue;
			if (v == d[i]) continue;
			if (d[i] + v > V) continue;
			have[d[i] + v] = 1;
		}
	}
	vi v;
	go(v);
	cout << "Case #" << cur_case << ": " << ans << endl;
}

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	cout << fixed;
	freopen("C-small-attempt3.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	clock_t start_time = clock(), check_time;
	int total_cases;
	cin >> total_cases;
	for (int cur_case = 1; cur_case <= total_cases; ++cur_case) {
		solve(cur_case);
		check_time = clock(); cerr << "Case #" << cur_case << " elapsed time: " << check_time - start_time << "ms" << endl; start_time = clock();
	}
	return 0;
}
