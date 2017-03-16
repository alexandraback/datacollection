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

bigint kadic(ull k, const vector<ull>& v) {
	ull base = 1;
	bigint res = 0;

	for (auto a : v) {
		if (a >= k) a = k-1;
		res += base*a;
		base *= k;
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int t;
	cin >> t;

	for (int nc=1; nc<=t; ++nc) {
		cout << "Case #" << nc << ": ";

		ull k,c,s;
		cin >> k >> c >> s;

		int positions_per_guess = c;

		if (s*positions_per_guess < k) {
			cout << "IMPOSSIBLE\n";
			continue;
		}

		set<bigint> guesses;

		int pcursor = 0;
		while (pcursor < k) {
			vector<ull> positions(c);
			for(auto& p : positions) {
				p = pcursor++;
			}
			//debug(positions);

			guesses.insert(kadic(k, positions));
		}

		for (auto g : guesses) {
			cout << g+1 << " ";
		}

		cout << endl;
	}
}
