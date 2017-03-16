// If there exists i, ij and ends with ijk, then win
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
#include <set>
#include <assert.h>
using namespace std;
typedef long long ll;
#define MP make_pair
ll multbase[4][4] = {
	{0,1,2,3},
	{1,4+0,3,4+2},
	{2,4+3,4+0,1},
	{3,2,4+1,4+0}
};

ll mult[8][8];
int main() {
	for (ll x = 0; x < 8; x++) {
		for (ll y = 0; y < 8; y++) {
			bool neg = (x >= 4) ^ (y >= 4);
			ll ans = multbase[x%4][y%4];
			if (neg) {
				if (ans < 4) {ans += 4;}
				else {ans -= 4;}
			}
			mult[x][y] = ans;
		}
	}
	ll ij = mult[1][2];
	ll ijk = mult[mult[1][2]][3];
	ios::sync_with_stdio(false);
	ll cases;
	cin >> cases;
	for (ll casenum = 1; casenum <= cases; casenum++) {
		ll n,r;
		cin >> n; cin >> r;
		string s; cin >> s;
		ll *b = new ll[n+1];
		b[0] = 0;
		for (ll i = 0; i < n; i++) {
			ll next;
			if (s[i] == '1') {
				next = 0;
			}
			else if (s[i] == 'i') {
				next = 1;
			}
			else if (s[i] == 'j') {
				next = 2;
			}
			else {
				next = 3;
			}
			b[i+1] = mult[b[i]][next];
		}
		ll h[4];
		h[0] = 0;
		for (ll i = 1; i < 4; i++) {
			h[i] = mult[h[i-1]][b[n]];
		}
		bool isi = false;
		bool isij = false;
		pair<ll,ll> firsti = MP(-1,-1);
		for (ll k = 0; k < min(r,4LL); k++) {
			for (ll i = 1; i <= n; i++) {
				ll g = mult[h[k]][b[i]];
				if (g==1) {
					firsti = MP(k,i);
					isi = true;
					break;
				}
			}
			if (isi) {break;}
		}
		for (ll k = 0; k < min(r,4LL); k++) {
			for (ll i = 1; i <= n; i++) {
				ll g = mult[h[k]][b[i]];
				if (g==ij) {
					if (r >= 4 || (firsti < MP(k,i))) {
						isij = true;
						break;
					}
				}
			}
			if (isij) {break;}
		}
		ll last = 0;
		for (ll i = 0; i < (r%4); i++) {
			last = mult[last][b[n]];
		}
		bool isijk = (last==ijk);
		bool ans = (isi && isij && isijk);
		if (ans) {
			cout << "Case #" << casenum << ": " << "YES" << endl;
		}
		else {
			cout << "Case #" << casenum << ": " << "NO" << endl;
		}
	}
}