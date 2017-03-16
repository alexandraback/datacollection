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

void nprint(int n, char c) {
	for (int i=0; i<n; ++i) cout << c;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int cases; cin >> cases;
	for (int nc=1; nc<=cases; ++nc) {
		cout << "Case #" << nc << ": ";

		string s;
		cin >> s;

		map<char,int> counts;
		for (char c : s) ++counts[c];

		// reduce obvious
		int zeros = counts['Z'];
		counts['Z'] -= zeros;
		counts['E'] -= zeros;
		counts['R'] -= zeros;
		counts['O'] -= zeros;

		int twos = counts['W'];
		counts['T'] -= twos;
		counts['W'] -= twos;
		counts['O'] -= twos;

		int eights = counts['G'];
		counts['E'] -= eights;
		counts['I'] -= eights;
		counts['G'] -= eights;
		counts['H'] -= eights;
		counts['T'] -= eights;

		int threes = counts['T'];
		counts['T'] -= threes;
		counts['H'] -= threes;
		counts['R'] -= threes;
		counts['E'] -= threes;
		counts['E'] -= threes;

		int sixes = counts['X'];
		counts['S'] -= sixes;
		counts['I'] -= sixes;
		counts['X'] -= sixes;

		int fours = counts['R'];
		counts['F'] -= fours;
		counts['O'] -= fours;
		counts['U'] -= fours;
		counts['R'] -= fours;

		int ones = counts['O'];
		counts['O'] -= ones;
		counts['N'] -= ones;
		counts['E'] -= ones;

		int fives = counts['F'];
		counts['F'] -= fives;
		counts['I'] -= fives;
		counts['V'] -= fives;
		counts['E'] -= fives;		

		int sevens = counts['S'];

		int nines = counts['I'];

		nprint(zeros, '0');
		nprint(ones, '1');
		nprint(twos, '2');
		nprint(threes, '3');
		nprint(fours, '4');
		nprint(fives, '5');
		nprint(sixes, '6');
		nprint(sevens, '7');
		nprint(eights, '8');
		nprint(nines, '9');
		cout << endl;
	}
}
