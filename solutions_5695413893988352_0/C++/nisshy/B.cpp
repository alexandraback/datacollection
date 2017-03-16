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

class solver {
private:
	int n;
	string C, J;
	string ans;
	long long best;

	void init() {
		ans = "";
		best = LLONG_MAX;
	}

	void calc() {
		const long long j_v = stoll(J);
		string tmp = C;

		const auto f = [&](char fil_v) {
			string buf = tmp;
			for(auto &c : buf) {
				if(c == '?') c = fil_v;
			}
			const long long c_v = stoll(buf);
			const long long diff = abs(j_v - c_v);
			if(diff < best) {
				ans = buf + ' ' + J;
				best = diff;
			}
			else if(diff == best) {
				chmin(ans, buf + ' ' + J);
			}
		};

		for(int i = 0; i < n; ++i) {
			for(char c = '0'; c <= '9'; ++c) {
				if(tmp[i] != '?' && tmp[i] != c) continue;
				const char buf = tmp[i];
				tmp[i] = c;
				f('0');
				f('9');
				tmp[i] = buf;
			}
			if(i < n) {
				if(tmp[i] != '?' && tmp[i] != J[i]) return;
				tmp[i] = J[i];
			}
		}
		assert(tmp == J);
		chmin(ans, J + ' ' + J);
		best = 0;
	}

	void dfs(int index) {
		if(index == n) {
			calc();
			return;
		}
		if(J[index] != '?') {
			dfs(index + 1);
			return;
		}
		for(char c = '0'; c <= '9'; ++c) {
			J[index] = c;
			dfs(index + 1);
		}
		J[index] = '?';
	}

public:
	void input() {
		init();
		cin >> C >> J;
		n = C.size();
	}

	string solve() {
		dfs(0);
		assert(!ans.empty());
		assert(best >= 0);
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
