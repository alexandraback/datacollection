#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cfloat>
#include <climits>
#include <numeric>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORS(i,a,b,s) for (int i = (a); i < (b); i=i+(s))
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

const double PI = 2.0 * acos(0.0);

string int_to_str(int v) {
	ostringstream os;
	os << v;
	return os.str();
}

ll str_to_int(string s) {
	istringstream is(s);
	ll v;
	is >> v;
	return v;

}
ll p,q;
ll seed = 1099511627776;

int getGen(double elfs){
	int gen = 0;
	while(elfs >= 2){
		gen++;
		elfs/=2;
	}
	return 40-gen;
}

int main() {
	int tc;
	cin >> tc;
	FOR(cas, 1, tc+1){
		string s;
		getline(cin, s, '/');
		p=str_to_int(s);
		cin >> q;
		double fac = (double)seed / (double)q;
		double elfs = fac*p;
		cout << "Case #" << cas << ": ";
		if(abs(floor(elfs)-elfs) < eps){
			cout << getGen(elfs) << endl;
		}else{
			cout << "impossible" << endl;
		}

	}
}