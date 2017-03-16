#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int t;

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &t);

	for (int q = 0; q < t; ++q) {
	 	int k, c, s;
	 	scanf("%d%d%d", &k, &c, &s);
	 	if (k > c * s) {
	 	 	cout << "Case #" << q + 1 << ": IMPOSSIBLE\n";
	 	 	continue;
	 	}
	 	vector<ll> ans;
	 	int i = 0;
	 	for (; i < k; ) {
	 		ll now = 0;
			for (int j = 0; j < c; ++j) {
			 	now = now * k;
			 	now += min(i, k - 1);
			 	++i;
			}
			ans.puba(now);
	 	}	
	 	cout << "Case #" << q + 1 << ": ";
	 	for (ll num: ans) {
	 	 	cout << num + 1 << " ";
	 	}
	 	cout << "\n";
	}

	return 0;
}