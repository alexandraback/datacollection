// I can
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

ifstream fin("A-large.in");
ofstream fout("A-large.out");

ll t, r, c, w;

ll solve(ll rr, ll cc, ll ww) {
	if(ww == 1)
		return cc;
	if(ww == cc || ww == cc - 1)
		return cc;
	//if(cc - ww < ww)
	if(cc == 4) {
		return 3;
	}
	if(cc == 5) {
		return 4;
	}
	if(cc == 6) {
		if(ww == 2) return 4;
		if(ww == 3) return 4;
		return 5;
	}
	if(cc == 7) {
		if(ww == 2) return 5;
		if(ww == 3) return 5;
		if(ww == 4) return 5;
		return 6;
	}
	if(cc == 8) {
		if(ww == 2) return 5;
		if(ww == 3) return 5;
		if(ww == 4) return 5;
		if(ww == 5) return 6;
		return 7;
	}
	if(cc == 9) {
		if(ww == 7) return 8;
		if(ww == 6) return 7;
		if(ww == 3) return 5;
		return 6;
	}
	if(cc == 10) {
		if(ww == 8) return 9;
		if(ww == 7) return 8;
		if(ww == 2) return 6;
		if(ww == 3) return 6;
		if(ww == 4) return 6;
		if(ww == 5) return 6;
		return 7;		
	}
	if(2 * ww <= cc) {
		return solve(rr, cc - ww, ww);
	}
	else
		return ww + 1;
	//return 1 + solve(rr, cc - ww, ww);
}

void output(ll level, ll ans) {
	cout << "Case #" << level << ": " << ans << endl;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	for(ll index = 1; index <= t; ++index) {
		cin >> r >> c >> w;
		output(index, r * solve(r, c, w));
	}
	return 0;
}