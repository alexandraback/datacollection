#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)

typedef unsigned long long ll;
ll ringCost(ll r) {
	return r*r-(r-1)*(r-1);
}
ll cost(ll r, ll n) {
	return n * (2*r - 1) + 2 * (n-1) * n;
}

ll solve() {
	ll r,t;
	cin >> r >> t;
	r += 1;
	ll high = 1;
	while(cost(r, high) <= t)
		high *= 2;
	ll low = high / 2;
	while(low <= high) {
		ll mid = low + (high-low) / 2;
		if(cost(r, mid) > t) {
			high = mid-1;
		} else {
			low = mid + 1;
		}
	}
	return high;
}

int main() {
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	REP(i,t) {
		cout << "Case #" << (i+1) << ": " << solve() << endl;
	}
}
