#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <ctime>

using namespace std;

#define sqr(a) ((a)*(a))
#define two(a) (1 << (a))
#define has(mask, a) ((mask) & two(a) ? 1 : 0)

const long double e = 2.7182818284590452353602874;

int n, x, y;

long double fact[1000005], dp[5005][5005];

void load() {
	cin >> n >> x >> y;
}

void solve(int test) {
	if (x == 0 && y == 0) {
	 	printf ("Case #%d: 1.0\n", test);
	 	return;
	}
	int step = 1;
	int size = 1;
	n--;

	while (true) {
	 	if (2 * (size + 1) + 1 > n) break;

	 	n -= 2 * (size + 1) + 1;
	 	int j = 0;
	 	for (int i = -step - 1;i <= 0;i++) {
	 		if (x == i && y == j) {
	 			printf ("Case #%d: 1.0\n", test);
	 			return;
	 		}
	 		++j;
	 	}
	 	j = step + 1;
	 	for (int i = 0;i <= step + 1;i++) {
	 	 	if (x == i && y == j) {
	 	 	 	printf ("Case #%d: 1.0\n", test);
	 	 	 	return;
	 	 	}
	 	 	j--;
	 	}
	 	size++;
	 	step++;
	}

	bool ok = false;
	int need = 1, j = 0;
	for (int i = -step - 1;i < 0;i++) {
		if (x == i && y == j) {
		 	ok = true;
		 	break;
		}
		need++;
		j++;
	}

	if (!ok) {
		need = size;
		int j = step;
		for (int i = 1;i <= step + 1;i++) {
			if (x == i && y == j) {
		 		ok = true;
		 		break;
			}
			need--;
			j--;
		}
		need++;             
	}

	if (!ok || need > n) {
	 	printf ("Case #%d: 0.0\n", test);
	 	return;
	}
	long double ans = 0;

	if (n <= 5000) {
		memset (dp, 0, sizeof (dp));
		dp[0][0] = 1;
		for (int i = 1;i <= n;i++) {
			for (int j = 0;j <= n;j++) {
			 	dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) / 2.0; 
			}
		}
		for (int i = need;i <= n;i++) {
		 	ans += dp[n][i];
		}
	}
	else {
		for (int i = need;i <= n;i++) {
	 		ans += pow (n / 2.0, i) / fact[i]  * pow (e, - (n / 2.0));
	 		//cerr << pow (n / 2.0, i) << " " << fact[i] << " " << pow (e, - (n / 2.0)) << endl;
		}
		//cerr << endl;
	}	

	printf ("Case #%d: %.7lf\n", test, (double)ans);
}

int main() {
 	freopen ("a.in", "r", stdin);
 	freopen ("a.out", "w", stdout);

 	fact[0] = 1;
 	for (int i = 1;i <= 1000000;i++) {
 	 	fact[i] = fact[i - 1] * i;
 	}
 	int t;
 	scanf ("%d\n", &t);

 	for (int i = 1;i <= t;i++) {
 		load();
 		solve(i);
 	}

 	return 0;
}