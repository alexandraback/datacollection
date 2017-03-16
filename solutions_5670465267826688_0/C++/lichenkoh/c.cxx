#include <algorithm>
#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
#include <set>
#include <assert.h>
using namespace std;
typedef long long ll;
#define INF 922337203685477580
int multbase[4][4] = {
	{0,1,2,3},
	{1,4+0,3,4+2},
	{2,4+3,4+0,1},
	{3,2,4+1,4+0}
};

int mult[8][8];
int leftinv[8];
int main() {
	for (ll x = 0; x < 8; x++) {
		for (ll y = 0; y < 8; y++) {
			bool neg = (x >= 4) ^ (y >= 4);
			int ans = multbase[x%4][y%4];
			if (neg) {
				if (ans < 4) {ans += 4;}
				else {ans -= 4;}
			}
			mult[x][y] = ans;
			//cout << x << "*" << y << "=" << ans << endl;
		}
	}
	for (ll x = 0; x < 8; x++) {
		for (ll y = 0; y < 8; y++) {
			if (mult[y][x] == 0) {
				leftinv[x] = y;
				break;
			}
		}
	}
	int ij = mult[1][2];
	int ijk = mult[mult[1][2]][3];
	ios::sync_with_stdio(false);
	ll cases;
	cin >> cases;
	for (ll casenum = 1; casenum <= cases; casenum++) {
		ll n,r;
		cin >> n; cin >> r;
		string s; cin >> s;
		int *b = new int[n];
		for (ll i = 0; i < n; i++) {
			int next;
			if (s[i] == '1') {
				b[i] = 0;
			}
			else if (s[i] == 'i') {
				b[i] = 1;
			}
			else if (s[i] == 'j') {
				b[i] = 2;
			}
			else {
				b[i] = 3;
			}
		}
		int *a = new int[n*r+1];
		a[0] = 0;
		ll ind = 1;
		for (ll j = 0; j < r; j++) {
			for (ll i = 0; i < n; i++) {
				a[ind] = mult[a[ind-1]][b[i]];
				ind++;
			}
		}
		ll prodnr = n*r;
		bool ans = false;
		if (a[prodnr] == ijk) {
			
			for (ll x = 1; x <= prodnr; x++) {
				int b1 = a[x];
				if (b1 == 1) {
					for (ll y = x+1; y <= prodnr; y++) {
						int b2 = mult[leftinv[a[x]]][a[y]];
						int b3 = mult[leftinv[a[y]]][a[prodnr]];
						if (b2 == 2 && b3 == 3) {
							ans = true;
							break;
						}
					}
				}
				if (ans) {break;}
			}
			
		}
		if (ans) {
			cout << "Case #" << casenum << ": " << "YES" << endl;
		}
		else {
			cout << "Case #" << casenum << ": " << "NO" << endl;
		}
	}
}