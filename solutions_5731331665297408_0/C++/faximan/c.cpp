#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <math.h>
#include <stack>
#include <queue>
#include <stdio.h>

using namespace std;

int t, n, m;
string zip[50];
string best = "";

struct edge {
	int a, b;
	//edge (int aa, int bb) : a(aa), b(bb) {}
	bool operator<(const edge& rhs) const {
		return zip[b] < zip[rhs.b];
	}

};

edge edges[10001];
int numEdges;

std::vector<int> v;
int visited[50];
int parent[50];

// fly from p, is current in c.
bool isParent(int p, int c) {
	if (p == c) return true;
	if (parent[p] == -2) return true;
	if (parent[c] < 0) return false;
	return isParent(p, parent[c]);
}

void solve(int cur) {
	if (v.size() == n) {
		string res = "";
		for (int i = 0; i < n; i++) {
			res += zip[v[i]];
		}
		if (best == "" || res < best) {
			best = res;
		}
		return;
	}

	for (int i = 0; i < numEdges; i++) {
		if (visited[edges[i].b])
			continue;
		if (!visited[edges[i].a])
			continue;
		if (!isParent(edges[i].a, cur))
			continue;


		visited[edges[i].b] = 1;
		v.push_back(edges[i].b);
	//	cout << parent[edges[i].b] << endl;
		parent[edges[i].b] = edges[i].a;
		solve(edges[i].b);
		parent[edges[i].b] = -1;
		v.pop_back();
		visited[edges[i].b] = 0;

	}
}

int main() {
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		best = "";
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> zip[i];
		}

		numEdges = 0;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			edge e;
			e.a = x-1;
			e.b = y-1;
			edges[numEdges++] = e;
			e.a = y-1;
			e.b = x-1;
			edges[numEdges++] = e;
		}

		sort (edges, edges + numEdges);

		for (int i = 0; i < n; i++) {
			memset(parent, -1, sizeof parent);
			memset(visited, 0, sizeof visited);
			v.clear();
			v.push_back(i);
			visited[i] = 1;
			parent[i] = -2;
			solve(i);
		}
		printf("Case #%d: %s\n", tt, best.c_str());
	}


  return 0;
}
