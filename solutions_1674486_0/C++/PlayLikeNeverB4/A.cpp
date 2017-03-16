#include <fstream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("a.in");
ofstream fout("a.out");

#define MAXN 1010
int i, j, N, M, t, T;
int A[MAXN][MAXN];
queue<int> Q;
int v[MAXN], D[MAXN];

int bfs(int st) {
	while(!Q.empty()) Q.pop();
	Q.push(st);
	v[st] = 1;
	D[st] = 1;
	
	while(!Q.empty()) {
		int p = Q.front();
		for(int i = 1; i <= A[p][0]; i++)
			if(D[A[p][i]] > 0) return 1;
			else {
				D[A[p][i]] = 1;
				if(!v[A[p][i]]) {
					v[A[p][i]] = 1;
					Q.push(A[p][i]);
				}
			}
		Q.pop();
	}
	
	return 0;
}

int main() {
	fin >> T;
	for(t = 1; t <= T; t++) {
		fin >> N;
		
		for(i = 1; i <= N; i++) {
			fin >> M;
			A[i][0] = M;
			for(j = 1; j <= M; j++)
				fin >> A[i][j];
		}
		
		for(i = 1; i <= N; i++) {
			memset(D, 0, sizeof(D));
			memset(v, 0, sizeof(v));
			if(bfs(i)) break;
		}
		
		fout << "Case #" << t << ": ";
		if(i <= N) fout << "Yes\n";
		else fout << "No\n";
	}
	
	return 0;
}
