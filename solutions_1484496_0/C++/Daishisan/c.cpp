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
typedef long long ll;
typedef long double ld;
typedef complex<double> pt;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

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

// main
int main() {
	int num_tests; cin >> num_tests;
	for (int test = 1; test <= num_tests; ++test) {
		cout << "Case #" << test << ":" << endl;
		int n; cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		map<int, vector<int> > seen;
		bool possib = false;
		for (int i = 1; i < (1 << n); ++i) {
			int ii = i;
			int key = 0;
			vector<int> entry;
			for (int j = 0; ii > 0; ++j) {
				if (ii%2) {
					key += a[j];
					entry.push_back(a[j]);
				}
				ii /= 2;
			}
			if (seen.find(key) == seen.end())
				seen[key] = entry;
			else {
				possib = true;
				for (int j = 0; j + 1 < (int) entry.size(); ++j)
					cout << entry[j] << " ";
				cout << entry.back() << endl;
				for (int j = 0; j + 1 < (int) seen[key].size(); ++j)
					cout << seen[key][j] << " ";
				cout << seen[key].back() << endl;
				break;
			}
		}
		if (!possib)
			cout << "Impossible" << endl;
	}
}

