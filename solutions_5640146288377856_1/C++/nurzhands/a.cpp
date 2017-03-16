#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <bitset>
#include <vector>
#include <string>
#include <cstdio>
#include <cassert>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)a.size()
#define ms(a, x) memset(a, x, sizeof a)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef pair<int,int> pt;

const int inf = 1<<30;
const int N = 1<<17;

int main() {
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int r, c, w;
		cin >> r >> c >> w;
		int ans = (c + w - 1) / w + w - 1;
		ans = ans * r;
		cout << "Case #" << test << ": " << ans << endl;
	}

	return 0;
}