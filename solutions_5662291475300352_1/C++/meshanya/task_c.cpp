#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#define int64 long long
#define ldb long double
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define taskname "task_c"
const ldb pi = acos(-1.0);

int main() {
//	assert(freopen(taskname".in", "r", stdin));
//	assert(freopen(taskname".out", "w", stdout));
	int t, pos, cnt, m, n;
	scanf("%d", &t);
	for (int it = 0; it < t; ++it) {
		scanf("%d", &n);
		vector< pair<int64, int64> > e;
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d", &pos, &cnt, &m);
			for (int j = 0; j < cnt; ++j)
				e.pb(mp((360LL - pos) * (m + j), 360LL * (m + j)));
		}
		int64 l = 0, r = (int64) 3.6e13;
		while (l < r) {
			int64 q = (l + r + 1) / 2, sum = 0;
			for (int i = 0; i < sz(e); ++i)
				if (q >= e[i].fs)
					sum += (q - e[i].fs) / e[i].sc + 1;
			if (sum > 2 * sz(e))
				r = q - 1;
			else
				l = q;
		}
		vector< pair<int64, int> > t;
		for (int i = 0; i < sz(e); ++i) {
			t.pb(mp(e[i].fs, 0));
			while (e[i].fs + e[i].sc <= l)
				t.pb(mp(e[i].fs += e[i].sc, 1));
		}
		sort(t.begin(), t.end());
		int sum = 0, zeroes = 0, ans = sz(e);
		for (int i = 0; i < sz(t); ) {
			int j = i;
			while ((j < sz(t)) && (t[i].fs == t[j].fs)) {
				if (t[j].sc == 0) zeroes++;
				sum += t[j++].sc;
			}
			ans = min(ans, sz(e) - zeroes + sum);
			i = j;
		}
		printf("Case #%d: %d\n", it + 1, ans);
	}	
	return 0;
}
