#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <bitset>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

const long long INF = 1000000000000000LL;

class MaximumFlow {
	int s, f;
public:
	struct edge {
		int u, v;
		long long capacity, flow;
		edge() { u = v = capacity = flow = 0; }
		edge(int u_, int v_, long long capacity_, long long flow_) :
			u(u_), v(v_), capacity(capacity_), flow(flow_) {
		}
	};

	vector <edge> edges;
	vector <vector <int> > graph;
	vector <int> ptr, level;
	queue <int> q;
	int n;

	MaximumFlow() {}

	MaximumFlow(int number) {
		n = number;
		graph.resize(n);
		ptr.assign(n, 0);
		level.resize(n);
	}

	void addEdge(int u, int v, long long capacity) {
		int sz = (int)(edges.size());
		edges.push_back(edge(u, v, capacity, 0));
		edges.push_back(edge(v, u, 0, 0));
		graph[u].push_back(sz);
		graph[v].push_back(sz + 1);
	}

	void updateLevels() {
		level.assign(n, -1);
		q.push(s);
		level[s] = 0;
		while (!q.empty()) {
			int topq = q.front();
			q.pop();
			for (int index = 0; index < graph[topq].size(); ++index) {
				int i = graph[topq][index];
				int to = edges[i].v;
				if (edges[i].capacity - edges[i].flow == 0) {
					continue;
				}
				if (level[to] == -1) {
					level[to] = level[topq] + 1;
					q.push(to);
				}
			}
		}
	}

	long long pushFlow(int v, long long flow) {
		if (v == f || flow == 0) {
			return flow;
		}
		for (; ptr[v] < graph[v].size(); ++ptr[v]) {
			int index = graph[v][ptr[v]];
			int to = edges[index].v;
			if (level[v] + 1 == level[to]) {
				int pushed = pushFlow(to, min(flow, edges[index].capacity - edges[index].flow));
				if (pushed > 0) {
					edges[index].flow += pushed;
					edges[index ^ 1].flow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}

	long long dinicFlow(int start, int finish) {
		s = start, f = finish;
		long long result = 0;
		while (true) {
			updateLevels();
			if (level[f] == -1) {
				break;
			}
			while (true) {
				long long pushed = pushFlow(start, INF);
				if (pushed == 0) {
					break;
				}
				result += pushed;
			}
			ptr.assign(n, 0);
		}
		return result;
	}

	vector<int> getVerts() {
		set<int> tot;
		for (int i = 0; i < n; ++i) {
			tot.insert(i);
		}

		for (int i = 0; i < edges.size(); ++i) {
			if (edges[i].u < edges[i].v && edges[i].capacity > 0 && edges[i].flow > 0) {
				tot.erase(edges[i].u);
				tot.erase(edges[i].v);
			}
		}
		return vector<int>(tot.begin(), tot.end());
	}
};

void solve(int tcase) {
	printf("Case #%d: ", tcase);
	int n;

	vector<pair<int, int> > vals;

	map<string, int> words1;
	map<string, int> words2;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s, t;
		cin >> s >> t;
		int ids = -1, idt = -1;
		if (words1.count(s)) {
			ids = words1[s];
		} else {
			words1[s] = words1.size();
			ids = words1[s];
		}

		if (words2.count(t)) {
			idt = words2[t];
		} else {
			words2[t] = words2.size();
			idt = words2[t];
		}

		vals.push_back(make_pair(ids, idt));
	}

	MaximumFlow flow(2 * n + 2);

	for (int i = 0; i < n; ++i) {
		flow.addEdge(2 * n, i, 1);
		flow.addEdge(n + i, 2 * n + 1, 1);
		flow.addEdge(vals[i].first, vals[i].second + n, 1);
	}

	int res = flow.dinicFlow(2 * n, 2 * n + 1);

	vector<int> v = flow.getVerts();

	int addon = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] < n && v[i] < words1.size()) {
			++addon;
		}
		if (v[i] >= n && v[i] < 2 * n && v[i] < n + words2.size()) {
			++addon;
		}
	}
	
	cout << n - res - addon << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		solve(i + 1);
	}


	return 0;
}
