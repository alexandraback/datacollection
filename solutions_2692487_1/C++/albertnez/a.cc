#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <sstream>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef unsigned long long ll;
typedef vector<ll> vl;
typedef vector<vl> vll;

vi v;

void aprox(ll& n, int obj, ll& op) {
	while (n <= obj) {
		n += n-1;
		++op;
	}
}



int main() {
	int t, n;
	ll a;
	cin >> t;
	for (int cases = 1; cases <= t; ++cases) {
		cin >> a >> n;
		v = vi(n);
		ll op = 0;
		for (int i = 0; i < n; ++i){
			cin >> v[i];
		}

		//case a == 1
		if (a == 1) {
			cout << "Case #" << cases << ": " << n << endl;
		}
		else {
			sort(v.begin(), v.end());
			//precalc operations
			ll tmp = a;
			ll maxop = 0;
			for (int i = 0; i < v.size(); ++i) {
				if (tmp > v[i]){
					tmp += v[i];
				}
				else {
					aprox(tmp, v[i], maxop);
					tmp += v[i];
				}
			}

			for (int i = 0; i < v.size(); ++i) {
				if (a > v[i]) {
					a += v[i];
				}
				else {
					if (a*2-1 > v[i]) {
						a = a*2 -1;
						a += v[i];
						++op;
					}
					else if (maxop - op <= v.size() - i) {
						aprox(a, v[i], op);
						a += v[i];
					}
					else {
						op += v.size() - i;
						break;

					}

				}
			}
			cout << "Case #" << cases << ": " << op << endl;
		}
	}


}