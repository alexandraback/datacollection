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
	ll numpat[5] = {0,1,1,2,5};
	vector<pair<ll,ll> > *pat[5];
	pat[1] = new vector<pair<ll,ll> >[1];
	pat[1][0].push_back(MP(0,0));
	pat[2] = new vector<pair<ll,ll> >[1];
	pat[2][0].push_back(MP(0,0));
	pat[2][0].push_back(MP(0,1));
	pat[3] = new vector<pair<ll,ll> >[2];
	pat[3][0].push_back(MP(0,0));
	pat[3][0].push_back(MP(0,1));
	pat[3][0].push_back(MP(0,2));
	pat[3][1].push_back(MP(0,0));
	pat[3][1].push_back(MP(0,1));
	pat[3][1].push_back(MP(1,1));
	pat[4] = new vector<pair<ll,ll> >[5];
	pat[4][0].push_back(MP(0,0));
	pat[4][0].push_back(MP(0,1));
	pat[4][0].push_back(MP(1,0));
	pat[4][0].push_back(MP(1,1));

	pat[4][1].push_back(MP(0,0));
	pat[4][1].push_back(MP(0,1));
	pat[4][1].push_back(MP(0,2));
	pat[4][1].push_back(MP(1,2));

	pat[4][2].push_back(MP(0,0));
	pat[4][2].push_back(MP(0,1));
	pat[4][2].push_back(MP(1,1));
	pat[4][2].push_back(MP(0,2));

	pat[4][3].push_back(MP(0,0));
	pat[4][3].push_back(MP(0,1));
	pat[4][3].push_back(MP(-1,1));
	pat[4][3].push_back(MP(-1,2));

	pat[4][4].push_back(MP(0,0));
	pat[4][4].push_back(MP(0,1));
	pat[4][4].push_back(MP(0,2));
	pat[4][4].push_back(MP(0,3));



	ios::sync_with_stdio(false);
	ll cases;
	cin >> cases;
	for (ll casenum = 1; casenum <= cases; casenum++) {
		ll d;
		cin >> d; cin >> r; cin >> c;
		bool ans = true;
		for (ll z = 0; z < numpat[d]; z++) {
			bool goodpattern = false;
			for (ll cx = -1; cx <= 1; cx += 2) {
				for (ll cy = -1; cy <= 1; cy += 2) {
					for (ll flip = 0; flip <= 1; flip++) {
						for (ll x = 0; x < r; x++) {
							for (ll y = 0; y < r; y++) {
								bool goodxy = true;
								for (ll i = 0; i < r; i++) {
									for (ll j = 0; j < c; j++) {
										a[i][j] = false;
									}
								}
								for (vector<pair<ll,ll> >::iterator it = pat[d][z].begin(); it != pat[d][z].end(); ++it) {
									ll dx = cx * it->first; ll dy = cy * it->second;
									if (flip) {
										ll temp = dx;
										dx = dy;
										dy = temp;
									}
									ll px = x+dx; ll py = y+dy;
									if (!(0 <= px && px < r && 0 <= py && py < c)) {
										goodxy = false;
										break;
									}
									a[px][py] = true;
								}
								for (ll i = 0; i < r; i++) {
									for (ll j = 0; j < c; j++) {
										ll num = dfs(i,j);
										if (num % d != 0) {
											goodxy = false;
										}
									}
								}
								if (goodxy) {goodpattern = true;}
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