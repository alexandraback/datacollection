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
		ll n;
		cin >> n;
		set < int > st;
		ll res = -1;
		for(int i = 1; i <= 1000000; ++i) {
			ll tmp = i * n;
			while(tmp) {
				st.insert(tmp % 10);
				tmp /= 10;
			}
			if(st.size() == 10) {
				res = i * n;
				break;
			}
		}
		cout << "Case #" << tcase << ": ";
		if(res == -1) {
			cout << "INSOMNIA\n";
		} else {
			cout << res << endl;
		}
	}
	return 0;
}