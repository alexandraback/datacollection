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
int main() {
	int t;
	cin >> t;
	for(int tcase = 1; tcase <= t; ++tcase) {
		int n;
		cin >> n;
		vector < string > v1, v2;
		string str, str1;
		// set < string > s1, s2;
		for(int i = 0; i < n; ++i) {
			cin >> str >> str1;
			v1.push_back(str);
			// s1.insert(str);
			v2.push_back(str1);
			// s2.insert(str1);
		}
		// int sz1 = s1.size();
		// int sz2 = s2.size();
		// int res = min(n - sz1, n - sz2);
		int res = 0;
		for(int mask = 0; mask < (1 << n); ++mask) {
			set < string > s1, s2;
			for(int i = 0; i < n; ++i) {
				if(!(mask & (1 << i))) {
					s1.insert(v1[i]);
					s2.insert(v2[i]);
				}
			}
			bool flag = true;
			for(int i = 0; i < n; ++i) {
				if(mask & (1 << i)) {
					if(s1.find(v1[i]) == s1.end() || s2.find(v2[i]) == s2.end()) {
						flag = false;
						break;
					}
				}
			}
			if(flag) {
				res = max(res, __builtin_popcount(mask));
			}
		}
		cout << "Case #" << tcase << ": " << res << endl;
	}
	return 0;
}