#include <bits/stdc++.h>
using namespace std;

vector<int> B;
vector<vector<int> > G;
vector<bool> V;

int dfs_height(int i, int p) {
	V[i] = true;
	int best = 0;
	for(int j = 0; j < G[i].size(); j++) {
		if(p == G[i][j]) continue;
		best = max(dfs_height(G[i][j], i), best);
	}
	return best + 1;
}

void code() {
	int N;
	cin >> N;
	B = vector<int>(N);
	G = vector<vector<int> >(N);
	V = vector<bool>(N, false);
	for(int i = 0; i < N; i++) {
		cin >> B[i];
		B[i]--;
		G[B[i]].push_back(i);
	}

	int best = 0;
	int indcount = 0;
	for(int i = 0; i < N; i++) {
		if(B[B[i]] == i) {
			indcount += dfs_height(i, B[i]) + dfs_height(B[i], i);
		}
	}
	best = max(indcount / 2, best);

	int len = 0;

	for(int i = 0; i < N; i++) {
		if(V[i]) continue;
		map<int, int> m;
		m[i] = 0;
		V[i] = true;
		int n = 0;
		int cur = B[i];
		while(m.find(cur) == m.end()) {
			if(V[cur]) goto next;
			V[cur] = true;
			m[cur] = ++n;
			cur = B[cur];
		}

		len = n - m[cur] + 1;
		best = max(len, best);

		next:;
	}

	cout << best;
}

int main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		code();
		cout << endl;
	}
}
