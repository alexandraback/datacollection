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
	vector<pair<string, string>> topics;

	void init() {
	}

public:
	void input() {
		init();
		cin >> n;
		topics.resize(n);
		for(auto &e : topics) {
			cin >> e.first >> e.second;
		}
	}

	int solve() {
		int ans = 0;
		for(int bit = 0; bit < (1 << n); ++bit) {
			const int num = __builtin_popcount(bit);
			if(num <= ans) continue;

			set<string> F, S;
			for(int i = 0; i < n; ++i) {
				if(bit & (1 << i)) continue;
				F.emplace(topics[i].first);
				S.emplace(topics[i].second);
			}

			for(int i = 0; i < n; ++i) {
				if(!(bit & (1 << i))) continue;
				if(!F.count(topics[i].first) || !S.count(topics[i].second)) goto next;
			}
			ans = num;
		next:;
		}
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
