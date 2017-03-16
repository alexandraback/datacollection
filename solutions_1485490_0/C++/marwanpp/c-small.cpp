/*
 * c-small.cpp
 *
 *  Created on: May 5, 2012
 *      Author: Marwan
 */

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstring>
#include <sstream>
#include <complex>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <climits>
#include <set>
#include <map>

using namespace std;

const int oo = (int) 1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
#define MP make_pair
#define SZ(x) (int)x.size()

typedef long long ll;
typedef pair<ll, int> pii;

#define SMALL

vector<pii> v1, v2;

ll mem[101][101];
ll ans = 0;

void calc(int id1, int id2, ll val) {
	if (id1 >= SZ(v1) or id2 >= SZ(v2)) {
		ans = max(ans, val);
		return;
	}

	if (v1[id1].second == v2[id2].second) {
		if (v1[id1].first > v2[id2].first)
		{
			v1[id1].first -= v2[id2].first;
			calc(id1, id2 + 1, val + v2[id2].first);
			v1[id1].first += v2[id2].first;
		}
		else if (v1[id1].first < v2[id2].first)
		{
			v2[id2].first -= v1[id1].first;
			calc(id1 + 1, id2, val + v1[id1].first);
			v2[id2].first += v1[id1].first;
		}
		else
			calc(id1 + 1, id2 + 1, val + v1[id1].first);
	}
	else{
		calc(id1 + 1, id2, val);
		calc(id1, id2 + 1, val);
	}

}

int main() {
#ifdef SMALL
	freopen("c-small.in", "rt", stdin);
	freopen("c-small.txt", "wt", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		ans = 0ll;
		printf("Case #%d: ", t);

		int N, M;

		scanf("%d%d", &N, &M);
		v1 = vector<pii>(N);
		v2 = vector<pii>(M);

		for (int j = 0; j < N; ++j)
			cin >> v1[j].first >> v1[j].second ;

		for (int j = 0; j < M; ++j)
			cin >> v2[j].first >> v2[j].second ;


		calc (0,0 ,0);

		cout << ans << endl;
	}
	return 0;
}
