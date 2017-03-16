#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


#define clr(x) memset(x, 0, sizeof(x))
#define pb push_back
#define mp make_pair

typedef long long ll;

int main () {
	int i, j, k, ca, T;
	int a, b, c;
	freopen ("B-small-attempt0.in", "r", stdin);
	freopen ("small-out", "w", stdout);

	cin >> T;
	for (ca = 1; ca <= T; ++ca) {
		cin >> a >> b >> c;
		int ans = 0;
		for (i = 0; i < a; ++i)
			for (j = 0; j < b; ++j)
				if ((i & j) < c) ans ++;
		cout << "Case #" << ca << ": " << ans << endl;
	}
	return 0;
}
