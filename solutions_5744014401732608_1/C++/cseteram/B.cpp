#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <algorithm>

using namespace std;
typedef long long ll;

void solve(int &b, ll &m) {
	ll maxval = (1LL << (b - 2));
	ll rem = maxval - m;

	if (rem < 0) {
		printf("IMPOSSIBLE\n");
		return;
	}

	vector<vector<int> > G(b, vector<int>(b,0));
	for(int i=0 ; i<b ; i++) {
		for(int j=i+1 ; j<b ; j++) {
			G[i][j] = 1;
		}
	}

	for(int i=1 ; i<b && rem > 0 ; i++) {
		ll t = rem % 2;
		rem /= 2;

		if (t) G[i][b-1] = 0;
	}

	printf("POSSIBLE\n");
	for(int i=0 ; i<b ; i++) {
		for(int j=0 ; j<b ; j++) {
			printf("%d", G[i][j]);
		}
		printf("\n");
	}

	// printf("\n");
}

int main() {

	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		int b;
		ll m;
		scanf("%d %lld", &b, &m);
		printf("Case #%d: ", tc);

		solve(b,m);
	}

	return 0;
}