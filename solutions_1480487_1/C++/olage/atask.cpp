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
#define rs resize

typedef long long ll;
typedef vector < vector < double > > vvd;
typedef vector < double > vd;
typedef vector < pair < double, double> > vdd;
typedef vector < vector < long long > > vvl;
typedef vector < long long > vl;


int main()
{
	vl s;
	vd p;
	ll n, t;
	cin >> t;

	for(ll cs = 1; cs <= t; cs++) {
		s.clear();
		p.clear();
		cin >> n;
		ll b, sum = 0;
		for(int i = 0; i < n; i++) {
			cin >> b;
			s.pb(b);
			sum += b;
		}

		double pr = 0;
		ll pn = 0;

		for(ll i = 0; i < n; i++) {
			double b = 100*((2. * sum - n * s[i] ) / (n * sum));
			if (b < 0) {
				pr += b;
				pn++;
			}
			p.pb(b);			
		}

		if(pn != 0)
			for(ll i = 0; i < n; i++) {
				if (p[i] >= 0)
					p[i]+= (pr / (n - pn));
				else 
					p[i] = 0;
			}
		double d = 0;
		cout << "Case #" << cs << ":";
		for(ll i = 0; i < n; i++) {
			cout << fixed;
			cout.precision(6);
		//	d += p[i];
			cout << " " << p[i];
		}
		//cout << " " << d;
		cout << endl;
	}
}
