

#if 1

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;
typedef int64_t int64;

typedef pair<int,int> pii;
typedef pair<double,double> pdd;
#define mp make_pair
#define X first
#define Y second

static void solve();

int main() {
	freopen("B.in.txt","r",stdin);
	freopen("B.out.txt","w",stdout);
	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; ++t) {
		cout << "Case #" << t << ": ";
		solve();
		cout << '\n';
	}
	return 0;
}

static void solve() {
	int d;
	cin >> d;
	deque<int> p;
	generate_n(back_inserter(p), d, []() { int pi; cin >> pi; return pi; });
	
	sort(p.begin(), p.end(), greater<int>());
	
	int m = p[0];
	set<int> targetSet(p.begin(), p.end());
	for (int target = int(ceil(sqrt(m))); target <= (m + 1) / 2; target++) {
		targetSet.insert(target);
	}
	int best = m;
	for (auto target : targetSet) {
		int cost = target;
		for (auto x : p) {
			int xc = (x + target - 1) / target - 1;
			cost += xc;
		}
		if (cost < best)
			best = cost;
	}
	cout << best;
}

#endif

