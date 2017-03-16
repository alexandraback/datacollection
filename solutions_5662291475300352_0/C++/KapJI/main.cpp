#include <cassert>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

typedef long long ll;
typedef long double ldb;
typedef pair<int, int> st;

const int INF = 1e9;
const ldb EPS = 1e-8;
const int MAXN = 1e6 + 100;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

int solve() {
	int n;
	scanf("%d", &n);
	vector<pair<int, int> > a;
	for (int i = 0; i < n; ++i) {
		int p, cnt, t;
		scanf("%d%d%d", &p, &cnt, &t);
		for (int j = 0; j < cnt; ++j) {
			a.push_back(make_pair(p, t + j));
		}
	}
	assert(a.size() <= 2);
	sort(a.begin(), a.end(), cmp);
	if (a.size() < 2) {
		return 0;
	}
	if (a[0].second > a[1].second) {
		//cerr << "case\n";
		double last_t = (360 - a[0].first) / 360.0 * a[0].second;
		double first_2t = (720 - a[1].first) / 360.0 * a[1].second;
		// if (abs(last_t - first_2t) < EPS) {
		// 	cerr << a[0].first << " v " << a[0].second << endl;
		// 	cerr << a[1].first << " v " << a[1].second << endl;
		// }
		//assert(abs(last_t - first_2t) > EPS);
		if (last_t + EPS < first_2t) {
			return 0;
		} else {
			return 1;
		}
	} else {
		//double last_t = (360 - a[0].first) / 360.0 * a[0].second;
		double last_2t = (720 - a[0].first) / 360.0 * a[0].second;
		double first_t = (360 - a[1].first) / 360.0 * a[1].second;
		if (first_t + EPS < last_2t) {
			return 0;
		} else {
			return 1;
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    FOR(i, t) {
        printf("Case #%d: %d\n", i + 1, solve());
    }
	return 0;
}

