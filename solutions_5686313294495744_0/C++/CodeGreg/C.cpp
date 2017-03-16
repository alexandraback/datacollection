#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <ctime>
#include <cstdlib>
#include <queue>

using namespace std;

#define D(x) x
#define REP(i,a,b) for (int i = (a); i < (b); ++i)

ifstream fin ("C-small-attempt0.in");
ofstream fout ("C-small-attempt0.out");

// Goldberg-Tarjan: Max-Flow O(V^2 * E)
// TODO: define MAX_NODES
#define MAX_NODES 2100

int N, dist[MAX_NODES], in[MAX_NODES], out[MAX_NODES];
bool is_active[MAX_NODES];

struct edge {
  int a, b, cap, flow;
  edge(int init_a, int init_b, int init_cap) :
    a(init_a), b(init_b), cap(init_cap), flow(0) {}
  void add_flow(int from, int add) {
    if (a == from) {
      out[a] += add; in[b] += add; flow += add;
    } else {
      out[b] += add; in[a] += add; flow -= add;
    }
  }
  int to(int from) {
    if (from == a) return b;
      return a;
  }
  int possible(int from) {
    if (from == a) return cap - flow;
      return flow;
  }
};

vector<vector<edge*> > g;

// TODO: define start and target nodes
bool isStart(int v) { return v == 0; }

bool isTarget(int v) { return v == 1; }

int main() {
	int T; fin >> T;

	REP(t, 1, T+1) {
		ios_base::sync_with_stdio(false);
		fout << setprecision(12) << fixed;

		// TODO: get number of nodes N
		fin >> N;
		N *= 2;
		N += 2;
		g.clear(); g.resize(N);

		// TODO: insert edges into g. Example: directed graph.
		// For undirected graph insert edges twice.
		int amax = 0; int bmax = 0;
		map<string, int> as;
		map<string, int> bs;
		for (int i = 0; i < N/2-1; ++i) {
			string a, b; fin >> a >> b;
			int a_ind = 0, b_ind = 0;

			if (as.find(a) != as.end()) {
				a_ind = as.find(a)->second;
			} else {
				a_ind = amax + 2; amax++;
				as.insert(make_pair(a, a_ind));
			}

			if (bs.find(b) != bs.end()) {
				b_ind = bs.find(b)->second;
			} else {
				b_ind = bmax+2+(N/2)-1; bmax++;
				bs.insert(make_pair(b, b_ind));
			}

//			cout << a_ind << " " << b_ind << endl;

		    edge* e = new edge(a_ind, b_ind, 1);
		    g[a_ind].push_back(e);
		    g[b_ind].push_back(e);
		}


		for (int i = 0; i < amax; ++i) {
		    edge* e = new edge(0, i+2, 1);
		    g[0].push_back(e);
		    g[i+2].push_back(e);
		}

		for (int i = 0; i < bmax; ++i) {
		    edge* e = new edge(i+2+(N/2)-1, 1, 1);
		    g[1].push_back(e);
		    g[i+2+(N/2)-1].push_back(e);
		}

		fill_n(dist, N, -1); fill_n(in, N, 0);
		fill_n(out, N, 0); fill_n(is_active, N, false);
		queue<int> border, active;

		// Initial distance
		for (int i = 0; i < N; ++i)
		if (isTarget(i)) {
			dist[i] = 0; border.push(i); }

		while (!border.empty()) {
		int v = border.front(); border.pop();
		for (edge* e : g[v]) {
			if (dist[e->to(v)] == -1 || dist[v] + 1 < dist[e->to(v)]) {
				dist[e->to(v)] = dist[v] + 1;
				border.push(e->to(v)); }
			}
		}

		for (int i = 0; i < N; ++i)
		if (isStart(i)) dist[i] = N;

		// Initialize preflow
		for (int s = 0; s < N; ++s) {
		if (!isStart(s)) continue;
		for (auto e : g[s]) {
		  if (!isStart(e->to(s)) && e->possible(s) > 0) {
			e->add_flow(s, e->possible(s));
			if (!is_active[e->to(s)] && !isTarget(e->to(s))) {
			  active.push(e->to(s)); is_active[e->to(s)] = true; }
		  }
		}
		}

		while (!active.empty()) {
			int v = active.front();
			active.pop();is_active[v] = false;

			// Push
			for (auto e : g[v]) {
				if (dist[v] == dist[e->to(v)] + 1 && e->possible(v) > 0) {
					e->add_flow(v, min(in[v] - out[v], e->possible(v)));
					if (in[e->to(v)] > out[e->to(v)] && !is_active[e->to(v)]
					  && !isTarget(e->to(v))) {
					  active.push(e->to(v)); is_active[e->to(v)] = true;
					}
				}
			}

			// Relabel
			if (in[v] > out[v]) {
				dist[v] = -1;
				for (auto e : g[v])
				if (e->possible(v) > 0 && (dist[v] == -1 || dist[e->to(v)] + 1 < dist[v]))
					dist[v] = dist[e->to(v)] + 1;
				active.push(v); is_active[v] = true;
			}
		}

		int max_flow = 0;
		for (int i = 0; i < N; ++i)
		if (isTarget(i)) max_flow += in[i] - out[i];

/*		for (int i = 0; i < N; ++i)
			cout << "in[" << i << "]: " << in[i] << ", out: " << out[i] << endl;*/

//		cout << "maxflow : " << max_flow << endl;

		fout << "Case #" << t << ": " << (N/2-1) - max_flow - (amax + bmax - 2*max_flow) << endl;
	}
	return 0;
}
