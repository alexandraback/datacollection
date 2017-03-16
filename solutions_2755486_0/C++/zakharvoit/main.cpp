#pragma comment(linker, "/stack:8388608")
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <cassert>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long ll;

const int MAXN = 1000000;

struct Item {
	int d, w, e, s;

	Item() {}
	Item(int d, int w, int e, int s) : d(d), w(w), e(e), s(s) {}

	bool operator <(const Item &other) const {
		return d < other.d;
	}

	bool operator ==(const Item &other) const {
		return d == other.d;
	}
};

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int test = 0; test < t; test++) {
		int ans = 0;

		int n;
		cin >> n;

		vector <Item> v;
		for (int i = 0; i < n; i++) {
			int d, cnt, w, e, s, dd, dp, ds;
			cin >> d >> cnt >> w >> e >> s >> dd >> dp >> ds;

			e *= 2;
			w *= 2;
			dp *= 2;
			e += MAXN / 2;
			w += MAXN / 2;

			for (int j = 0; j < cnt; j++) {
				v.push_back(Item(d, w, e, s));
				w += dp;
				d += dd;
				e += dp;
				s += ds;
			}
		}

		sort(v.begin(), v.end());

		vector <int> wall(MAXN);
		vector <int> nwall(MAXN);
		
		int last = 0;

		for (int k = v[0].w; k <= v[0].e; k++) {
			nwall[k] = max(nwall[k], v[0].s);
		}
		++ans;
		for (int i = 1; i < (int)v.size(); i++) {
			if (v[i].d != v[last].d) {
				for (; last < i; last++) {
					for (int k = v[last].w; k <= v[last].e; k++) {
						wall[k] = max(wall[k], nwall[k]);
					}
				}
			}
			bool t = false;
			for (int k = v[i].w; k <= v[i].e; k++) {
				nwall[k] = max(nwall[k], v[i].s);
				if (!t && v[i].s > wall[k]) {
					++ans;
					t = true;
				}
			}	
		}
		
		cout << "Case #" << (test + 1) << ": " << ans << endl;
	}

	return 0;
}