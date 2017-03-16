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
		string str;
		cin >> str;
		int len = (int)(str.length());
		string res = "";
		res += str[0];
		for(int i = 1; i < len; ++i) {
			if(str[i] >= res[0]) {
				res = str[i] + res;
			} else {
				res = res + str[i];
			}
		}
		cout << "Case #" << tcase << ": " << res << endl;
	}
	return 0;
}