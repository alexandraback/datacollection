/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll				long long int
#define MOD				1000000007
#define si(a)			scanf("%d", &a)
#define sl(a)			scanf("%lld", &a)
#define pi(a)			printf("%d", a)
#define pl(a)			printf("%lld", a)
#define pn 				printf("\n")
ll pow_mod(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
pair < bool, vector < ll > > isPrime(ll val) {
	vector < ll > v;
	for(ll i = 2; i <= (ll)(sqrt(val)); ++i) {
		if(val % i == 0) {
			v.push_back(i);
			if(i != val / i) {
				v.push_back(val / i);
			}
		}
	}
	if(v.empty()) {
		return make_pair(true, v);
	} else {
		return make_pair(false, v);
	}
	// return true;
}
int main() {
	int t;
	cin >> t;
	for(int tcase = 1; tcase <= t; ++tcase) {
		int n, j;
		cin >> n >> j;
		ll st = (1 << (n - 1)) + 1;
		vector < pair < vector < int> , set < pair < int, ll > > > > v;
		for(ll mask = st; mask < (1 << n); mask += 2) {
			vector < int > bin;
			ll tmp = mask;
			while(tmp) {
				bin.push_back(tmp % 2);
				tmp /= 2;
			}
			reverse(bin.begin(), bin.end());
			vector < ll > base_val;
			for(int base = 2; base <= 10; ++base) {
				ll val = 0;
				for(int i = 0; i < (int)(bin.size()); ++i) {
					val = val * base + bin[i];
				}
				base_val.push_back(val);
			}
			bool flag = true;
			set < pair < int, ll > > st;
			for(int i = 0; i < (int)(base_val.size()); ++i) {
				pair < bool, vector < ll > > tmp = isPrime(base_val[i]);
				if(tmp.first) {
					flag = false;
				} else {
					st.insert(make_pair(i + 2, tmp.second[0]));
				}
			}
			if(flag) {
				v.push_back(make_pair(bin, st));
			}
			if((int)(v.size()) == j) {
				break;
			}
		}
		cout << "Case #" << tcase << ":\n";
		for(int i = 0; i < j; ++i) {
			vector < int > tmp = v[i].first;
			for(int k = 0; k < (int)(tmp.size()); ++k) {
				cout << tmp[k];
			}
			cout << " ";
			set < pair < int, ll > > s = v[i].second;
			set < pair < int, ll > > :: iterator it;
			for(it = s.begin(); it != s.end(); ++it) {
				cout << (*it).second << " ";
			}
			cout << endl;
		}
	}
	return 0;
}