#include <stdio.h>
#include <cassert>
#include <cstring>
#include <map>
#include <set>
#include <time.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

typedef pair <int, int> ii;
typedef pair <long long, long long> ll;

template<typename T>
struct NetworkFlow {
	struct Edge {
		int target, inverse_index;
		T capacity, flow;
		Edge(int t, int c, int ii) : target(t), capacity(c), flow(0), inverse_index(ii) {}
		T residual() const { return capacity - flow; }
	};

	int V;
	vector<vector<Edge> > adj;
	vector<int> levels, edges_tried;

	NetworkFlow(int V = 0) : V(V), adj(V), levels(V), edges_tried(V) {}

	void add_edge(int a, int b, T a2b, T b2a = 0) {
		int a2b_index = adj[a].size(), b2a_index = adj[b].size();
		adj[a].push_back(Edge(b, a2b, b2a_index));
		adj[b].push_back(Edge(a, b2a, a2b_index));
	}

	bool assign_levels(int source, int sink) {
		fill(levels.begin(), levels.end(), -1);
		queue<int> q; q.push(source);
		levels[source] = 0;
		while (!q.empty()) {
			int here = q.front(); q.pop();
			for (int i = 0; i < adj[here].size(); ++i) {
				const Edge& e = adj[here][i];
				if (levels[e.target] == -1 && e.residual() > 0) {
					levels[e.target] = levels[here] + 1;
					q.push(e.target);
				}
			}
		}
		return levels[sink] != -1;
	}

	int push_flow(int here, int sink, T flow) {
		if (here == sink) return flow;

		for (int& i = edges_tried[here]; i < adj[here].size(); ++i) {
			Edge& e = adj[here][i];
			if (e.residual() > 0 && levels[e.target] == levels[here] + 1) {
				T amt = push_flow(e.target, sink, min(flow, e.residual()));
				if (amt > 0) {
					Edge& e_inv = adj[e.target][e.inverse_index];
					e.flow += amt;
					e_inv.flow = -e.flow;
					return amt;
				}
			}
		}
		return 0;
	}

	T go(int source, int sink) {

		T total_flow = 0;
		while (assign_levels(source, sink)) {
			fill(edges_tried.begin(), edges_tried.end(), 0);
			while (true) {
				T pushed = push_flow(source, sink, numeric_limits<T>::max());
				if (pushed == 0) break;
				total_flow += pushed;
			}
		}
		return total_flow;
	}
};


const int N = 1005;
char s[N][22], p[N][22];
map <string, int> mp1, mp2;


void solve() {
	mp1.clear(), mp2.clear();

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf("%s %s", s + i, p + i);

	int sink = 2 * n + 1;
	NetworkFlow<int> g(sink + 1);
	int n1 = 0 , n2 = 0;
	
	for (int i = 0; i < n; i++) {
		if (!mp1[s[i]]) mp1[s[i]] = ++n1;
		if (!mp2[p[i]]) mp2[p[i]] = ++n2;
	}
	
	for (int i = 0; i < n; i++) {
		g.add_edge(mp1[s[i]], n1 + mp2[p[i]], 1);
	}
	
	for (int i = 1; i <= n1; i++)
		g.add_edge(0, i, 1);
	for (int i = 1; i <= n2; i++)
		g.add_edge(n1+i, sink, 1);

	printf("%d\n", n - (n1 + n2 - g.go(0, sink)));
	
}


int main() {
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int R = 1; R <= T; R++) {
		printf("Case #%d: ", R);
		solve();

	}
}