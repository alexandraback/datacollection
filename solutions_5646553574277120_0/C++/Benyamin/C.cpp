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

ifstream fin("C-small-attempt1.in");
ofstream fout("C-small-attempt1.out");

ll t, c, d, v;
ll coin[100];
bool can[100];


void output(ll level, ll ans) {
	cout << "Case #" << level << ": " << ans << endl;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	for(ll index = 1; index <= t; ++index) {
		cin >> c >> d >> v;
		for(ll i = 0; i <= 50; ++i)
			can[i] = false;
		for(ll i = 0; i < d; ++i)
			cin >> coin[i];
		ll count = 1 << d;
		for(ll i = 0; i < count; ++i) {
			ll tmp = i;
			ll tmp2 = 0;
			for(ll j = 0; j < d; ++j) {
				if(tmp % 2) tmp2 += coin[j];
				tmp /= 2;
			}
			if(tmp2 <= v)
				can[tmp2] = true;
		}
		ll ans2 = 0;
		//for(ll i = 0; i <= v; ++i)
		//	if(can[i]) cerr << i << endl;
		//cerr << endl;
		for(ll i = 1; i <= v; ++i) {
			if(can[i]) continue;
			ans2++;
			for(ll j = v; j >= 0; --j)
				if(can[j] && j + i <= v)
					can[j + i] = true;
		}
		output(index, ans2);
	}
	return 0;
}