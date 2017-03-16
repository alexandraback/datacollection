#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <iostream>
#include <cfloat>
#include <ctime>
#include <sstream>
using namespace std;
#define all(a) a.begin(),a.end()
#define mset(a, v) memset(a, v, sizeof(a));
typedef long long ll;

struct Tribe {
	int d, n, w, e, s;
	int delta_d, delta_p, delta_s;
};

vector<Tribe> tribes;

struct Attack {
	int w, e, s;
};

int solve() {
	priority_queue<pair<int, int> > q;
	for (int i = 0; i < (int)tribes.size(); ++i) {
		q.push(make_pair(-tribes[i].d, i));
	}
	int result = 0;
	int wall[4096] = {0};

	while (!q.empty()) {
		vector<pair<int, int> > curr;
		curr.push_back(q.top());
		q.pop();

		while (!q.empty()) {
			if (q.top().first != curr[0].first) {
				break;
			}
			curr.push_back(q.top());
			q.pop();
		}

		vector<Attack> nextAttacks;
		for (int i = 0; i < curr.size(); ++i) {
			Tribe t = tribes[curr[i].second];
			
			for (int j = t.w; j <= t.e; ++j) {
				if (t.s > wall[j]) {
					++result;
					break;
				}
			}
		}

		for (int i = 0; i < curr.size(); ++i) {
			Tribe &t = tribes[curr[i].second];

			for (int j = t.w; j <= t.e; ++j) {
				wall[j] = max(wall[j], t.s);
			}

			t.d += t.delta_d;
			t.e += t.delta_p;
			t.w += t.delta_p;
			t.s += t.delta_s;
			--t.n;

			if (t.n) {
				q.push(make_pair(-t.d, curr[i].second));
			}
		}
	}

	return result;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		int N;
		cin >> N;
		tribes.resize(N);
		for (int i = 0; i < N; ++i) {
			cin >> tribes[i].d;
			cin >> tribes[i].n;
			cin >> tribes[i].w;
			cin >> tribes[i].e;
			cin >> tribes[i].s;
			cin >> tribes[i].delta_d;
			cin >> tribes[i].delta_p;
			cin >> tribes[i].delta_s;
			tribes[i].w += 1024 + tribes[i].w;
			tribes[i].e += 1024 + tribes[i].e;
			tribes[i].delta_p *= 2;
		}

		cout << solve() << endl;
	}

	return 0;
}
