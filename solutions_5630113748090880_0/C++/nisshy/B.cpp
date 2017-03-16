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
	int m;
	vector<vector<int>> lists;

	void init() {
	}

public:
	void input() {
		init();
		cin >> n;
		m = 2 * n - 1;
		lists.clear();
		lists.reserve(m);
		for(int i = 0; i < m; ++i) {
			vector<int> x(n);
			for(auto &e : x) cin >> e;
			lists.emplace_back(x);
		}
	}

	auto solve() {
		for(int bit = 0; bit < (1 << (m)); ++bit) {
			if(__builtin_popcount(bit) != n) continue;

			vector<vector<int>> row, col;
			for(int i = 0; i < m; ++i) {
				if(bit & (1 << i)) {
					row.emplace_back(lists[i]);
				}
				else {
					col.emplace_back(lists[i]);
				}
			}

			sort(begin(row), end(row));
			sort(begin(col), end(col));

			int j = 0;
			int unused = -1;

			for(int i = 0; i < n; ++i) { // row
				if(i == n - 1 && j == n - 1) {
					unused = n - 1;
					break;
				}

				bool ok = true;
				for(int k = 0; k < n; ++k) {
					if(row[k][i] != col[j][k]) {
						ok = false;
						break;
					}
				}

				if(!ok) {
					if(unused == -1) {
						unused = i;
					}
					else {
						goto next;
					}
				}
				else {
					++j;
				}
			}

			if(unused != -1) {
				ostringstream oss;
				for(int i = 0; i < n; ++i) {
					if(i) oss << ' ';
					oss << row[i][unused];
				}
				return oss.str();
			}

			next:;
		}
		assert(false);
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
