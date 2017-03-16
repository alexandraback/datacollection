#include<iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	if(b == 0)
		return a;
	return gcd(b, a%b);
}
char c;

int main() {
	int t;
	cin >> t;
	
	for(int TIND = 0; TIND < t; TIND ++) {
		ll tpow = 2, p, q, div, pind = 1;
		cin >> p >> c >> q;
	
		div = gcd(p, q);
		p /= div;
		q /= div;
	
		while( (q & tpow) == 0)
			tpow *= 2, pind++;
		
		cout << "Case #" << TIND + 1 << ": ";
		
		if(q == tpow) {
			tpow = 2;
			while(p >= tpow)
				tpow*= 2, pind--;
			cout << pind << '\n';
		}
		else
			cout << "impossible\n";
	}
	
	return 0;
}
