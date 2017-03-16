// includes
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

// typedefs
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef complex<double> pt;

// macros
#define PRINT0(X) #X << " = " << (X)
#define PRINT1(X1) cout << PRINT0(X1) << endl;
#define PRINT2(X1, X2) cout << PRINT0(X1) << ", " << PRINT0(X2) << endl
#define PRINT3(X1, X2, X3) cout << PRINT0(X1) << ", " << PRINT0(X2) << ", " << PRINT0(X3) << endl
#define PRINT4(X1, X2, X3, X4) cout << PRINT0(X1) << ", " << PRINT0(X2) << ", " << PRINT0(X3) << ", " << PRINT0(X4) << endl
#define PRINTALL(COL) {cout << #COL << " ="; for (auto& printall_curr : (COL)) cout << " " << printall_curr;}

// basic methods
string int2string(int n) {
	stringstream str;
	str << n;
	string ret;
	str >> ret;
	return ret;
}

int string2int(const string& s) {
	return atoi(s.c_str());
}

bool is_upper(char c) {
	return 'A' <= c && c <= 'Z';
}

bool is_lower(char c) {
	return 'a' <= c && c <= 'z';
}

bool is_letter(char c) {
	return is_lower(c) || is_upper(c);
}

bool is_digit(char c) {
	return '0' <= c && c <= '9';
}

string to_upper(string s) {
	for (int i = 0; i < (int) s.length(); ++i)
		if (is_lower(s[i]))
			s[i] += 'A' - 'a';
	return s;
}

string to_lower(string s) {
	for (int i = 0; i < (int) s.length(); ++i)
		if (is_upper(s[i]))
			s[i] += 'a' - 'A';
	return s;
}

string reverse(string s) {
	for (int i = 0; i < (int) s.length()/2; ++i)
		s[i] = s[s.length() - 1 - i];
	return s;
}

// number theoretic methods
template<class T>
T gcd(T a, T b) {
	T t;
	while (b > 0) {
		t = b;
		b = a%b;
		a = t;
	}
	return a;
}

vector<int> primes;
vector<bool> is_prime;
void compute_primes(int cap) {
	// resize cap if necessary
	if (cap%2 == 1)
		++cap;
	// fill in is_prime
	is_prime.clear();
	is_prime.resize(cap);
	for (int i = 0; i < cap; ++i) {
		is_prime[i] = false;
		is_prime[++i] = true;
	}
	is_prime[1] = false;
	is_prime[2] = true;
	for (int i = 3; i*i < cap; i+=2)
		if (is_prime[i])
			for (int j = i*i; j < cap; j+=2*i)
				is_prime[j] = false;
	// fill in primes vector
	primes.clear();
	primes.push_back(2);
	for (int i = 3; i < cap; i+=2)
		if (is_prime[i])
			primes.push_back(i);
}

// graph methods
struct V {
	int val;
	vector<int> ws;
	vector<int> ns;
};
vector<V> vs;

struct S {
	int first;
	int second;
	bool operator<(const S& o) const {
		if (first != o.first)
			return first < o.first;
		return second < o.second;
	}
};

// main
int main() {
	int num_tests; cin >> num_tests;
	for (int test = 1; test <= num_tests; ++test) {
		cout << "Case #" << test << ": ";
		int ans = 0;
		int stars = 0;
		int n; cin >> n;
		S ba[n];
		for (int i = 0; i < n; ++i)
			cin >> ba[i].second >> ba[i].first;
		sort(ba, ba + n);
		for (int i = 0; i < n; ++i) {
			if (ba[i].first <= stars) {
				if (ba[i].second == (1 << 30))
					++stars;
				else
					stars += 2;
				++ans;
			} else {
				bool found = false;
				for (int j = n; j >= i; --j) {
					if (ba[j].second <= stars) {
						++stars;
						++ans;
						ba[j].second = (1 << 30);
						found = true;
						--i;
						break;
					}
				}
				if (!found) {
					break;
				}
			}
		}
		if (stars == 2*n) cout << ans << endl;
		else cout << "Too Bad" << endl;
	}
}

