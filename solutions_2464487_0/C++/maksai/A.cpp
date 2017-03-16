#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define mp make_pair
#define x first
#define y second
#define L(s) ((int)(s).size())
#define pb push_back
#define VI vector<int>
#define ll long long
ll r, t;
inline ll total_paint(ll k) {
	return 2LL * r * k + k + k * (k - 1) * 2LL;
}
int tc;
inline ll solve() {
	double dr = r, dt = t;
	double d = (2 * dr - 1) * (2 * dr - 1) + 8 * dt;
	ll k = (-2LL * r + 1 + (ll)sqrt(d)) / 4. - 100;
//	cerr << k << endl;
	if (k < 1) k = 1;
	while(total_paint(k + 1) <= t) ++k;
//	cerr << total_paint(k) << " " << t << endl;
	return k;
}
inline ll naive() {
	ll k = 1;
	while(total_paint(k + 1) <= t) ++k;
	return k;
}
int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> tc;
	for(int tn = 1; tn <= tc; ++tn) {
		cerr << tn << endl;
		cin >> r >> t;
		cout << "Case #" << tn << ": " << solve() << endl;
	}
} 