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

// * Dinic
template<class Weight>
class max_flow {
private:
	struct edge {
		int to;
		Weight cap;
		int rev;
		edge(const int to_, const Weight cap_, const int rev_):to(to_), cap(cap_), rev(rev_){}
	};

	static constexpr Weight INF = numeric_limits<Weight>::max() / 3;

	vector<vector<edge> > G;
	vector<int> level;
	vector<int> iter;

public:
	max_flow(int V):G(V), level(V), iter(V) {}

	void add_edge(const int from, const int to, const Weight cap) {
		if(from == to) return;
		G[from].emplace_back(to, cap, G[to].size());
		G[to].emplace_back(from, 0, G[from].size() - 1);
	}

	void bfs(const int s) {
		queue<int> que;
		fill(begin(level), end(level), -1);
		que.push(s);
		level[s] = 0;

		while(!que.empty()) {
			const int v = que.front();
			que.pop();

			for(const auto &e : G[v]) {
				if(e.cap > 0 && level[e.to] == -1) {
					level[e.to] = level[v] + 1;
					que.push(e.to);
				}
			}
		}
	}

	Weight dfs(const int v, const int t, const Weight f) {
		if(v == t) return f;

		for(int &i = iter[v]; i < G[v].size(); ++i) {
			edge &e = G[v][i];
			if(e.cap > 0 && level[v] < level[e.to]) {
				const Weight d = dfs(e.to, t, min(f, e.cap));
				if(d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}

		return 0;
	}

	Weight solve(int s, int t) {
		Weight flow = 0;
		while(true) {
			bfs(s);
			if(level[t] < 0) return flow;
			fill(begin(iter), end(iter), 0);
			for(Weight f; (f = dfs(s, t, INF)) > 0; flow += f);
		}
	}
};


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
		map<string, int> F, S;
		for(const auto &e : topics) {
			if(!F.count(e.first)) F.emplace(e.first, F.size());
			if(!S.count(e.second)) S.emplace(e.second, S.size());
		}

		const int V = F.size() + S.size();
		const int source = V;
		const int sink = source + 1;
		max_flow<int> mf(V + 2);

		for(int i = 0; i < F.size(); ++i) {
			mf.add_edge(source, i, 1);
		}

		for(int i = 0; i < S.size(); ++i) {
			mf.add_edge(i + F.size(), sink, 1);
		}

		for(const auto &e : topics) {
			const int a = F[e.first];
			const int b = S[e.second] + F.size();
			mf.add_edge(a, b, 1);
		}

		const auto result = mf.solve(source, sink);
		const auto ans = n - (V - result);
		assert(ans >= 0 && ans <= n);
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
