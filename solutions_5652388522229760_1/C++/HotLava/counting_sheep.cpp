#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

typedef long long ll; typedef unsigned long long ull; typedef vector<ll> vi; typedef pair<ll,ll> pi;
const int _1e5 = 100000; const int _1e7 = 10000000; const int _1e9 = 1000000000;

template<typename A, typename B> ostream& operator<<(ostream& str, const pair<A,B>& p) { str << "(" << p.first << ", " << p.second << ")"; return str; }
template<typename T> ostream& operator<<(ostream& str,             const vector<T>& v) { str << "["; for(auto n : v) str << n << ", "; str << "]"; return str; }
template<typename T> ostream& operator<<(ostream& str,             const set<T>& v) { str << "{"; for(auto n : v) { str << n << ", "; } str << "}"; return str; }
template<typename K, typename V> ostream& operator<<(ostream& str, const unordered_map<K, V>& v) { str << "{"; for(auto&& p : v) { str << p.first << " => " << p.second << ", "; } str << "}"; return str; }

#define debug(x) cout <<  #x  << ": " << x << endl


int main() {
	ios_base::sync_with_stdio(false);
	
	int t;
	cin >> t;

	for (int cs=1; cs<=t; ++cs) {
		cout << "Case #" << cs << ": ";

		ull n;
		cin >> n;

		if (n == 0) {
			cout << "INSOMNIA\n";
			continue;
		}

		ull bitmask = 0;
		std::string str;
		for (int i=1; bitmask != 0b1111111111; ++i) {
			str = to_string(i*n);
			//debug(str);
			for (char c : str) {
				unsigned char num = c - '0';
				bitmask |= (1u << num);
			}
		}

		cout << str << '\n';
	}
}
