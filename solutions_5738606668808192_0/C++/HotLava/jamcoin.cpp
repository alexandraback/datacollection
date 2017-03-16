#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/gmp.hpp>
#include <boost/multiprecision/miller_rabin.hpp>

using namespace std;

typedef long long ll; typedef unsigned long long ull; typedef vector<ll> vi; typedef pair<ll,ll> pi;
const int _1e5 = 100000; const int _1e7 = 10000000; const int _1e9 = 1000000000;

template<typename A, typename B> ostream& operator<<(ostream& str, const pair<A,B>& p) { str << "(" << p.first << ", " << p.second << ")"; return str; }
template<typename T> ostream& operator<<(ostream& str,             const vector<T>& v) { str << "["; for(auto n : v) str << n << ", "; str << "]"; return str; }
template<typename T> ostream& operator<<(ostream& str,             const set<T>& v) { str << "{"; for(auto n : v) { str << n << ", "; } str << "}"; return str; }
template<typename K, typename V> ostream& operator<<(ostream& str, const unordered_map<K, V>& v) { str << "{"; for(auto&& p : v) { str << p.first << " => " << p.second << ", "; } str << "}"; return str; }

#define debug(x) cout <<  #x  << ": " << x << endl

typedef boost::multiprecision::cpp_int bigint;

int n = 16;
int j = 50;

bigint construct(int base, size_t bitmask) {
	bigint x = 0;
	bigint power = 1;

	for (int i=0; i<n; ++i) {
		if (bitmask & 1)
			x += power;

		power *= base;
		bitmask >>= 1;
	}

	return x;
}

template<typename T>
string to_binary_string(const T& num) {
	int chars = sizeof(T);
	int bits = 8*chars;
	const char* begin = reinterpret_cast<const char*>(&num);

	string s(bits, '0');
	for(int i=0; i<bits; ++i) {
		if(begin[i/8] & (1<<(i%8))) s.at(bits-i-1) = '1';
	}

	return s;
}

bigint get_divisor(bigint b) {
	for (bigint d=2; d<=sqrt(b); ++d) {
		if (b % d == 0)
			return d;
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);


	int jamcoins = 0;
	cout << "Case #1:\n";

	for (size_t bitmask=0; bitmask<(1<<(n-2)); ++bitmask) {
		size_t candidate = (1<<(n-1)) + (bitmask<<1) + 1;

		vector<bigint> divisors(9);

		for (int i=2; i<=10; ++i) {
			auto n = construct(i, candidate);
			bigint d;
			if (miller_rabin_test(n, 2)) goto next_candidate;

 			d = get_divisor(n);
			if (d == 0) goto next_candidate;

			divisors[i-2] = d;
		}

		cout << to_binary_string(*reinterpret_cast<uint16_t*>(&candidate)) << " ";
		for (auto d : divisors)
			cout << d << " ";
		cout << endl;

		++jamcoins;

		if (jamcoins == j) break;

		next_candidate:
			;

		//if (bitmask > 10) break; // debug
	}
}
