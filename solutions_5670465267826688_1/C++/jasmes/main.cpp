#include <iostream>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <functional>

using namespace std;

#define upto(i,n) for(int i = 0; i<n; ++i)


typedef long long  ll;
#define E 1
#define I 2
#define J 3
#define K 4


ll op[5][5] = {
	{ 0, 0,  0,  0,  0 },
	{ 0, E,  I,  J,  K },
	{ 0, I, -E,  K, -J },
	{ 0, J, -K, -E,  I },
	{ 0, K,  J, -I, -E } };


ll mult(ll a, ll b) {
	ll res = op[abs(a)][abs(b)];

	ll sign = a*b;
	return sign<0 ? -res : res;
}


ll mult(ll a, char c) {
	ll b;
	switch (c){
	case 'i': b = I; break;
	case 'j': b = J; break;
	case 'k': b = K; break;
	}
	ll res = op[abs(a)][ b ];

	ll sign = a*b;
	return sign<0 ? -res : res ;
}

ll countPref(const string & s){
	ll res = 1;
	for (auto x : s){
		res = mult(res, x);
	}
	return res;
}


ll myPow(ll x, ll n){
	if (n == 0) return E;
	if (n == 1) return x;
	if ( n&1 ) 
		return mult(x, myPow(x, n - 1));
	ll a = myPow(x, n / 2);
	return mult(a, a);

}

bool check(const string &s, ll n, ll exp, ll prefix){
	//ll len = n*min(1000LL, exp);
	ll len = n*exp;
	ll x = 1;
	ll tmp = E;
	bool ii = false;
	bool jj = false;
	
	int k=0;

	for (int i = 0; i < len; i++) {
		tmp = mult(tmp, s[i%n]);
		if (!ii && tmp == I) {
			ii = true;
			tmp = E;
		}
		if (ii && !jj && tmp == J){
			jj = true;
			tmp = E;
			k = i+1;
			break;
		}
		if ((i%n) == (n - 1)) x++;
	}
	tmp = E;
	for (; k%n > 0 ; k++)
		tmp = mult(tmp, s[k%n]);

	ll p = myPow(prefix, max(exp - x, 0LL));

	return ii && jj && mult(tmp, p) == K;
	
}


int main() {
	ll t, l, x;
	string s;

	cin >> t;
	for (ll tc = 1; tc <= t; ++tc) {
		cout << "Case #" << tc << ": ";

		cin >> l >> x;
		cin >> s;


		ll prefix = countPref(s);
		//cout << "prefix: "<<prefix << endl;
		if ( myPow(prefix, x) != -E) {
			cout << "NO" << endl;
			continue;
		}

		if (check(s, l ,x, prefix)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		
	}
		


	return 0;
}