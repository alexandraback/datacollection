#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;

vector <int> cur;
int ans = 0;
int e, r, n;
int v[20];

void perebor(int pos, int tmp) {
	if (pos == n) {
		int curres = 0;
		for (int i = 0; i < n; ++i)
			curres += v[i] * cur[i];
		ans = max(ans, curres);
		return ;
	}
	for (int j = tmp; j >= 0; --j) {
		cur.pb(j);
		perebor(pos + 1, min(e, tmp - j + r));
		cur.pop_back();
	}
}

int solve() {
	scanf("%d %d %d", &e, &r, &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &v[i]);
	ans = 0;
	perebor(0, e);
	return ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		printf("Case #%d: %d\n", i + 1, solve());
	}
	return 0;
}