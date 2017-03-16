#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct H {
	ll val;
	int M;
	int D;
	H(int M, int D) : val((360 - D) * (ll)M), M(M), D(D) {}
};
bool operator<(const H& a, const H& b) {
	return a.val < b.val;
}

int solve() {
	int N;
	cin >> N;
	vector<H> hikers;
	rep(i,0,N) {
		int D, H, M;
		cin >> D >> H >> M;
		rep(i,0,H) {
			hikers.emplace_back(M+i, D);
		}
	}
	sort(all(hikers));
	ll res = sz(hikers);
	rep(i,0,sz(hikers)) {
		// ignore i+1 hikers, overtake the rest
		// if (i < sz(hikers) &&
		ll val = hikers[i].val;
		ll r = sz(hikers) - (i+1);
		rep(j,0,i+1) {
			ll v = ((hikers[j].D + val / hikers[j].M) / 360) - 1;
			// cerr << v << ' ';
			r += v;
		}
		// cerr << endl;
		res = min(res, r);
	}
	return (int)res;
}

int main() {
	int N;
	cin.sync_with_stdio(false);
	cin >> N;
	rep(i,0,N) {
		printf("Case #%d: %d\n", i+1, solve());
	}
}
