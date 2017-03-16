#include <bits/stdc++.h>

using namespace std;

const int M = 10000000;

int rev(int x) {
	int ans = 0;
	while (x) {
		ans = 10 * ans + (x % 10);
		x /= 10;
	}
	return ans;
}


std::vector<bool> used(M);
queue<int> q;
vector<int> d(M, M + 10);

void bfs() {
	d[1] = 1;
	used[1] = true;
	q.push(1);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		vector<int> g = {v + 1, rev(v)};
		for (int to : g)
			if (to < M && !used[to]) {
				used[to] = true;
				d[to] = d[v] + 1;
				q.push(to);
			}
	}
}


int n;

void read() {
	cin >> n;
}

int kill() {
	return d[n];
}

int main() {
	bfs();

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		read();
		cout << "Case #" << i << ": ";
		cout << kill() << endl;
		cerr << "case #" << i << " done.\n";
	}
	return 0;
}