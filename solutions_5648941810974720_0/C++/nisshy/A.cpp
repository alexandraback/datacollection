// * template
#include <bits/stdc++.h>

#ifdef LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif

using namespace std;

template<class T> inline void chmax(T &a, const T &b) { if(a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if(a > b) a = b; }

template<class T, class U> inline void fill_array(T &e, const U &v) { e = v; }
template<class T, class U, size_t s> inline void fill_array(T (&a)[s], const U &v) {for(auto&e:a)fill_array(e,v);}
template<class T, class U, size_t s> inline void fill_array(array<T, s> &a, const U &v) {for(auto&e:a)fill_array(e,v);}
template<class T, class U> inline void fill_array(vector<T> &a, const U &v) {for(auto&e:a)fill_array(e,v);}

// * solve

const string words[10] = {
	"ZERO",
	"ONE",
	"TWO",
	"THREE",
	"FOUR",
	"FIVE",
	"SIX",
	"SEVEN",
	"EIGHT",
	"NINE"
};

class solver {
private:
	string s;
	string ans;
	int cnt[128];

	void init() {
		ans = "";
		memset(cnt, 0, sizeof(cnt));
	}

	void dec(const int x) {
		ans += x + '0';
		for(const auto &c : words[x]) {
			assert(cnt[c] > 0);
			--cnt[c];
		}
	}

public:
	void input() {
		init();
		cin >> s;
	}

	string solve() {
		for(const auto &c : s) {
			++cnt[c];
		}

		while(cnt['Z'] > 0) dec(0);
		while(cnt['W'] > 0) dec(2);
		while(cnt['U'] > 0) dec(4);
		while(cnt['X'] > 0) dec(6);
		while(cnt['G'] > 0) dec(8);
		while(cnt['F'] > 0) dec(5);
		while(cnt['O'] > 0) dec(1);
		while(cnt['V'] > 0) dec(7);
		while(cnt['N'] > 0) dec(9);
		while(cnt['R'] > 0) dec(3);
		assert(accumulate(begin(cnt), end(cnt), 0) == 0);
		sort(begin(ans), end(ans));
		return ans;
	}
};

// * main

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

#ifdef _OPENMP
	int next_index = 0;
	vector<decltype(solver().solve())> ans(T);

	#pragma omp parallel for
	for(int t = 0; t < T; ++t) {
		int index;
		solver s;

		#pragma omp critical
		{
			index = next_index++;
			s.input();
		}

		ans[index] = s.solve();
	}

	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": " << ans[t - 1] << '\n';
	}

#else
	solver s;
	for(int t = 1; t <= T; ++t) {
		s.input();
		const auto ans = s.solve();
		cout << "Case #" << t << ": " << ans << '\n';
	}
#endif

	return EXIT_SUCCESS;
}
