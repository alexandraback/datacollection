#include <bits/stdc++.h>
using namespace std;


struct MaxFlow {
	/*
	 * NOTICE: all nodes indices must be GREATER THAN 0!
	 */
	static const int MAX_NODE = 10010;
	static const int MAX_EDGE = 2000010;
	static const int INF = 0x3f3f3f3f;

	int head[MAX_NODE];
	int counter[MAX_NODE];
	int h[MAX_NODE];

	int dest[MAX_EDGE];
	int pre[MAX_EDGE];
	int limit[MAX_EDGE];

	int total_flow, edge_cnt;
	int source, sink;

	MaxFlow() { }

	void clear() {
		memset(h, 0, sizeof(h));
		memset(counter, 0, sizeof(counter));
		memset(head, -1, sizeof(head));
		this->source = source;
		this->sink = sink;
		total_flow = 0;
		edge_cnt = 1;
	}

	void set_source_sink(int source, int sink) {
		this->source = source;
		this->sink = sink;
	}

	void add_edge(int x, int y, int z, bool flag = true) {
		dest[++edge_cnt] = y;
		limit[edge_cnt] = z;
		pre[edge_cnt] = head[x];
		head[x] = edge_cnt;
		if (flag) {
			add_edge(y, x, 0, false);
		}
	}

	int shortest_augment_path(int x, int remain) {
		if (x == sink) {
			return remain;
		}
		int tmp_remain = remain;
		int minh = sink - 1;

		for (int k = head[x]; k >= 0; k = pre[k]) {
			if (limit[k] > 0) {
				int y = dest[k];
				if (h[x] == h[y] + 1) {
					int ret = shortest_augment_path(y, min(remain, limit[k]));
					remain -= ret;
					limit[k] -= ret;
					limit[k ^ 1] += ret;
					if (remain == 0 || h[source] >= sink) {
						return tmp_remain - remain;
					}
				}
				if (h[y] < minh) {
					minh = h[y];
				}
			}
		}

		if (remain == tmp_remain) {
			if (--counter[h[x]] == 0) {
				h[source] = sink;
			}
			h[x] = minh + 1;
			++counter[h[x]];
		}
		return tmp_remain - remain;
	}

	int run() {
		counter[0] = sink;
		total_flow = 0;
		while (h[source] < sink) {
			total_flow += shortest_augment_path(source, INF);
		}
		return total_flow;
	}

} flow;

void __main() {
	int N;
	cin >> N;
	unordered_map<string, int> map1;
	unordered_map<string, int> map2;
	vector<string> vec1;
	vector<string> vec2;
	unordered_set<string> s1;
	unordered_set<string> s2;
	flow.clear();
	for (int i = 0; i < N; i++) {
		string a, b;
		cin >> a >> b;
		vec1.push_back(a);
		vec2.push_back(b);
		s1.insert(a);
		s2.insert(b);
	}
	int n1 = s1.size(), n2 = s2.size();
	for (int i = 0; i < N; ++i) {
		if (!map1.count(vec1[i])) {
			int t = map1.size();
			map1[vec1[i]] = t + 2;
		}
		if (!map2.count(vec2[i])) {
			int t = map2.size();
			map2[vec2[i]] = t + 2 + n1;
		}
		int na = map1[vec1[i]];
		int nb = map2[vec2[i]];
		flow.add_edge(na, nb, 1);
	}
	int source = 1;
	int sink = n1 + n2 + 2;
	for (int i = 2; i <= 1 + n1; ++i) {
		flow.add_edge(source, i, 1);
	}
	for (int i = n1 + 2; i <= n1 + n2 + 1; ++i) {
		flow.add_edge(i, sink, 1);
	}
	flow.set_source_sink(source, sink);
	int f = flow.run();
	cout << N - ((n1 + n2) - f) << endl;
}

int main() {
//	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int testcase = 1; testcase <= T; ++testcase) {
		cout << "Case #" << testcase << ": ";
		__main();
	}
	return 0;
}
