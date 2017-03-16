#include <bits/stdc++.h>
using namespace std;
vector<long long> calc(string s) {
	vector<long long> tmp;
	tmp.clear();
	tmp.push_back(0);
	for(int i = 0; i < int(s.size()); i++) {
		if(s[i] == '?') {
			vector<long long> tmp1;
			tmp1 = tmp;
			tmp.clear();
			for(int j = 0; j < int(tmp1.size()); j++) {
				for(int k = 0; k < 10; k++) {
					tmp.push_back(10 * tmp1[j] + k);
				}
			}
		}
		else {
			for(int j = 0; j < int(tmp.size()); j++) tmp[j] = tmp[j] * 10 + s[i] - '0';
		} 
	}
	return tmp;
}
int digs(long long x) {
	int ret = 0;
	if(x == 0) return 1;
	while(x > 0) {
		x /= 10;
		ret++;
	}
	return ret;
} 
int main() {
	int test;
	cin >> test;
	for(int tt = 1; tt <= test; tt++) {
		cout << "Case #" << tt << ": ";
		string s, t;
		cin >> s >> t;
		vector<long long> vs, vt;
		vs = calc(s), vt = calc(t);
		vector<pair<long long, pair<long long, long long> > > v;
		for(int i = 0; i < int(vs.size()); i++) {
			for(int j = 0; j < int(vt.size()); j++) {
				v.push_back(make_pair(abs(vs[i] - vt[j]), make_pair(vs[i], vt[j])));
			}
		}
		sort(v.begin(), v.end());
		for(int i = 0; i < int(s.size()) - digs(v[0].second.first); i++) cout<<0;
		cout << v[0].second.first << " ";
		for(int i = 0; i < int(s.size()) - digs(v[0].second.second); i++) cout<<0;
		cout << v[0].second.second << endl;
	}
}