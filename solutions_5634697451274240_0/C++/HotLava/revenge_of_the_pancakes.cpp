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

void flip_char(char& c) {
	if (c == '+') 
		c = '-';
	else 
		c = '+';
}

// flip [left, right]
void flip(int left, int right, string& str) {
	while (left < right) {
		swap(str[left], str[right]);
		flip_char(str[left]);
		flip_char(str[right]);
		++left, --right;
	}

	if (left == right) flip_char(str[left]);
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int t;
	cin >> t;

	for (int cs=1; cs<=t; ++cs) {
		cout << "Case #" << cs << ": ";

		string s;
		cin >> s;

		int flips = 0;
		size_t left = 0, right = s.size();

		while(true) {
			while(right > 0 && s[right-1] == '+') --right;

			if (right == 0) break;

			++flips;
			switch (s[0]) {
			case '+': {
				size_t bound = 0;
				while (bound < s.size() && s[bound] == '+') ++bound;
				flip(0, bound-1, s);
				break;
			}
			case '-': {
				flip(0, right-1, s);
				break; 
			}
			}
		}

		cout << flips << endl;
	}
}
