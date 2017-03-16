#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <queue>
#include <assert.h>
#include <deque>
#include <string.h>


using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

typedef vector <int> vi;
typedef vector <vi> vvi;



void solve() {
	int64 x;
	cin >> x;
	int n;
	cin >> n;
	vi a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	if (x == 1) {
		cout << n << endl;
		return;
	}

	
	sort(all(a));

	int res = n;
	int ind = 0;
	int done = 0;
	while (ind < n) {
		res = min(res, done + n - ind);
		if (x > a[ind]) {
			x += a[ind];
			++ind;
			continue;
		}
		++done;
		x += x - 1;
	}
	res = min(res, done);
	cout << res << endl;
}



int main () {
	//freopen("", "rt", stdin);
	//freopen("", "wt", stdout);
	//std::ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cout << "Case #" << t + 1 << ": ";
		solve();
	}

    return 0;
}

