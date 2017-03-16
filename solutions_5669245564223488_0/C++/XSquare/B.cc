#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string> 

using namespace std;

typedef long long ll;
typedef vector <ll> VI;
typedef vector <VI> VVI;
typedef vector <double> VD;
typedef vector <VD>  VVD;
typedef vector <bool> VB;
typedef vector <VB> VVB;
typedef vector <string> VS;

VVI st;
VVI end;
VVI mid;
VVI lol;

ll M = 1e9+7;

ll sol;

ll fact(ll n){
	if (n == 0) return 1;
	return (n*fact(n-1))%M;
}

void work (VS &v){
	ll N = v.size();
	for (ll i = 0; i < N; ++i){
		char ant = 'A';
		string s;
		ll n = v[i].size();
		for (ll j = 0; j < n; ++j){
			if (v[i][j] != ant) s+= v[i][j];
			ant = v[i][j];
		}
		v[i] = s;
	}
}

void iterate (VS &v, bool &b){
	ll N = v.size();
	//cout << "holaa" << endl;
	//for (ll i = 0; i < N; ++i) cout << v[i] << endl;
	st = end = mid = lol = VVI(26, VI(0));
	for (ll i = 0; i < N; ++i){
		ll n = v[i].size();
		if (n == 1) lol[v[i][0] - 'a'].push_back(i);
		else{
			for (ll j = 0; j < n; ++j){
				if (j == 0) st[v[i][j] - 'a'].push_back(i);
				else if (j == n-1) end[v[i][j]-'a'].push_back(i);
				else mid[v[i][j]-'a'].push_back(i);
			}
		}
	}
	for (ll i = 0; i < 26; ++i){
		if (st[i].size() > 1){
			b = false;
			return;
		}
		else if (st[i].size() == 1){
			if (mid[i].size() > 0){
				b = false;
				return;
			}
			if (end[i].size() > 1){
				b = false;
				return;
			}
			if (end[i].size() == 1){
				ll ii = st[i][0];
				ll jj = end[i][0];
				if (ii == jj){
					b = false;
					return;
				}
				VS vv(0);
				for (ll j = 0; j < N; ++j){
					if (j != ii and j != jj){
						if (v[j].size() > 1 or v[j][0] != v[ii][0]) vv.push_back(v[j]);
					}
				}
				sol *= fact(lol[v[ii][0] - 'a'].size());
				sol %= M;
				string s = v[jj];
				for (ll j = 1; j < (ll)v[ii].size(); ++j) s+= v[ii][j];
				vv.push_back(s);
				iterate(vv, b);
				return;
			}
		}
		else{
			if (end[i].size() > 1){
				b = false;
				return;
			}
			else if (end[i].size() == 1){
				if (mid[i].size() > 0){
					b = false;
					return;
				}
			}
			else{
				if (mid[i].size() > 1){
					b = false;
					return;
				}
				else if (mid[i].size() == 1){
					if (lol[i].size() > 0){
						b = false;
						return;
					}
				}
			}
		}	
	}
	ll y = N;
	for (ll i = 0; i < 26; ++i){
		if (lol[i].size() > 0){
			sol*= fact((ll)lol[i].size());
			sol %= M;
			y -= lol[i].size();
			if (st[i].size() + end[i].size() == 0) ++y;
		}
	}
	sol *= fact(y);
	sol %= M;
}

int main(){
	ll T;
	cin >> T;
	for (ll t = 1; t <= T; ++t){
		sol = 1;
		ll N;
		cin >> N;
		VS v(N);
		for (ll i = 0; i < N; ++i) cin >> v[i];
		work(v);
		bool b = true;
		iterate(v, b);
		//for (ll i = 0; i < N; ++i) cout << v[i] << endl;
		cout << "Case #" << t << ": ";
		if (not b) cout << 0 << endl;
		else cout << sol << endl;
	}
}
