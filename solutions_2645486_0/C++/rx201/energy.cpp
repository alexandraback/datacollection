#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

int min(int x, int y) {
	return x< y ? x : y;
}

int max(int x, int y) {
	return x > y ? x : y;
}

int solve(int E, int R, int N, int* v) {
	int m[10][10];
	memset(m, 0 ,sizeof(m));
	for(int s=0 ;s<=E; s++) {
		m[0][min(E-s+R, E)] = v[0] * s;
	}
	
	for(int i=0; i<N; i++) {
		for(int e=0 ;e<=E; e++) {
			//propogate m[i][e] to m[i+1][?]
			for(int x=0; x<=e; x++) { //spend x
				int new_e = min(e - x + R, E);
				int new_v = m[i][e] + v[i+1] * x;
				m[i+1][new_e] = max(m[i+1][new_e], new_v);
			}
		}
	}
	
	int r =0;
	for(int e=0; e<=E; e++)
		if (m[N-1][e] > r) r = m[N-1][e];
	return r;
}

int main(int argc, char* argv[]) {
	int T;
	setbuf(stdout, NULL);
	
	//FILE* f = fopen(argv[1], "rt");
	//fscanf(f, "%d\n", &T);
	scanf("%d\n", &T);
	
	for(int t=0; t<T; t++) {
		int E, R, N;
		int v[10001];
		//fscanf(f, "%d", &N);
		scanf("%d %d %d", &E, &R, &N);
		
		for(int i=0; i<N; i++)
			scanf("%d", &v[i]);
		printf("Case #%d: %d\n", t+1, solve(E, R, N, v));

	}
	//fclose(f);
	return 0;
}
