#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

vector<int> candidates(string s) {
	vector<int> res;
	int n = s.size();
	for(int i=0; i<n; ++i) {
		if(s[i]!='?') {
			int val = s[i]-'0';
			if(res.empty()) {
				res.assign(1, val);
			} else {
				for(int& v: res) {
					v = v*10 + val;
				}
			}
		} else {
			vector<int> w;
			if(res.empty()) {
				for(int i=0; i<=9; ++i) {
					res.push_back(i);
				}
			} else {
				vector<int> w;
				for(int v: res) for(int i=0; i<=9; ++i) {
					int a = 10 * v + i;
					w.push_back(a);
				}
				res = w;
			}
		}
	}
	return res;
}

string mystr(ll a, size_t n) {
	stringstream ss;
	ss << a;
	string res = ss.str();
	if(res.size()<n) {
		res = string(n-res.size(), '0') + res;
	}
	return res;
}

void single_test() {
	string sc, sj;
	cin >> sc >> sj;
	auto vc = candidates(sc);
	auto vj =candidates(sj);
	pii best_p;
	ll best_d = numeric_limits<ll>::max();
	for(auto c: vc) for(auto j: vj) {
		ll d = abs(c-j);
		if(d<best_d) {
			best_d = d;
			best_p.first = c;
			best_p.second = j;
		}
	}
	cout << mystr(best_p.first, sc.size()) << ' ';
	cout << mystr(best_p.second, sj.size()) << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	int t;
	cin >> t;
	for(int i=1; i<=t; ++i) {
		cout << "Case #" << i << ": ";
		single_test();
	}
	return 0;
}
