// X >= 7 means impossible
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cmath>
#include <queue>
#include <set>
#include <assert.h>
using namespace std;
typedef int ll;
#define MP make_pair
bool a[20][20];
ll r,c;
ll dfs(ll x, ll y) {
	if (a[x][y]) {return 0;}
	ll ans = 1;
	a[x][y] = true;
	for (ll i = max(0,x-1); i <= min(x+1,r-1); i++) {
		if (!a[i][y]) {
			ans += dfs(i,y);
		}
	}
	for (ll j = max(0,y-1); j <= min(y+1,c-1); j++) {
		if (!a[x][j]) {
			ans += dfs(x,j);
		}
	}
	return ans;
}

int main() {
	vector<ll> pat[7];
	r = 5; c = 5;
	for (ll z = 0; z < (1<<24); z++) {
		ll s = z;
		ll d = __builtin_popcountll(z)+1;
		if (d > 6) {
			continue;
		}
		a[0][0] = false;
		for (ll x = 0; x < 5; x++) {
			for (ll y = 0; y < 5; y++) {
				if (x == 0 && y == 0) continue;
				a[x][y] = ((s&0x1)==0);
				s = s >> 1;
			}
		}
		if (dfs(0,0) == d) {
			bool alldiff = true;
			for (vector<ll>::iterator it=pat[d].begin(); it != pat[d].end(); ++it) {
				s = z;
				ll t = *it;
				bool diff = false;
				for (ll x = 0; x < 5; x++) {
					for (ll y = 0; y < 5; y++) {
						if (x == 0 && y == 0) continue;
						a[x][y] = ((s&0x1)==1);
						s = s >> 1;
					}
				}
				for (ll y = 0; y < 5; y++) {
					for (ll x = 0; x < 5; x++) {
						if (x == 0 && y == 0) continue;
						if (((t&0x1)==1) != a[x][y]) {
							diff = true;
							break;
						}
					}
				}
				if (!diff) alldiff = false;
			}
			if (alldiff) {
				pat[d].push_back(z);
			}
		}
	}
	pat[6].push_back(-1);
	
	ios::sync_with_stdio(false);
	ll cases;
	cin >> cases;
	for (ll casenum = 1; casenum <= cases; casenum++) {
		ll d;
		cin >> d; cin >> r; cin >> c;
		if (d >= 7) {
			cout << "Case #" << casenum << ": " << "RICHARD" << endl;
			continue;
		}
		bool ans = true;
		for (vector<ll>::iterator it = pat[d].begin(); it != pat[d].end(); ++it) {
			ll z = *it;
			bool goodpattern = false;
			if (z==-1) {
				for (ll cx = -1; cx <= 1; cx++) {
					for (ll cy = -1; cy <= 1; cy++) {
						if (!(cx==0 || cy == 0)) continue;
						for (ll x = 0; x < r; x++) {
							for (ll y = 0; y < r; y++) {
								bool goodxy = true;
								for (ll i = 0; i < r; i++) {
									for (ll j = 0; j < c; j++) {
										a[i][j] = false;
									}
								}
								for (ll i = 0; i < d; i++) {
									ll px = x+(i*cx);
									ll py = y+(i*cy);
									if (!(0 <= px && px < r && 0 <= py && py < c)) {
										goodxy = false;
										break;
									}
									a[px][py] = true;
								}
								if (!goodxy) continue;
								for (ll i = 0; i < r; i++) {
									for (ll j = 0; j < c; j++) {
										ll num = dfs(i,j);
										if (num % d != 0) {
											goodxy = false;
										}
									}
								}
								if (goodxy) {goodpattern = true; break;}
							}
						}
					}
				}
			}
			else {
				for (ll cx = -1; cx <= 1; cx+=2) {
					for (ll cy = -1; cy <= 1; cy+=2) {
						for (ll flip = 0; flip <= 1; flip++) {
							for (ll x = 0; x < r; x++) {
								for (ll y = 0; y < r; y++) {
									bool goodxy = true;
									for (ll i = 0; i < r; i++) {
										for (ll j = 0; j < c; j++) {
											a[i][j] = false;
										}
									}
									a[x][y] = true;
									ll s = z;
									for (ll dx = 0; dx < 5; dx++) {
										for (ll dy = 0; dy < 5; dy++) {
											if (dx == 0 && dy == 0) continue;
											if (s&0x1) {
												ll rdx,rdy;
												if (flip) {
													rdx = dy;
													rdy = dx;
												}
												else {
													rdx = dx;
													rdy = dy;
												}
												ll px = x+rdx;
												ll py = y+rdy;
												if (!(0 <= px && px < r && 0 <= py && py < c)) {
													goodxy = false;
													break;
												}
												a[px][py] = true;
											}
											s = s >> 1;
										}
									}
									if (!goodxy) continue;
									for (ll i = 0; i < r; i++) {
										for (ll j = 0; j < c; j++) {
											ll num = dfs(i,j);
											if (num % d != 0) {
												goodxy = false;
											}
										}
									}
									if (goodxy) {goodpattern = true; break;}
								}
							}
						}
					}
				}
			}
			if (!goodpattern) {
				ans = false;
				break;
			}
		}
		if (ans) {
			cout << "Case #" << casenum << ": " << "GABRIEL" << endl;
		}
		else {
			cout << "Case #" << casenum << ": " << "RICHARD" << endl;
		}
	}
}