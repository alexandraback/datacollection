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

struct state {
	int v;
	vector<int> sta;
	int used;
	string s;
	state(int v_, const vector<int> &sta_, int used_, const string &s_):v(v_), sta(sta_), used(used_), s(s_) {}
	bool operator>(const state &st) const {
		return s > st.s;
	}
};

string solve() {
	int n, m;
	cin >> n >> m;

	vector<string> zip(n);
	for(auto &e : zip) cin >> e;

	vector<vector<int>> G(n);
	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}

	int s = 0;
	for(int i = 1; i < n; ++i) {
		if(zip[s] > zip[i]) s = i;
	}

	priority_queue<state, vector<state>, greater<state>> que;
	que.emplace(s, vector<int>{s}, 1 << s, zip[s]);

	while(!que.empty()) {
		state s = que.top();
		que.pop();

		if(s.used == (1 << n) - 1) return s.s;
		for(const auto &to : G[s.v]) {
			if(s.used & (1 << to)) continue;
			vector<int> tmp(s.sta);
			tmp.emplace_back(to);
			que.emplace(to, tmp, s.used | (1 << to), s.s + zip[to]);
		}

		if(s.sta.size() > 1) {
			s.sta.pop_back();
			s.v = s.sta.back();
			que.emplace(s);
		}
	}
	assert(false);
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
