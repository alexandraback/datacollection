#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
#include <utility>
#include <unordered_map>
#include <map>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;


ll popcnt(ll i) {
	ll cnt = 0;

	while(i) {
		if(i & 1) ++cnt;
		i >>= 1;
	}

	return cnt;
}


ll 
gcd ( ll a, ll b )
{
  ll c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int main() {
	int ncases;
	cin >> ncases;

	for(int c=1; c<=ncases; ++c) {
		ll p, q;
		char slash;
		cin >> p >> slash >> q;

		ll g = gcd(p,q);
		p /= g;
		q /= g;

		//cout << g << " "  << p << " " << q << endl;

		cout << "Case #" << c << ": ";
		if(popcnt(q) > 1)
			cout << "impossible" << endl;
		else {
			int cnt = 0;

			while(p < q) { q /= 2; ++cnt; }

			//while(!(q&(1<<cnt))) ++cnt;

			cout << cnt << endl;
		}
	}
}