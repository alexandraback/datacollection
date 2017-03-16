#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

#define dump(...) (cerr<<#__VA_ARGS__<<" = "<<(DUMP(),__VA_ARGS__).str()<<endl)

struct DUMP : ostringstream {
	template<class T> DUMP &operator,(const T &t) {
		if(this->tellp()) *this << ", ";
		*this << t;
		return *this;
	}
};

template<class T> inline void chmax(T &a, const T &b) { if(b > a) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if(b < a) a = b; }

template<class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
	return os << '(' << p.first << ", " << p.second << ')';
}

template<class Tuple, unsigned Index>
void print_tuple(ostream &os, const Tuple &t) {}

template<class Tuple, unsigned Index, class Type, class... Types>
void print_tuple(ostream &os, const Tuple &t) {
	if(Index) os << ", ";
	os << get<Index>(t);
	print_tuple<Tuple, Index + 1, Types...>(os, t);
}

template<class... Types>
ostream &operator<<(ostream &os, const tuple<Types...> &t) {
	os << '(';
	print_tuple<tuple<Types...>, 0, Types...>(os, t);
	return os << ')';
}

template<class Iterator>
ostream &dump_range(ostream &, Iterator, const Iterator &);

template<class T>
ostream &operator<<(ostream &os, const vector<T> &c) {
	return dump_range(os, c.cbegin(), c.cend());
}

template<class Iterator>
ostream &dump_range(ostream &os, Iterator first, const Iterator &last) {
	os << '[';
	for(int i = 0; first != last; ++i, ++first) {
		if(i) os << ", ";
		os << *first;
	}
	return os << ']';
}

bitset<32> a_bit, b_bit, k_bit;
long long memo[32][2][2][2];

long long powll(long long x, long long k) {
	long long res = 1;
	while(k--) res *= x;
	return res;
}

long long dfs(int digit, bool lessA, bool lessB, bool lessK) {
	if(lessA && lessB && lessK) {
		const long long t = powll(2, digit + 1);
		return t * t;
	}
	if(digit < 0) return 0;

	long long &res = memo[digit][lessA][lessB][lessK];
	if(res != -1) return res;

	res = 0;
	const bool a_ok = (lessA || a_bit[digit]);
	const bool b_ok = (lessB || b_bit[digit]);
	const bool k_ok = (lessK || k_bit[digit]);

	// Ad: 1 Bd: 1
	if(a_ok && b_ok && k_ok) {
		res += dfs(digit - 1, lessA, lessB, lessK);
	}

	// Ad: 1 Bd: 0
	if(a_ok) {
		res += dfs(digit - 1, lessA, b_ok, k_ok);
	}

	// Ad: 0 Bd: 1
	if(b_ok) {
		res += dfs(digit - 1, a_ok, lessB, k_ok);
	}

	// Ad: 0 Bd: 0
	res += dfs(digit - 1, a_ok, b_ok, k_ok);

	return res;
}

string solve() {
	int a, b, k;
	cin >> a >> b >> k;

	a_bit = a;
	b_bit = b;
	k_bit = k;

	memset(memo, -1, sizeof(memo));
	return to_string(dfs(31, false, false, false));
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": " << solve() << "\n";
	}

	return EXIT_SUCCESS;
}
