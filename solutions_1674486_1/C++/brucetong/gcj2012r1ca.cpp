//Problem: GCJ 2012 Round 1C A
//Name: Diamond Inheritance
//Author: Bruce K. B. Tong

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <list>

using namespace std;

//#define SMALL
#define LARGE

#define SIZE 1000

#define a2d(a, h, w) for(int i=0; i<(int)(h); i++) {for(int j=0; j<(int)(w); j++) cout << a[i][j]; cout << endl;}

int g[SIZE][SIZE];

void read(int &N, int g[SIZE][SIZE]) {
	int mi, parent;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> mi;
		while (mi-- > 0) {
			cin >> parent;
			g[i][parent - 1] = 1;
		}
	}
}

int dfs(int N, int g[SIZE][SIZE], int v, int visited[SIZE]) {
	visited[v] = 1;
	for (int i = 0; i < N; i++) {
		if (i != v) {
			if (g[v][i] && visited[i]) return 1;
			if (g[v][i] && dfs(N, g, i, visited)) {
				return 1;
			}
		}
	}
	return 0;
}


void compute(int N, int g[SIZE][SIZE]) {
	int visited[SIZE];
	for (int i = 0; i < N; i++) {
		memset(visited, 0, sizeof(visited));
		int result = dfs(N, g, i, visited);
		if (result) {
			cout << "Yes";
			return;
		}
	}
	cout << "No";
}

int main() {
	freopen("A-sample.in", "rt", stdin);
	#ifdef SMALL
		freopen("A-small-attempt0.in", "rt", stdin);
		freopen("A-small-attempt0.out", "wt", stdout);
	#endif
	#ifdef LARGE
		freopen("A-large.in", "rt", stdin);
		freopen("A-large.out", "wt", stdout);
	#endif

	int T;				//1 <= T <= 50
	int N;				//1 <= N <= 50 (or 1,000)

	cin >> T;

	for (int i = 1; i <= T; i++) {
		memset(g, 0, sizeof(g));
		read(N, g);
		cout << "Case #" << i << ": ";
		compute(N, g);
		cout << endl;
	}

	return 0;
}