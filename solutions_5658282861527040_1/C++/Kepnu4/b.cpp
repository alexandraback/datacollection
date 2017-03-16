#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <numeric>

using namespace std;

#define sqr(a) ((a)*(a))
#define two(a) (1 << (a))
#define has(mask, a) ((mask) & two(a) ? 1 : 0)

int n;

long long dp[20][2][2][2];

vector <int> a, b, k;

vector <int> tobit (int a) {
	vector <int> res;

	while (a > 0) {
		res.push_back (a % 2);
		a /= 2;
	}
	reverse (res.begin(), res.end());
	return res;
}

void load() {
	int aa, bb, cc;
	cin >> aa >> bb >> cc;
	
	a = tobit (aa);
	b = tobit (bb);
	k = tobit (cc);
	n = max (k.size(), max (a.size(), b.size()));

	while ((int)a.size() < n) a.insert (a.begin(), 0);
	while ((int)b.size() < n) b.insert (b.begin(), 0);
	while ((int)k.size() < n) k.insert (k.begin(), 0);
}

long long go (int pos, int ea, int eb, int ek) {
	if (pos == n) return ea && eb && ek;

	long long &res = dp[pos][ea][eb][ek];
	if (res != -1) return res;
	res = 0;

	int ma = (ea || (a[pos] == 1)) ? 2 : 1;
	int mb = (eb || (b[pos] == 1)) ? 2 : 1;
	
	for (int i = 0;i < ma;i++) {
		for (int j = 0;j < mb;j++) {
			int c = i & j;
			if (c == 1 && !ek && k[pos] == 0) continue;

			int na = ea || (i < a[pos]);
			int nb = eb || (j < b[pos]);
			int nk = ek || (c < k[pos]);

			res += go (pos + 1, na, nb, nk);
		}
	}
	return res;
}

void solve(int test) {
	memset (dp, -1, sizeof (dp));

	printf ("Case #%d: %lld\n", test, go (0, 0, 0, 0));
}

int main() {
 	freopen ("a.in", "r", stdin);

 	int t;
 	scanf ("%d\n", &t);

 	for (int i = 1;i <= t;i++) {
 		load();
 		solve(i);
 	}

 	return 0;
}