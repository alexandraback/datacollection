#include <bits/stdc++.h>

using namespace std;

#define ll long long

int t;


void solve();

int main() {
	ios::sync_with_stdio(0);

	bool file = true;
	if (file) {
		freopen("B-small-attempt0.in","r", stdin);
		freopen("output.out", "w", stdout);
	}

	cin >> t;
	for (int z = 1; z<= t; z++) {
		cout << "Case #" << z << ": ";
		solve();
		cout << endl;
	}
	return 0;
}

ll b,m;
bool graph[8][8];

bool cyclic() {
	for (int i = 0; i < b-1; i++) {
		stack<int> s;
		s.push(i);
		bool visited[8];
		for (int j = 0; j < b; j++)
			visited[j] = false;
		while(!s.empty()) {
			int cur = s.top();
			s.pop();
			if (cur == i && visited[cur]) return true;
			if (visited[cur])
				continue;
			visited[cur] = true;
			for (int j = 0; j < b; j++) {
				if (graph[cur][j] && j == i)
					return true;
				if (graph[cur][j] && !visited[j])
					s.push(j);
			}
		}
	}
	return false;
}

bool equals() {
	ll cc = 0;
	for (int i = 0; i < b-1; i++) {
		stack<int> s;
		s.push(i);
		while(!s.empty()) {
			int cur = s.top();
			if (cur == b-1)
				cc++;
			if (cc > m)
				return false;
			s.pop();
			for (int j = 0; j < b; j++) {
				if (graph[cur][j])
					s.push(j);
			}
		}
	}
	if (cc == m)
		return true;
	return false;
}
void print_graph() {
	for (int k = 0; k < b; k++) {
				for (int kk = 0; kk < b; kk++) {
					cout << graph[k][kk];
				}
				cout << endl;
			}
}

void solve() {
	cin >> b >> m;
	int mx = b*(b-1) - b + 1;
	for (int i = 0; i < (1<<mx); i++) {
		int j = 0;
		for (int k = 0; k < b ; k++) {
			for (int z = 0; z < b; z++) {
				graph[k][z] = 0;
			}
		}
		for (int k = 0; k < b-1; k++) {
			for (int z = 0; z < b; z++) {
				if (k == z)
					continue;
				if (i & (1<<j)) {
					graph[k][z] = 1;
				}
				j++;
			}
		}
		//print_graph();
		if (cyclic()) {
			//cout << "Thought Acyclic";
			continue;
		} else {
			if (equals()) {
				cout << "POSSIBLE";
				for (int kk = 0; kk < b; kk++) {
					cout << endl;
					for (int kkk = 0; kkk<b; kkk++) {
						cout << graph[kk][kkk];
					}
				}
				return;
			}
		}
	}
	cout << "IMPOSSIBLE";
}
