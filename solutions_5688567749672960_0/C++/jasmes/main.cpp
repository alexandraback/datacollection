#include <cstdio>
#include <iostream>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using ii = pair < int, int >;

#define X first
#define Y second
#define upto(i,n) for(int i = 0; i<n; ++i)
#define DEBUG(x) cout << #x <<": " << x << endl

using ll = long long;

const ll INF = 1e18;
int A[2002];

ll reverse(ll n) {
	ll res = 0;
	if (n % 10 == 0) return INF;
	while (n) {
		res *= 10;
		res += (n % 10);
		n /= 10;

	}
	return res;
}

ll res[1000002];

ll solve(ll n) {
	
	ll a = reverse(n);
	ll b = n - 1;
	if (a >= n) return res[b] + 1;
	

	return min(res[a], res[b]) +1;
}

int main() {
	int t;
	ll n;
	cin >> t;
	res[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		res[i] = solve(i);

	}
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		cout << "Case #" << tc << ": " << res[n] << endl;
	}
	return 0;
}