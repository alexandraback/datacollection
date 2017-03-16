#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <iostream>
#include <cstdlib>

using namespace std;

int T, R, N, M, K;
int mem[6][6][6][999];
int v[5];

int ans[5];

int inp[9];
inline int score(int a, int b, int c) {
	int prod = 1;
	for(int i = 0 ; i < K ; i++) {
		prod *= mem[a][b][c][inp[i]];
	}
	return prod;
}

inline void calc() {
	int best = -1;
	for(v[0] = 2 ; v[0] <= M ; v[0]++) {
		for(v[1] = v[0] ; v[1] <= M ; v[1]++) {
			for(v[2] = v[1] ; v[2] <= M ; v[2]++) {
				int s = score(v[0], v[1], v[2]);
				if (s > best) {
					best = s;
					memcpy(ans, v, sizeof(ans));
				}
			}
		}
	}
	for(int i = 0 ; i < N ; i++)
		printf("%d", ans[i]);
	printf("\n");
}

int main() {
	scanf("%d", &T);
	for(int t = 1 ; t <= T ; t++) {
		scanf("%d %d %d %d", &R, &N, &M, &K);
		for(v[0] = 2 ; v[0] <= M ; v[0]++) {
			for(v[1] = v[0] ; v[1] <= M ; v[1]++) {
				for(v[2] = v[1] ; v[2] <= M ; v[2]++) {
					for(int mask = 0 ; mask < 8 ; mask++) {
						int prod = 1;
						for(int i = 0 ; i < 3 ; i++) {
							if ((mask >> i) & 1) {
								prod *= v[i];
							}
						}
						mem[v[0]][v[1]][v[2]][prod]++;
					}
				}
			}
		}
		printf("Case %d:\n", t);
		for(int u = 0 ; u < R ; u++) {
			for(int i = 0 ; i < K ; i++)
				scanf("%d", &inp[i]);
			calc();
		}
	}
}
