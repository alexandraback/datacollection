#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll t = 1;
ll gcd(ll a, ll b){
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

ll getPower(ll a){
	ll res = 0;
	t = 1;
	while (t < a){
		++res;
		t *= 2;
	}
	return res;
}

int main(){
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int testCount;
	cin >> testCount;
	for (int testCase = 1; testCase <= testCount; ++testCase){
		ll p, q;
		scanf("%lld/%lld\n", &p, &q);
		ll g = gcd(p, q);
		p /= g;
		q /= g;
//		cout << g << ' ' << p << ' ' << q << endl;
		cout << "Case #" << testCase << ": ";
		ll pw = getPower(q);
		if (t != q)
			cout << "impossible\n";
		else {
			while (p > 1){
				p /= 2;
				q /= 2;
				pw--;
			}
			cout << pw << endl;
		}
	}
	return 0;
}

