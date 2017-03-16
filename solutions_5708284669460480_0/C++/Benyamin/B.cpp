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

ifstream fin("B-small-attempt0.in");
ofstream fout("B-small-attempt0.out");

ll t, k, l, s,best, counter, moz;
string curstr = "", key, goal;
vector<char>harf;

void BT(ll sz) {
	//cerr << sz << endl;
	if(sz == s) {
		counter++;
		ll tmp = 0;
		for(ll i = 0; i <= s - l; ++i) {
			if(curstr.substr(i, l) == goal)
				tmp++;
		}
		best += (moz - tmp);
		//cerr << curstr << counter << endl;
		return;
	}
	for(ll i = 0; i < harf.size() ; ++i) {
		//harf[i]--;
		curstr += harf[i];
		BT(sz + 1);
		//harf[i]++;
		curstr = curstr.substr(0, curstr.size() - 1);
	}
	return;
}

void BT2(ll sz) {
	//cerr << sz << endl;
	if(sz == s) {
		ll tmp = 0;
		for(ll i = 0; i <= s - l; ++i) {
			if(curstr.substr(i, l) == goal)
				tmp++;
		}
		//cerr << curstr << endl;
		if(tmp > moz)
			moz = tmp;
		return;
	}
	for(ll i = 0; i < harf.size() ; ++i) {
		//harf[i]--;
		curstr += harf[i];
		BT2(sz + 1);
		//harf[i]++;
		curstr = curstr.substr(0, curstr.size() - 1);
	}
	
	return;
}

void output(ll level, ld ans) {
	cout << "Case #" << level << ": ";
	cout << fixed << setprecision(7) << ans << endl;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	for(ll index = 1; index <= t; index++) {
		cin >> k >> l >> s >> key >> goal;
		best = counter = moz = 0;
		while(harf.size()) harf.popb();
		curstr = "";
		for(ll i = 0; i < key.size(); ++i)
			harf.pb(key[i]);
		BT2(0);
		curstr = "";
			//cerr << moz << endl;
		BT(0);

		//cerr << counter << ' ' << best << endl;
		output(index, (ld)((ld) best / (ld) counter));
		
	}
	return 0;
}