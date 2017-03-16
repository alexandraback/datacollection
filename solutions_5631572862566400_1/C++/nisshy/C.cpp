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
	vector<int> bff;
	vector<vector<int>> rbff;
	vector<bool> used;

	void init() {
	}

public:
	void input() {
		init();
		cin >> n;
		bff.resize(n);
		rbff.assign(n, vector<int>());
		for(int i = 0; i < n; ++i) {
			cin >> bff[i];
			--bff[i];
			rbff[bff[i]].emplace_back(i);
		}
	}

	int find_cycle(const int v, const int s, const int p, const int num) {
		if(bff[v] == p) return 0;
		if(bff[v] == s) return num;
		if(used[bff[v]]) return 0;
		used[v] = true;
		const int result = find_cycle(bff[v], s, v, num + 1);
		if(result == 0) used[v] = false;
		return result;
	}

	int rdfs(const int v, const int p) {
		int res = 0;
		for(const auto &u : rbff[v]) {
			if(u == p) continue;
			chmax(res, rdfs(u, v));
		}
		return res + 1;
	}

	int solve() {
		int ans = 0;
		used.assign(n, false);
		for(int v = 0; v < n; ++v) {
			if(used[v]) continue;
			chmax(ans, find_cycle(v, v, -1, 1));
		}

		int sum = 0;
		for(int v = 0; v < n; ++v) {
			if(used[v]) continue;
			for(const auto &u : rbff[v]) {
				if(used[u]) continue;
				if(bff[v] == u) {
					dump(u, v, bff[u], bff[v]);
					sum += rdfs(u, v) + rdfs(v, u);
					used[u] = used[v] = true;
				}
			}
		}

		chmax(ans, sum);
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
