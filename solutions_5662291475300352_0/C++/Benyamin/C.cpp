#include <bits/stdc++.h>
#include <fstream>
#define X first
#define Y second
#define pb push_back
#define popb pop_back
#define mp make_pair
#define cin fin
#define cout fout
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> point;

ifstream fin("C-small-1-attempt0.in");
ofstream fout("C-small-1-attempt0.out");

void output(ll level, ll ans) {
	cout << "Case #" << level << ": " << ans << endl;
	return;
}

ll t, n;
class hiker {
public:
	ll time, st;
	ld speed;



};

int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	for(ll index = 1; index <= t; ++index) {
		cin >> n;
		ll t[10] = {0}, h[10] = {0}, m[10] = {0};
		for(ll i = 0; i < n; ++i) {
			cin >> t[i] >> h[i] >> m[i];
		}
		vector<hiker>g;
		for(ll i = 0; i < n; ++i) {
			for(ll j = 0; j < h[i]; ++j) {
				hiker tmp;
				tmp.time = m[i] + j;
				tmp.st = t[i];
				tmp.speed = 360.0 / tmp.time;
				g.pb(tmp);
			}
		}
		//cerr << g.size() << endl;
		if(g.size() == 1) {
			output(index, 0);
			continue;
		}
		if(g[0].st > g[1].st || (g[0].st == g[1].st && g[1].speed > g[0].speed)) {
			hiker tmp = g[1];
			g[1] = g[0];
			g[0] = tmp;
		}
		//cerr << g[0].time << ' ' << g[1].time << endl;
		if(g[0].time == g[1].time) {
			output(index, 0);
			continue;
		}
		cerr << g[1].speed << ' ' << g[0].speed << endl;
		if(g[1].speed < g[0].speed) {
			ll baghi = 360 - g[1].st;
			ld t_need = ((double) baghi) / g[1].speed;
			ld masa = g[0].speed * t_need;
			cerr << masa << endl;
			if(g[0].st != g[1].st && masa < 360 - g[0].st) {
				output(index, 0);
				continue;
			}
			if(g[0].st == g[1].st && masa < 360 + 360 - g[0].st) {
				output(index, 0);
				continue;
			}
			//masa -= (360 - g[0].st);
			//ll ans = 1 + masa / 360;
			output(index, 1);
			continue;
		}
		ll baghi = 360 - g[0].st;
		ld t_need = ((double) baghi) / g[0].speed;
		ld masa = g[1].speed * t_need;
		if(masa < 360 + (360 - g[1].st)) {
			output(index, 0);
			continue;
		}
		//masa -=  360 + (360 - g[1].st);
		//ll ans = 1 + masa / 360;
		output(index, 1);
	}
	return 0;
}