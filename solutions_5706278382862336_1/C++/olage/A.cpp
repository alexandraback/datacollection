#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>

using namespace std;

#define fr first
#define sd second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector < vector < double > > vvd;
typedef vector < double > vd;
typedef vector < pair < double, double> > vdd;
typedef vector < vector < long long > > vvl;
typedef vector < long long > vl;


ll gcd(ll a, ll b) {
	return !a ? b : gcd(b % a, a);
}

int main()
{

	ll T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		string s;
		cin >> s;
		ll u = 0, d = 0;
		int st = 0;
		for(size_t i = 0; i < s.size(); i++) {
			if(s[i] == '/') {
				st = 1;
			} else if(st == 0) {
				u += s[i] - '0';
				u *= 10;
			} else {
				d += s[i] - '0';
				d *= 10;
			}
		}
		u /= 10;
		d /= 10;
	
		ll g = gcd(u, d);
		//cout << g << endl;
		u /= g;
		d /= g;


//		cout << u << " " << d << endl;

		ll su = 0, sd = 0;
		ll pow = 1;
		int is_pow = 0;
		for(int i = 0; i < 40; i++) {
			if(pow <= u) {
				su++;
			}

			if(pow <= d) {
				sd++;
			}

			if(pow == d) {
				is_pow = 1;
			}
			pow *= 2;
		}
		cout << "Case #" << t << ": ";
		if(is_pow == 0) {
			cout << "impossible" << endl;
		} else {
			cout << sd - su << endl;
		}
	}

	return 0;
}
