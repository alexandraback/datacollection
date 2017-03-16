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
int cnt[2505];
int main() {
	int t;
	cin >> t;
	for(int tcase = 1; tcase <= t; ++tcase) {
		int n;
		cin >> n;
		memset(cnt, 0, sizeof(cnt));
		int x;
		for(int i = 0; i < 2 * n - 1; ++i) {
			for(int j = 0; j < n; ++j) {
				cin >> x;
				cnt[x] += 1;
			}
		}
		vector < int > res;
		cout << "Case #" << tcase << ": ";
		for(int i = 1; i <= 2500; ++i) {
			if(cnt[i] & 1) {
				cout << i << " ";
			}
		}
		cout << endl;
	}
	return 0;
}