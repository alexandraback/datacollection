#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

#include <boost/multiprecision/gmp.hpp>

using namespace std;

typedef long long ll; typedef unsigned long long ull; typedef vector<ll> vi; typedef pair<ll,ll> pi;
const int _1e5 = 100000; const int _1e7 = 10000000; const int _1e9 = 1000000000;

template<typename A, typename B> ostream& operator<<(ostream& str, const pair<A,B>& p) { str << "(" << p.first << ", " << p.second << ")"; return str; }
template<typename T> ostream& operator<<(ostream& str,             const vector<T>& v) { str << "["; for(auto n : v) str << n << ", "; str << "]"; return str; }
template<typename T> ostream& operator<<(ostream& str,             const set<T>& v) { str << "{"; for(auto n : v) { str << n << ", "; } str << "}"; return str; }
template<typename K, typename V> ostream& operator<<(ostream& str, const unordered_map<K, V>& v) { str << "{"; for(auto&& p : v) { str << p.first << " => " << p.second << ", "; } str << "}"; return str; }

#define debug(x) cout <<  #x  << ": " << x << endl

typedef boost::multiprecision::mpz_int bigint;


bool compatible(int x, string& s) {
	for (int i=s.size(); i --> 0;) {
		if (s[i] == '?') {
		} else {
			// debug(x);
			// debug(s[i]);
			if ((x % 10) != (s[i] - '0'))
				return false;
		}
		x /= 10;
	}

	if (x != 0) return false;

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int cases; cin >> cases;
	for (int nc=1; nc<=cases; ++nc) {
		cout << "Case #" << nc << ": ";

		string coders,jammers;
		cin >> coders >> jammers;

		int mindist = 99999999;
		string cres, jres;

		for (int i=0; i<999; ++i) for (int j=0; j<999; ++j) {
			if (abs(i-j) < mindist && compatible(i,coders) && compatible(j, jammers)) {
				//debug(mindist);
				mindist = abs(i-j);
				cres = to_string(i);
				jres = to_string(j);
			}
		}

		cout << setfill('0') << setw(coders.size()) << cres << " ";
		cout << setfill('0') << setw(jammers.size()) << jres << endl;

		// string c,j;
		// cin >> c >> j;

		// size_t s = c.size();

		// // case c == j
		// bool possible = true;
		// string cres(s), jres(s);
		// for (int i=0; i<c.size(); ++i) {
		// 	if (c[i] == '?' && j[i] == '?') {
		// 		cres[i] = '0'; jres[i] = '0';
		// 	} else if (c[i] == '?') {
		// 		cres[i] = j[i]; jres[i] = j[i];
		// 	} else if (j[i] == '?') {
		// 		cres[i] = c[i]; jres[i] = c[i];
		// 	} else if (c[i] == j[i]) {
		// 		cres[i] = c[i]; jres[i] = j[i];
		// 	} else {
		// 		possible = false;
		// 		break;
		// 	}
		// }

		// if (possible) {
		// 	cout << cres << " "<< jres << endl;
		// 	continue;
		// }

		// // case c < j
		// bool sure = false;
		// bool possible = true;
		// string c2res(s), j2res(s);
		// for (int i=0; i<s; ++i) {
		// 	if (sure) {
		// 		cres[i] = (c[i] == '?') ? '9': c[i];
		// 		jres[i] = (j[i] == '?') ? '0' : j[i];
		// 		continue;
		// 	}

		// 	if (c[i] != '?' && j[i] != '?') {
		// 		c2res[i] = c[i]; j2res[i] = j[i];
		// 		if (c[i] < j[i]) {
		// 			sure = true;
		// 		} else if (c[i] > j[i] /* && !sure is always true*/) {
		// 			possible = false;
		// 			break;
		// 		}
		// 	} else if (c[i] == '?' && j[i] == '?') {
		// 		c2res[i] = '0'; j2res[i] = '1';
		// 		sure = true;
		// 	} else if (c[i] == '?') {
		// 		j2res[i] = j[i];

		// 		if (j[i] == '0') {
		// 			c2res[i] = '0';
		// 		} else {
		// 			c2res[i] = j[i]-1;
		// 			sure = true;
		// 		}
		// 	} else /* j[i] == '?' */ {
		// 		c2res[i] = c[i];

		// 		if (j)
		// 	}
		// }

	}
}
