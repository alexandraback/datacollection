//Problem: Google Code Jam 2014 Round 1B C
//Name: The Bored Traveling Salesman
//Author: Bruce K. B. Tong
//Tag: Graph

#include <cstdio>
#include <iostream>

using namespace std;

#define SMALL
//#define LARGE

#define N_SIZE 50
int ZIP[N_SIZE];
int g[N_SIZE][N_SIZE];

void read(int &N, int &M, int ZIP[], int g[N_SIZE][N_SIZE]) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			g[i][j] = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> ZIP[i];
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		g[a-1][b-1] = 1;
		g[b-1][a-1] = 1;
	}
}

void dfs(int u, int N, int g[N_SIZE][N_SIZE], int visited[]) {
	visited[u] = 1;
	for (int i = 0; i < N; i++)
		if (i != u && g[u][i] > 0 && !visited[i]) dfs(i, N, g, visited);
}

void dfs_output(int u, int N, int ZIP[], int g[N_SIZE][N_SIZE], int visited[]) {
	visited[u] = 1;
	cout << ZIP[u];
	while (1) {
		int minZIP = 100000, v = -1;
		for (int i = 0; i < N; i++)
			if (i != u && g[u][i] > 0 && !visited[i] && ZIP[i] < minZIP) {
				minZIP = ZIP[i];
				v = i;
			}
		if (v != -1) dfs_output(v, N, ZIP, g, visited);
		else break;
	}
}


void solve(int N, int M, int ZIP[], int g[N_SIZE][N_SIZE]) {
	int ans[N_SIZE] = {0};
	for (int i = 0; i < N; i++) {
		int visited[N_SIZE] = {0};
		dfs(i, N, g, visited);
		int success = 1;
		for (int j = 0; j < N && success; j++)
			if (visited[j] == 0) success = 0;
		ans[i] = success;
	}
	int u = -1, minZIP = 100000;
	for (int i = 0; i < N; i++)
		if (ans[i])
			if (ZIP[i] < minZIP) {
				minZIP = ZIP[i];
				u = i;
			}
	int visited[N_SIZE] = {0};
	dfs_output(u, N, ZIP, g, visited);
}

int main() {
	freopen("C-sample.in", "rt", stdin);
	#ifdef SMALL
		freopen("C-small-attempt0.in", "rt", stdin);
		freopen("C-small-attempt0.out", "wt", stdout);
	#endif
	#ifdef LARGE
		freopen("C-large.in", "rt", stdin);
		freopen("C-large.out", "wt", stdout);
	#endif

	int T;			//1 <= T <= 100
	int N;			//1 <= N <= 8 (or 50)
	int M;			//0 <= M <= N*(N-1)/2
	
	cin >> T;
	for (int i = 1; i <= T; i++) {
		read(N, M, ZIP, g);
		cout << "Case #" << i << ": ";
		solve(N, M, ZIP, g);
		cout << endl;
	}
	return 0;
}