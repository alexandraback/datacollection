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
		vector < int > cnt(26, 0);
		for(int i = 0; i < len; ++i) {
			cnt[str[i] - 'A'] += 1;
		}
		vector < int > res;
		while(cnt['Z' - 'A']) {
			cnt['Z' - 'A'] -= 1;
			cnt['E' - 'A'] -= 1;
			cnt['R' - 'A'] -= 1;
			cnt['O' - 'A'] -= 1;
			res.push_back(0);
		}
		while(cnt['G' - 'A']) {
			cnt['E' - 'A'] -= 1;
			cnt['I' - 'A'] -= 1;
			cnt['G' - 'A'] -= 1;
			cnt['H' - 'A'] -= 1;
			cnt['T' - 'A'] -= 1;
			res.push_back(8);
		}
		while(cnt['X' - 'A']) {
			cnt['S' - 'A'] -= 1;
			cnt['I' - 'A'] -= 1;
			cnt['X' - 'A'] -= 1;
			res.push_back(6);
		}
		while(cnt['U' - 'A']) {
			cnt['F' - 'A'] -= 1;
			cnt['O' - 'A'] -= 1;
			cnt['U' - 'A'] -= 1;
			cnt['R' - 'A'] -= 1;
			res.push_back(4);
		}
		while(cnt['F' - 'A']) {
			cnt['F' - 'A'] -= 1;
			cnt['I' - 'A'] -= 1;
			cnt['V' - 'A'] -= 1;
			cnt['E' - 'A'] -= 1;
			res.push_back(5);
		}
		while(cnt['V' - 'A']) {
			cnt['S' - 'A'] -= 1;
			cnt['E' - 'A'] -= 1;
			cnt['V' - 'A'] -= 1;
			cnt['E' - 'A'] -= 1;
			cnt['N' - 'A'] -= 1;
			res.push_back(7);
		}
		while(cnt['I' - 'A']) {
			cnt['N' - 'A'] -= 1;
			cnt['I' - 'A'] -= 1;
			cnt['N' - 'A'] -= 1;
			cnt['E' - 'A'] -= 1;
			res.push_back(9);
		}
		while(cnt['W' - 'A']) {
			cnt['T' - 'A'] -= 1;
			cnt['W' - 'A'] -= 1;
			cnt['O' - 'A'] -= 1;
			res.push_back(2);
		}
		while(cnt['O' - 'A']) {
			cnt['O' - 'A'] -= 1;
			cnt['N' - 'A'] -= 1;
			cnt['E' - 'A'] -= 1;
			res.push_back(1);
		}
		while(cnt['T' - 'A']) {
			cnt['T' - 'A'] -= 1;
			cnt['H' - 'A'] -= 1;
			cnt['R' - 'A'] -= 1;
			cnt['E' - 'A'] -= 1;
			cnt['E' - 'A'] -= 1;
			res.push_back(3);
		}
		sort(res.begin(), res.end());
		cout << "Case #" << tcase << ": ";
		for(int i = 0; i < (int)(res.size()); ++i) {
			cout << res[i];
		}
		cout << endl;
	}
	return 0;
}