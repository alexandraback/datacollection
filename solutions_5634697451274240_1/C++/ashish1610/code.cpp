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
		int len = str.length();
		string str1 = "";
		for(int i = 0; i < len; ++i) {
			str1 = str1 + '+';
		}
		int cnt = 0;
		while(str != str1) {
			cnt += 1;
			int pos = -1;
			for(int i = 0; i < len; ++i) {
				if(str[i] == '-') {
					pos = i;
					break;
				}
			}
			while(pos < len && str[pos] == '-') {
				pos += 1;
			}
			string tmp = "";
			for(int i = 0; i < pos; ++i) {
				if(str[i] == '+') {
					tmp = tmp + '-';
				} else {
					tmp = tmp + '+';
				}
			}
			for(int i = pos; i < len; ++i) {
				tmp = tmp + str[i];
			}
			str = tmp;
		}
		cout << "Case #" << tcase << ": " << cnt << endl;
	}
	return 0;
}