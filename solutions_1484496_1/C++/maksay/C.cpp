#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;
#define L(s) (int)((s).size())
#define pb push_back
#define pii pair<int, int>
#define mpr make_pair
#define x first
#define y second
#define inf 1000000000
#define all(s) (s).begin(), (s).end()
#define ll long long
#define VI vector<int>
#define ull unsigned ll
ll a[555], p[20], q[20];
int n, t;
pair<ll, ll> mp[1 << 20], mq[1 << 20];
map<ll, ll> pp, qq;
ll cp[1 << 20], cq[1 << 20];
inline void put(ll x, ll y) {
	ll rx = x ^ (x & y);
	ll ry = y ^ (x & y);
	x = rx; y = ry;
	bool was = 0;
	for(int i = 0; i < 40; ++i) {
		if (x & (1LL << i)) {
			if (!was) was = 1; else cout << " ";
			cout << a[i];
		}
	}
	cout << endl;
	was = 0;
	for(int i = 0; i < 40; ++i) {
		if (y & (1LL << i)) {
			if (!was) was = 1; else cout << " ";
			cout << a[i];
		}
	}
	cout << endl;
}
int main() {
	freopen("C-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
//	t = 10;
	for(int num = 1; num <= t; ++num) {
		cerr << num << endl;
		printf("Case #%d:\n", num);
		cin >> n; for(int i = 0; i < n; ++i) cin >> a[i];
//		n = 500; for(int i = 0; i < n; ++i) a[i] = rand();
		random_shuffle(a, a + n);
		for(int i = 0; i < 20; ++i) p[i] = a[i], q[i] = a[i + 20];
		for(int mask = 0; mask <(1 << 20); ++mask) {
			ll sp = 0, sq = 0;
			for(int i = 0; i < 20; ++i) {
				if (mask & (1 << i)) {
					sp += p[i];
					sq += q[i];
				}
			}
			mp[mask] = mpr(sp, mask);
			mq[mask] = mpr(sq, mask);
			cp[mask] = sp;
			cq[mask] = sq;
		}
		sort(mp, mp + (1 << 20));
		sort(mq, mq + (1 << 20));
		bool ok = 0;
		for(int i = 0; i < (1 << 20) - 1; ++i) {
			if (mp[i].x == mp[i + 1].x) {
				put(mp[i].y, mp[i + 1].y);
				ok = 1;
				break;
			}
			if (mq[i].x == mq[i + 1].x) {
				put(mq[i].y << 20, mq[i + 1].y << 20);
				ok = 1;
				break;
			}
		}
		if (ok) continue;
		for(int i = 0; i < (1 << 20); ++i) {
			if (!mp[i].x) continue;
			int pos = lower_bound(mq, mq + (1 << 20), mpr(mp[i].x, (ll)-inf)) - mq;
			if (pos < (1 << 20) && mq[pos].x == mp[i].x) {
				put(mp[i].y, mq[pos].y << 20);
				ok = 1;
				break;
			}
		}
		if (ok) continue;
		for(int i = 0; i <(1 << 20); ++i) {
			pp[mp[i].x] = mp[i].y;
			qq[mq[i].x] = mq[i].y;
		}
		for(ll mask = 0; mask < (1 << 20) && !ok; ++mask) {
			for(ll subx = mask & (mask - 1); subx; subx = mask & (subx - 1)) {
				ll suby = mask ^ subx;
				if (qq.find(cp[subx] - cp[suby]) != qq.end()) {
					put(subx, suby | (qq[cp[subx] - cp[suby]] << 20));
					ok = 1;
					break;
				}
			}
		}
		for(ll mask = 0; mask < (1 << 20) && !ok; ++mask) {
			for(ll suby = mask & (mask - 1); suby; suby = mask & (suby - 1)) {
				ll subx = mask ^ suby;
				if (pp.find(cq[suby] - cq[subx]) != pp.end()) {
					put((subx << 20) | pp[cq[suby] - cq[subx]], suby << 20);
					ok = 1;
					break;
				}
			}
		}
	}
}
