// -Wl,--stack,9001 
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)((x).size()))
#define rep(i, N) for (int i = 0; i < N; ++i)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
typedef long long lint;
typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve(int num) {
	int X, R, C;
	cin >> X >> R >> C;
	if (R > C) swap(R, C);
	string g = "GABRIEL";
	string r = "RICHARD";
	string res = r;
	if (X == 1) {
		res = g;
	} else if (X == 2) {
		if (R * C % 2 == 0) {
			res = g;
		}
	} else if (X == 3) {
		if ((R >= 2 && C >= 2) && (R * C % 3 == 0)) {
			res = g;
		}
	} else if (X <= 6) {
		if (R >= X - 1 && C >= X && (R * C) % C == 0) {
			res = g;
		}
		//if ((R == 3 && C == 4) || (R == 4 && C == 4)) {
		//	res = g;
		//}
	}

	printf("Case #%d: %s\n", num, res.c_str());
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tst;
	cin >> tst;
	for (int i = 1; i <= tst; ++i) {
		solve(i);
	}
    return 0;
}
